#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

#include "maps.h"
#include "spellcross.h"

class QListWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadMaps();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;
    QGraphicsItemGroup* gridGroup_;
    QGraphicsItemGroup* gridNumbersGroup_;


    QMenu* sceneContextMenu_;
    QAction* addEnemyAction_;

    std::shared_ptr<SpellCross> spellcross_;
    std::shared_ptr<Map> currentMap_;

    QMap<int, QGraphicsTextItem*> gridNumbers_;
    int currentActionGridNumber_;


    void createGrid();
    void createLineDownDirection(int y_position);
    void createLineUpDirection();

    void prepareMap(const QString& mapName);
    void loadMapDefinition(const QString& mapName);

private slots:
    void showContextMenu(const QPoint& position);
    void onListItemDoubleClicked(QListWidgetItem* item);

    void setGridNumberOpacity(int value);
    void setGridNumbersColor();

    void moveGridUp();
    void moveGridDown();
    void moveGridLeft();
    void moveGridRight();


    void deleteScene();

    void addEnemy();
};
#endif // MAINWINDOW_H
