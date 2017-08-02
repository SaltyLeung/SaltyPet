#ifndef NAME_H
#define NAME_H
#include"mainwindow.h"
#include <QDialog>
#include"introduce.h"
namespace Ui {
class Name;
}

class Name : public QDialog
{
    Q_OBJECT

public:
    explicit Name(MainWindow* w,Introduce* ,QWidget *parent = 0);
    ~Name();

private:
    Ui::Name *ui;
    MainWindow* w;
    Introduce* i;
    QString text;
private slots:
    void ok();
    void getText(const QString & text);
};

#endif // NAME_H
