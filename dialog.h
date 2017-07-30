#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"adventurewindow.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(AdventureWindow * wptr, QWidget *parent = 0);
    ~Dialog();
    AdventureWindow * adw;
private:
    Ui::Dialog *ui;
    //int acexp;
private slots:
void quit();
void next();
};

#endif // DIALOG_H
