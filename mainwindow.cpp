#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fileop.h"
#include"adventurewindow.h"
#include<QString>
//#define level getLevel()
//#define name getName()
//#define attribute getAttribute()
//#define exp getExp()
//#define coin getCoin()
//#define gender getGender()
//#define status getStatus()
//#define period getPeriod()
MainWindow::MainWindow(Data *gameData,QWidget *parent) :
    QMainWindow(parent),dataPtr(gameData),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->feed_button->setStyleSheet("QPushButton{border-image: url(:/image/feed);}"
                                 "QPushButton:hover{border-image: url(:/image/feed_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/feed_press);}");
    ui->bath_button->setStyleSheet("QPushButton{border-image: url(:/image/bath);}"
                                 "QPushButton:hover{border-image: url(:/image/bath_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/bath_press);}");
    ui->adventure_button->setStyleSheet("QPushButton{border-image: url(:/image/adventure);}"
                                 "QPushButton:hover{border-image: url(:/image/adventure_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/adventure_press);}");
    dataUpdate();
    QObject::connect(gameData, SIGNAL(dataChanged()), this, SLOT(dataUpdate()));

    QObject::connect(ui->feed_button, SIGNAL(clicked()), this, SLOT(feed_clicked()));
    QObject::connect(ui->bath_button, SIGNAL(clicked()), this, SLOT(bath_clicked()));
    QObject::connect(ui->adventure_button, SIGNAL(clicked()), this, SLOT(adventure_clicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
    FileOp::save(dataPtr);
}

void MainWindow::bath_clicked()
{

}

void MainWindow::feed_clicked()
{

}

void MainWindow::adventure_clicked()
{
   this->hide();
   AdventureWindow *adw=new AdventureWindow(this);
    (*adw).setWindowFlags(windowFlags()&~ (Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));
    (*adw).show();

}
void MainWindow::dataUpdate()
{

    QString attr;
    if(dataPtr->attribute==1)
    {
        attr="FIRE";
        ui->attr->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
    }
    else if(dataPtr->attribute==2)
    {
        attr="ICE";
        ui->attr->setStyleSheet("QLabel{color: rgb(0, 0, 255);}");
    }
    else attr="NONE";
     ui->attr->setText(attr);

     QString status;
     switch(dataPtr->status)
     {
     case 0:
         status="Nice";
         break;
     case 1:
         status="Hungry";
     break;
     case 2:
         status="Dirty";
         break;
     case 3:
         status="Hungry & Dirty";
         break;
     default:
         status="unknown";
         break;
     }
     ui->status->setText(status);


     ui->name->setText(dataPtr->name);
     ui->coin->setText(QString::number(dataPtr->coin));
     ui->exp->setText(QString::number(dataPtr->exp));

     QString gender;
     if(dataPtr->gender)ui->gender->setText("Male");
     else ui->gender->setText("Female");

     QString period;
     switch(dataPtr->period)
     {
     case 0:
         period="Egg";
         break;
     case 1:
         period="Little Cat";
     break;
     case 2:
         period="Middle Cat";
         break;
     case 3:
         period="Big Cat";
         break;
     default:
         period="Crazy Cat";
         break;
     }
     ui->period->setText(period);
     ui->level->setText(QString::number(dataPtr->level));
}
