#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"data.h"
//#include"adventurewindow.h"
#include <QMainWindow>
#include<QApplication>
#include<QtMultimedia/QMediaPlayer>
#include <QKeyEvent>
#include"sleep.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Data*,QWidget *parent = 0);
    ~MainWindow();
    Data* dataPtr;

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlayer* pianoPlayer[14];
    void keyPressEvent(QKeyEvent *);
private slots:
    void bath_clicked();
    void feed_clicked();
    void adventure_clicked();
    void dataUpdate();
    void music_clicked();

};


#endif // MAINWINDOW_H
