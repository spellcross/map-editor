#ifndef ADDENEMYDIALOG_H
#define ADDENEMYDIALOG_H

#include <QDialog>

namespace Ui {
class AddEnemyDialog;
}

class AddEnemyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEnemyDialog(QWidget *parent = nullptr);
    ~AddEnemyDialog();

private:
    Ui::AddEnemyDialog *ui;
};

#endif // ADDENEMYDIALOG_H
