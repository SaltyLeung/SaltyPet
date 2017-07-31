#ifndef DEVELOP_H
#define DEVELOP_H

#include <QDialog>
#include"mainwindow.h"
namespace Ui {
class develop;
}

class develop : public QDialog
{
    Q_OBJECT

public:
    explicit develop(MainWindow* w,QWidget *parent = 0);
    ~develop();

private:
    Ui::develop *ui;
    MainWindow* w;
private slots:
   void littleCat_click();
   void smallCat_click();
   void dilu_click();
   void iceCat_click();
   void ghostCat_click();
   void fireCat_click();
   void redCoat_click();
   void old_click();
   void ha_click();
};

#endif // DEVELOP_H
