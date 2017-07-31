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
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlayer* pianoPlayer[14];
     int s1process;
private slots:
    void bath_clicked();
    void feed_clicked();
    void adventure_clicked();
    void dataUpdate();
    void music_clicked();
    void finger_clicked();
    void help_clicked();
    void skill_clicked();
    void develop_clicked();
    void song1_check(int);

};


#endif // MAINWINDOW_H
