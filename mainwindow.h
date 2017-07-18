#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"data.h"
#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Data* dataPtr;

private:
    Ui::MainWindow *ui;
private slots:
    void bath_clicked();
    void feed_clicked();
    void adventure_clicked();
};
#endif // MAINWINDOW_H