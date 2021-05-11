#include "addenemydialog.h"
#include "ui_addenemydialog.h"

AddEnemyDialog::AddEnemyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEnemyDialog)
{
    ui->setupUi(this);
}

AddEnemyDialog::~AddEnemyDialog()
{
    delete ui;
}
