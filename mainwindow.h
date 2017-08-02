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
     int s2process;
     int s3process;
     int s4process;
     int s5process;
     int s6process;
     int s7process;
     int s8process;
     int s9process;
     int s10process;
     int s11process;
     int s12process;

public slots:
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
    void song2_check(int);
    void song3_check(int);
    void song4_check(int);
    void song5_check(int);
    void song6_check(int);
    void song7_check(int);
    void song8_check(int);
    void song9_check(int);
    void song10_check(int);
    void song11_check(int);
    void song12_check(int);
};


#endif // MAINWINDOW_H
