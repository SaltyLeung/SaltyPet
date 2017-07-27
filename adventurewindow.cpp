#include "adventurewindow.h"
#include "ui_adventurewindow.h"
#include<QTime>
#include<QDebug>
#include<QAction>
#include<QSignalMapper>
#include<QPropertyAnimation>
#include<QGraphicsOpacityEffect>
#include"random.h"
AdventureWindow::AdventureWindow(MainWindow* wptr,QWidget *parent) :
    QMainWindow(parent),w(wptr),
    ui(new Ui::AdventureWindow)
{

    ui->setupUi(this);
    ui->myname->setText(w->dataPtr->name);
    myHP=5;
    vsHP=5;
    for(int i=0;i<=4;++i) up[i]=0;
    setMinimumSize(900, 600);
    setMaximumSize(900, 600);

    QTime T=QTime::currentTime();
    int i=T.msecsTo(t);
    qsrand(i);
    for(int x=0;x<=4;++x)
    {
            myCardPoint[x][0]=qrand()%4;
            //vsCardPoint[x][0]=qrand()%4;
            myCardPoint[x][1]=1+qrand()%6;
            //vsCardPoint[x][1]=1+qrand()%6;
    }
    myCard[0]= ui->mycard_1;
    myCard[1]= ui->mycard_2;
    myCard[2]= ui->mycard_3;
    myCard[3]= ui->mycard_4;
    myCard[4]= ui->mycard_5;
    vsCard[0]= ui->vscard_1;
    vsCard[1]= ui->vscard_2;
    vsCard[2]= ui->vscard_3;
    vsCard[3]= ui->vscard_4;
    vsCard[4]= ui->vscard_5;
    card_button[0]= ui->card_button_1;
    card_button[1]= ui->card_button_2;
    card_button[2]= ui->card_button_3;
    card_button[3]= ui->card_button_4;
    card_button[4]= ui->card_button_5;
    for(int i=0;i<=4;++i)
    {
        QString myCardSheet="QPushButton{border-image: url(:/image/card_"+QString::number (myCardPoint[i][0])+QString::number (myCardPoint[i][1])+");}";
        myCard[i]->setStyleSheet(myCardSheet);
    }

    //QMenu *pMenu = new QMenu(this);
    //pMenu->addAction(QString::fromLocal8Bit("discard"));
    //pMenu->addAction(QString::fromLocal8Bit("v"));
    //pMenu->addSeparator();
    //ui->card_button_1->setMenu(pMenu);
    //m_actionOne = new QAction(ui->card_button_1);
    //m_actionTwo = new QAction(ui->card_button_1);
    //m_actionThree = new QAction(ui->card_button_1);

   // m_actionOne->setText("ActionOne");
    //m_actionTwo->setText("ActionTwo");
    //m_actionThree->setText("ActionThree");

    //ui->card_button_1->addAction(m_actionOne);
    //ui->card_button_1->addAction(m_actionTwo);
    //ui->card_button_1->addAction(m_actionThree);
    //connect(m_actionOne, SIGNAL(triggered()), this, SLOT(actionOneSlot()));
   // connect(m_actionTwo, SIGNAL(triggered()), this, SLOT(actionTwoSlot()));
    //connect(m_actionThree, SIGNAL(triggered()), this, SLOT(actionThreeSlot()));

    //ui->card_button_1->addAction(new QAction(tr("discard"),this));      //下拉菜单
    signalMapper = new QSignalMapper(this);

   QObject:: connect(ui->card_button_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(ui->card_button_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(ui->card_button_3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(ui->card_button_4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    QObject::connect(ui->card_button_5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui->card_button_1, 0);
    signalMapper->setMapping(ui->card_button_2, 1);
    signalMapper->setMapping(ui->card_button_3, 2);
    signalMapper->setMapping(ui->card_button_4, 3);
    signalMapper->setMapping(ui->card_button_5, 4);
    QObject::connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(chooseCard(int)));
    QObject::connect(ui->discard, SIGNAL(clicked()), this, SLOT(discard()));
    QObject::connect(ui->return_button, SIGNAL(clicked()), this, SLOT(quit()));
    //QObject::connect(ui->card_button_1, SIGNAL(clicked()), this, SLOT(chooseCard(0)));
    //QObject::connect(ui->card_button_2, SIGNAL(clicked()), this, SLOT(chooseCard(1)));
    //QObject::connect(ui->card_button_3, SIGNAL(clicked()), this, SLOT(chooseCard(2)));
    //QObject::connect(ui->card_button_4, SIGNAL(clicked()), this, SLOT(chooseCard(3)));
    //QObject::connect(ui->card_button_5, SIGNAL(clicked()), this, SLOT(chooseCard(4)));

}

AdventureWindow::~AdventureWindow()
{
    w->show();
    delete ui;
    delete signalMapper;
    delete this;

}
void AdventureWindow::quit()
{
    w->show();
    this->close();
}
void AdventureWindow::chooseCard(int x)
{
    qDebug()<<x;
    if(up[x]==0)
    {
        myCard[x]->move(myCard[x]->pos().x(),myCard[x]->pos().y()-20);
        up[x]=1;
        for(int i=0;i<=4;++i)
            if((i!=x)&&(up[i]==1))
            {
                up[i]=0;
                myCard[i]->move(myCard[i]->pos().x(),myCard[i]->pos().y()+20);
            }

    }
    else if(up[x]==1)
    {
        myCard[x]->move(myCard[x]->pos().x(),myCard[x]->pos().y()+20);
        up[x]=0;
    }
}

void AdventureWindow::discard()
{
    for(int i=0;i<=4;++i)
    {
        if(up[i]==1)break;
        if(i==4)return;
    }
   static int vsRemain=5;
    //bool clear=true;
    //for(int i=0;i<=4;++i)
//{
   // if(up[i]==1)clear=false;
    //break;
//}
    //if (clear==true) return;
    int mySuit=0;
    int myNum=1;
    int vsSuit=qrand()%4;;
    int vsNum=1+qrand()%6;
    for(int i=0;i<=4;++i)
    {
        if(up[i]==1)
        {
            up[i]=-1;
            //QString myCardSheet="QPushbutton{background-color: rgba(0, 0, 0, 0);}";
            //myCard[i]->setStyleSheet(myCardSheet);
            myCard[i]->setVisible(false);
            card_button[i]->setEnabled(false);
            mySuit=myCardPoint[i][0];
            myNum=myCardPoint[i][1];
        }
    }
    vsCard[vsRemain-1]->setVisible((false));
    vsRemain-=1;
    QString vsCardSheet="QLabel{border-image: url(:/image/card_bg);}";
    ui->myCard_dis->setStyleSheet(vsCardSheet);
    ui->enemyCard_dis->setStyleSheet(vsCardSheet);
    QGraphicsOpacityEffect *effect1=new QGraphicsOpacityEffect();
    QGraphicsOpacityEffect *effect2=new QGraphicsOpacityEffect();
    for(int i=0;i<=5;++i)
    {
     effect1->setOpacity(1.0-0.2*i);
     effect2->setOpacity(1.0-0.2*i);
      ui->myCard_dis->setGraphicsEffect(effect1);
      ui->enemyCard_dis->setGraphicsEffect(effect2);
      ui->discard->setEnabled(false);
    sleep(200);
    }
    QString myCardSheet2="QLabel{border-image: url(:/image/card_"+QString::number (mySuit)+QString::number (myNum)+");}";
    ui->myCard_dis->setStyleSheet(myCardSheet2);
    QString vsCardSheet2="QLabel{border-image: url(:/image/card_"+QString::number (vsSuit)+QString::number (vsNum)+");}";
    ui->enemyCard_dis->setStyleSheet(vsCardSheet2);

    for(int i=0;i<=5;++i)
    {
        effect1->setOpacity(0.0+0.2*i);
        effect2->setOpacity(0.0+0.2*i);
         ui->myCard_dis->setGraphicsEffect(effect1);
         ui->enemyCard_dis->setGraphicsEffect(effect2);
    sleep(200);
    }
    ui->discard->setEnabled(true);
    if(vsRemain<=0){
        ui->discard->setEnabled(false);
        vsRemain=5;
    }
    delete effect1;
    delete effect2;
    if(myNum>vsNum) vsHPdecrease();
    else if(myNum<vsNum)myHPdecrease();
    else
    {
         if(mySuit==vsSuit)
         {
             vsHPdecrease();
             myHPdecrease();
         }
        else if(mySuit>vsSuit)vsHPdecrease();
        else myHPdecrease();
    }

}


void AdventureWindow::actionOneSlot()
{
    qDebug() << "actionOne";
}

void AdventureWindow::actionTwoSlot()
{
    qDebug() << "actionTwo";
}

void AdventureWindow::actionThreeSlot()
{
    qDebug() << "actionThree";
}

void AdventureWindow::myHPdecrease()
{
    QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect();
    switch(myHP)
    {
case 5:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_5->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 4:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_4->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 3:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_3->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 2:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_2->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 1:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_1->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    default:break;
    }
    delete effect;

    myHP-=1;
}

void AdventureWindow::vsHPdecrease()
{
    QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect();
    switch(vsHP)
    {
case 5:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_10->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 4:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_9->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 3:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_8->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 2:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_7->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    case 1:
        for(int i=0;i<=5;++i)
        {
            effect->setOpacity(1.0-0.2*i);
             ui->hp_6->setGraphicsEffect(effect);
        sleep(50);
        }
        break;
    default:break;
    }
    delete effect;

    vsHP-=1;
}


