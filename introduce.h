#ifndef INTRODUCE_H
#define INTRODUCE_H

#include <QMainWindow>
#include"mainwindow.h"
namespace Ui {
class Introduce;
}

class Introduce : public QMainWindow
{
    Q_OBJECT

public:
    explicit Introduce(MainWindow* w, QWidget *parent = 0);
    ~Introduce();

private:
    Ui::Introduce *ui;
    MainWindow* w;
private slots:
    void next_clicked();
};

#endif // INTRODUCE_H
