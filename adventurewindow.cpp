#include "adventurewindow.h"
#include "ui_adventurewindow.h"
#include<QTime>
#include<QDebug>
#include<QAction>
#include<QSignalMapper>
AdventureWindow::AdventureWindow(QMainWindow* wptr,QWidget *parent) :
    QMainWindow(parent),w(wptr),
    ui(new Ui::AdventureWindow)
{
    for(int i=0;i<=4;++i) up[i]=0;
    setMinimumSize(900, 600);
    setMaximumSize(900, 600);

    static QTime t=QTime::currentTime();
    QTime T=QTime::currentTime();
    int i=T.msecsTo(t);
    qsrand(i);
    ui->setupUi(this);
    for(int x=0;x<=4;++x)
    {
            myCardPoint[x][0]=qrand()%4;
            vsCardPoint[x][0]=qrand()%4;
            myCardPoint[x][1]=1+qrand()%6;
            vsCardPoint[x][1]=1+qrand()%6;
    }
    myCard[0]= ui->mycard_1;
    myCard[1]= ui->mycard_2;
    myCard[2]= ui->mycard_3;
    myCard[3]= ui->mycard_4;
    myCard[4]= ui->mycard_5;
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
    QSignalMapper *signalMapper = new QSignalMapper(this);

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
    //bool clear=true;
    //for(int i=0;i<=4;++i)
//{
   // if(up[i]==1)clear=false;
    //break;
//}
    //if (clear==true) return;
    int suit=0;
    int num=1;
    for(int i=0;i<=4;++i)
    {
        if(up[i]==1)
        {
            up[i]=-1;
            //QString myCardSheet="QPushbutton{background-color: rgba(0, 0, 0, 0);}";
            //myCard[i]->setStyleSheet(myCardSheet);
            myCard[i]->setVisible(false);
            suit=myCardPoint[i][0];
            num=myCardPoint[i][1];
        }
    }
    QString myCardSheet="QLabel{border-image: url(:/image/card_"+QString::number (suit)+QString::number (num)+");}";
    ui->myCard_dis->setStyleSheet(myCardSheet);
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
