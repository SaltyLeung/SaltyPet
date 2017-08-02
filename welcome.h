#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include"mainwindow.h"
namespace Ui {
class Welcome;
}

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Welcome(MainWindow* w, QWidget *parent = 0);
    ~Welcome();

private:
    Ui::Welcome *ui;
    MainWindow* w;

private slots:
    void load_clicked();
    void start_clicked();
};

#endif // WELCOME_H
