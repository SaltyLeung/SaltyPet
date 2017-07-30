#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include"adventurewindow.h"
namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2( AdventureWindow* ,QWidget *parent = 0);
    ~Dialog2();

private:
    Ui::Dialog2 *ui;
     AdventureWindow* adw;
     //int acexp;
private slots:
     void quit();
};

#endif // DIALOG2_H
