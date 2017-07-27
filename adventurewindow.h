#ifndef ADVENTUREWINDOW_H
#define ADVENTUREWINDOW_H

#include <QMainWindow>
#include"mainwindow.h"
#include"sleep.h"
#include<QPushButton>
#include<QSignalMapper>
namespace Ui {
class AdventureWindow;
}

class AdventureWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdventureWindow(MainWindow *, QWidget *parent = 0);
    ~AdventureWindow();

private:
    Ui::AdventureWindow *ui;
    MainWindow *w;
    QPushButton* myCard[5];
    QPushButton* card_button[5];
    QPushButton* vsCard[5];
    int myCardPoint[5][2];//[x][0]为花色：0为方块 1为梅花 2为红桃 3为黑桃；[x][1]为点数 1-13
    //int vsCardPoint[5][2];//[x][0]为花色：0为方块 1为梅花 2为红桃 3为黑桃；[x][1]为点数 1-13
    int up[5];
    QSignalMapper *signalMapper;
    int myHP;
    int vsHP;
   void myHPdecrease();
   void vsHPdecrease();
    //QAction *m_actionOne;
    //QAction *m_actionTwo;
    //QAction *m_actionThree;
private slots:
    void quit();
    void chooseCard(int);
    void discard();
    void actionOneSlot();
    void actionTwoSlot();
    void actionThreeSlot();

};

#endif // ADVENTUREWINDOW_H
