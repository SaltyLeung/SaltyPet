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
    explicit AdventureWindow(MainWindow *,int,int, QWidget *parent = 0);
    ~AdventureWindow();
    MainWindow *w;
    int acExp;
    int thisExp;
    int stage;
private:
    Ui::AdventureWindow *ui;
    QPushButton* myCard[5];
    QPushButton* card_button[5];
    QPushButton* vsCard[5];
    int myCardPoint[5][2];//[x][0]为花色：0为方块 1为梅花 2为红桃 3为黑桃；[x][1]为点数 1-13
    int vsCardPoint[5][2];//[x][0]为花色：0为方块 1为梅花 2为红桃 3为黑桃；[x][1]为点数 1-13
    bool validVS[5];
    int up[5];
    QSignalMapper *signalMapper;
    int myHP;
    int vsHP;
    bool dragonOn;
   void myHPdecrease();
   void vsHPdecrease();
    //QAction *m_actionOne;
    //QAction *m_actionTwo;
    //QAction *m_actionThree;
public slots:
    void see();
    void dragon();
    void quit();
    void chooseCard(int);
    void discard();
    void actionOneSlot();
    void actionTwoSlot();
    void actionThreeSlot();

};

#endif // ADVENTUREWINDOW_H
