#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsPixmapItem>

#include <QDebug>

#include <QtMath>
#include <QDirIterator>

#include <QColorDialog>
#include <QScrollBar>

#include <QThread>

#include "unit.h"


#include "addenemydialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , spellcross_(nullptr)
    , currentMap_(nullptr)
    , currentActionGridNumber_(-1)
{
    ui->setupUi(this);


    sceneContextMenu_ = new QMenu(this);
    addEnemyAction_ = new QAction(tr("Add enemy"));
    sceneContextMenu_->addAction(addEnemyAction_);


    scene_ = new QGraphicsScene(this);
    gridGroup_ = new QGraphicsItemGroup();
    gridNumbersGroup_ = new QGraphicsItemGroup();

    //createGrid();
    ui->graphicsView->setScene(scene_);
    ui->graphicsView->show();


    ui->graphicsView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->graphicsView, &QGraphicsView::customContextMenuRequested, this, &MainWindow::showContextMenu);





    connect(ui->gridUpPushButton, &QPushButton::clicked, this, &MainWindow::moveGridUp);
    connect(ui->gridDownPushButton, &QPushButton::clicked, this, &MainWindow::moveGridDown);
    connect(ui->gridLeftPushButton, &QPushButton::clicked, this, &MainWindow::moveGridLeft);
    connect(ui->gridRightPushButton, &QPushButton::clicked, this, &MainWindow::moveGridRight);
    connect(ui->deletePushButton, &QPushButton::clicked, this, &MainWindow::deleteScene);


    connect(ui->numberOpacitySlider, &QSlider::valueChanged, this, &MainWindow::setGridNumberOpacity);

    connect(ui->changeGridNumbersColorPushButton, &QPushButton::clicked, this, &MainWindow::setGridNumbersColor);

    spellcross_ = std::make_shared<SpellCross>();
    spellcross_->init();

    loadMaps();

    connect(ui->listWidget, &QListWidget::currentItemChanged, this, &MainWindow::onListItemDoubleClicked);
    connect(addEnemyAction_, &QAction::triggered, this, &MainWindow::addEnemy);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadMaps()
{
    auto maps = spellcross_->getMapList();
    for (auto map : maps)
    {
        ui->listWidget->addItem(map->name_);
    }
}

void MainWindow::createGrid()
{
    gridNumbers_.clear();
    //scene_->destroyItemGroup(gridGroup_);
    gridGroup_ = new QGraphicsItemGroup();
    gridNumbersGroup_ = new QGraphicsItemGroup();

    int TILE_HEIGHT = 48;
    int TILE_WIDTH = 80;
    int FIRT_TILE_FROM_TOP = 19;

    int WIDTH = scene_->width();
    int HEIGHT = scene_->height();


    QLine topBorderLine(0,0, WIDTH, 0);
    QLine bottomBorderLine(0, HEIGHT, WIDTH, HEIGHT);
    QLine rightBorderLine(WIDTH, 0, HEIGHT, WIDTH);



    int y = FIRT_TILE_FROM_TOP;

//    auto line = QLineF(0,0, 4000, 0);
//    line.setAngle(-31);
//    line.translate(0, y);

//    QPointF intersectPoint;
//    QLineF::IntersectType intersectType = line.intersect(bottomBorderLine, &intersectPoint);

//    if (intersectType != QLineF::NoIntersection)
//    {
//        auto gridLine = QLine(line.x1(), line.y1(), intersectPoint.x(), intersectPoint.y());
//        gridGroup_->addToGroup(scene_->addLine(gridLine, QPen((QColor(255,0,0)),1)));
//    }



////    gridGroup_->addToGroup(scene_->addLine(line, QPen((QColor(255,0,0)),1)));

//    //
//    // kresleni car z leveho okraje
//    //
//    y = 47;
//    while (y < HEIGHT)
//    {

//        auto l = line.translated(0, y);



//        // cara dolu
//        QPointF intersectPoint;
//        QLineF::IntersectType intersectType = l.intersect(bottomBorderLine, &intersectPoint);

//        if (intersectType != QLineF::NoIntersection)
//        {
//            auto gridLine = QLine(l.x1(), l.y1(), intersectPoint.x(), intersectPoint.y());
//            gridGroup_->addToGroup(scene_->addLine(gridLine, QPen((QColor(255,0,0)),1)));
//        }


//        // cara nahoru
//        l.setAngle(31);
//        intersectType = l.intersect(topBorderLine, &intersectPoint);

//        if (intersectType != QLineF::NoIntersection)
//        {
//            auto gridLine = QLine(l.x1(), l.y1(), intersectPoint.x(), intersectPoint.y());
//            gridGroup_->addToGroup(scene_->addLine(gridLine, QPen((QColor(255,0,0)),1)));
//        }

//        y += TILE_HEIGHT;


//    }


////    //
////    // kresleni car z horniho
////    //
////    int x = 50;
////    while (x < WIDTH)
////    {
////        auto l = line.translated(x, -FIRT_TILE_FROM_TOP);

////        //gridGroup_->addToGroup(scene_->addLine(line, QPen((QColor(0,0,255)),1)));

////        QPointF intersectPointBottom;
////        QLineF::IntersectType intersectTypeBottom = l.intersect(bottomBorderLine, &intersectPointBottom);

////        QPointF intersectPointRight;
////        QLineF::IntersectType intersectTypeRight = l.intersect(rightBorderLine, &intersectPointRight);


////        // protneme se vzdy tak co nastane driv
////        if (intersectPointBottom.y() < intersectPointRight.y())
////        {
////            auto gridLine = QLine(l.x1(), l.y1(), intersectPointRight.x(), intersectPointRight.y());
////            gridGroup_->addToGroup(scene_->addLine(gridLine, QPen((QColor(255,0,0)),1)));
////        }
////        else
////        {

////            auto gridLine = QLine(l.x1(), l.y1(), intersectPointBottom.x(), intersectPointBottom.y());
////            gridGroup_->addToGroup(scene_->addLine(gridLine, QPen((QColor(255,0,0)),1)));
////        }


////        //if (intersectPointBottom = QLineF::NoIntersection)



//////        if (intersectType != QLineF::NoIntersection)
//////        {
//////            auto gridLine = QLine(l.x1(), l.y1(), intersectPoint.x(), intersectPoint.y());
//////            gridGroup_->addToGroup(scene_->addLine(gridLine, QPen((QColor(255,0,0)),1)));
//////        }

////        x += TILE_WIDTH;
////    }






//    scene_->addItem(gridGroup_);



    int TILE_WIDTH_HALF = TILE_WIDTH / 2;
    int TILE_HEIGHT_HALF = TILE_HEIGHT / 2;

    QFont f;
    f.setPixelSize(20);


    int progress = 0;
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(currentMap_->height_ - 1);

    int index = 0;
    //int yy = 120;
    int yy = currentMap_->map_begin_y_offset_;
    for (int row = 0; row < currentMap_->height_; ++row) //vyska
    //for (int row = 0; row < 10; ++row) //vyska
    {
        int x = currentMap_->map_begin_x_offset_;

        if (row % 2 == 1)
        {
            x -= TILE_WIDTH_HALF;
        }

        for (int column = 0; column < currentMap_->width_; column++) // sirka
        //for (int column = 0; column < 10; column++) // sirka
        {

            QGraphicsTextItem* item = scene_->addText(QString("%1").arg(index, 4, 10, QChar('0')), f);
            item->setDefaultTextColor(QColor(QColorConstants::Yellow));
            item->setPos(x, yy);
            gridNumbersGroup_->addToGroup(item);
            gridNumbers_.insert(index, item);

            x += TILE_WIDTH;
            index++;
        }

        yy += TILE_HEIGHT_HALF;

        ui->progressBar->setValue(progress);
        progress++;
    }

    gridNumbersGroup_->setOpacity(0.5);
    scene_->addItem(gridNumbersGroup_);

}

void MainWindow::createLineDownDirection(int y_position)
{

}

void MainWindow::createLineUpDirection()
{

}

void MainWindow::prepareMap(const QString &mapName)
{
    scene_->clear();
    scene_->deleteLater();

    scene_ = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene_);
    ui->graphicsView->show();




    QImage image("D:\\private\\SPELLCROSS mapy\\" + mapName + ".jpg");
    QGraphicsPixmapItem* map = new QGraphicsPixmapItem(QPixmap::fromImage(image));

    currentMap_ = spellcross_->getMap(mapName);


    scene_->addItem(map);

    createGrid();
    loadMapDefinition(mapName);
}

void MainWindow::loadMapDefinition(const QString &mapName)
{
    QStringList scenarioTypes;
    QStringList scenarios;
    scenarioTypes << "" << "A" << "B" << "C" << "D";

    for (auto type : scenarioTypes)
    {
        QString filePath = "c:\\Users\\kucera\\Downloads\\spell_extractfs\\data\\COMMON\\" + mapName + type + ".DEF";
        if (QFile::exists(filePath))
        {
            scenarios << mapName + type;
        }
    }

    qDebug() << scenarios;

    if (scenarios.size() > 0)
    {
        // id, pozice
        QMultiMap<int, int> monsters;

        QFile file("c:\\Users\\kucera\\Downloads\\spell_extractfs\\data\\COMMON\\" + scenarios.at(0) + ".DEF");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        ui->textBrowser->clear();
        QTextStream in(&file);
        QString line;
        do {
            line = in.readLine();
            ui->textBrowser->append(line);


            if (line.contains("AddUnit"))
            {
                QStringList items = line.split(",");
                if (items.size() > 2)
                {
                    qDebug() << "enemy pos" << items.at(2);
                    QString pos = items.at(2);
                    auto number = gridNumbers_.value(pos.toInt());
                    if (number)
                    {
                        number->setDefaultTextColor(QColor(Qt::red));


                        auto enemyId = items.at(1).toInt();
                        auto enemy = spellcross_->getEnemy(enemyId);
                        QString enemyName = enemy ? enemy->name_ : "???";
                        number->setToolTip(enemyName);

                        monsters.insert(enemyId, pos.toInt());
                    }
                }
            }

        } while (!line.isNull());

        ui->monstersCountTextBrowser->clear();
        for (auto id : monsters.uniqueKeys())
        {
            QString line("%1: %2");
            auto enemy = spellcross_->getEnemy(id);
            ui->monstersCountTextBrowser->append(line.arg(enemy->name_).arg(monsters.values(id).count()));

        }

    }
}

void MainWindow::showContextMenu(const QPoint &position)
{
    qDebug() << "showContextMenu" << ui->graphicsView->mapToScene(position);

    ui->coordinatesLabel->setText(QString("x: %1 y: %2").arg(position.x()).arg(position.y()));

    int TILE_HEIGHT = 48;
    int TILE_WIDTH = 80;

    auto p = ui->graphicsView->mapToScene(position);

    //local ty = my - mx/2 - tile_height
    //local tx = mx + ty

    int ty = p.y() - p.x() / 2 - TILE_HEIGHT;
    int tx = p.x() + ty;

    qDebug() << tx << ty;




//    local y = math.ceil(-ty/tile_width)
//    local x = math.ceil(tx/tile_width) + 1

    int ly = qCeil(-ty / TILE_WIDTH);
    int lx = qCeil(tx / TILE_WIDTH) + 1;

    qDebug() << lx << ly;
    qDebug() << ly * 90 + lx;


//    QFont f;
//    f.setPixelSize(20);
//    auto item = scene_->addText("XXX", f);
//    item->setDefaultTextColor(QColor(QColorConstants::Cyan));

//    item->setPos(ui->graphicsView->mapToScene(position));

    auto item = scene_->itemAt(ui->graphicsView->mapToScene(position), QTransform());
    if (item)
    {
        QGraphicsTextItem* textItem = dynamic_cast<QGraphicsTextItem*>(item);
        if (textItem)
        {
            ui->tileLabel->setText(QString("Tile: %1").arg(textItem->toPlainText()));
            QString text = textItem->toPlainText();
            int number = text.toInt();
            currentActionGridNumber_ = textItem->toPlainText().toInt();
            sceneContextMenu_->exec(ui->graphicsView->mapToGlobal(position));
        }

    }
}

void MainWindow::onListItemDoubleClicked(QListWidgetItem *item)
{
    prepareMap(item->text());

}

void MainWindow::setGridNumberOpacity(int value)
{
    double opacity = value / 100.0;
    gridNumbersGroup_->setOpacity(opacity);
}

void MainWindow::setGridNumbersColor()
{
//    QColor color = QColorDialog::getColor();
//    if (color.isValid())
//    {

//        for (int i = 0; i < gridNumbersGroup_->da)
//        {
//            QGraphicsTextItem* textItem = dynamic_cast<QGraphicsTextItem*>(item);
//            if (textItem)
//            {
//                textItem->setDefaultTextColor(color);
//            }
//        }
//    }

}

void MainWindow::moveGridUp()
{
//    gridNumbersGroup_->moveBy(0, -1);
//    qDebug() << gridNumbersGroup_->boundingRect().topLeft();


    qreal scaleFactor = 0.8;
    qreal factor = ui->graphicsView->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    ui->graphicsView->scale(scaleFactor, scaleFactor);
}

void MainWindow::moveGridDown()
{
//    //gridGroup_->moveBy(0, 1);
//    gridNumbersGroup_->moveBy(0, 1);
//    qDebug() << gridNumbersGroup_->pos();

    qreal scaleFactor = 1.2;
    qreal factor = ui->graphicsView->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    ui->graphicsView->scale(scaleFactor, scaleFactor);
}

void MainWindow::moveGridLeft()
{
    gridNumbersGroup_->moveBy(-1, 0);
    qDebug() << gridNumbersGroup_->boundingRect().topLeft();
}

void MainWindow::moveGridRight()
{
    gridNumbersGroup_->moveBy(1, 0);
    qDebug() << gridNumbersGroup_->boundingRect().topLeft();

}

void MainWindow::deleteScene()
{
    scene_->clear();
}

void MainWindow::addEnemy()
{
    qDebug() << "ADD ENEMY ON TILE" << currentActionGridNumber_;
}


