#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fileop.h"
#include"adventurewindow.h"
#include<QString>
#include<QtMultimedia/QMediaPlayer>
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
    QObject::connect(ui->music_button, SIGNAL(clicked()), this, SLOT(music_clicked()));


    player = new QMediaPlayer();
       //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
     player->setMedia(QUrl("qrc:/music/ShootingTown"));
     player->setVolume(30);
     player->play();

     for(int i=0;i<=13;++i){
        pianoPlayer[i] = new QMediaPlayer();
        QString url="qrc:/piano/"+QString::number(i);
        pianoPlayer[i]->setMedia(QUrl(url));
        pianoPlayer[i]->setVolume(30);
     }
}


MainWindow::~MainWindow()
{
    delete ui;
    FileOp::save(dataPtr);
}

void MainWindow::music_clicked()
{
    static bool on=true;
    if(on==true)
    {
        ui->music_button->setStyleSheet("QPushButton{border-image: url(:/music/music_off);}");
        player->stop();
        on=false;
    }
    else
    {
        ui->music_button->setStyleSheet("QPushButton{border-image: url(:/music/music_on);}");
        player->play();
        on=true;
    }

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

void MainWindow::keyPressEvent(QKeyEvent *e)

{

    //int x = ui->pushButton->x();

    //int y = ui->pushButton->y();

    switch (e->key())

    {

    case Qt::Key_1 :
        pianoPlayer[1]->setPosition(0);
        pianoPlayer[1]->play();
        break;
    case Qt::Key_2 :
        pianoPlayer[2]->setPosition(0);
        pianoPlayer[2]->play();
        break;
    case Qt::Key_3 :
        pianoPlayer[3]->setPosition(0);
        pianoPlayer[3]->play();
        break;
    case Qt::Key_4 :
        pianoPlayer[4]->setPosition(0);
        pianoPlayer[4]->play();
        break;
    case Qt::Key_5 :
        pianoPlayer[5]->setPosition(0);
        pianoPlayer[5]->play();
        break;
    case Qt::Key_6 :
        pianoPlayer[6]->setPosition(0);
        pianoPlayer[6]->play();
        break;
    case Qt::Key_7 :
        pianoPlayer[7]->setPosition(0);
        pianoPlayer[7]->play();
        break;
    case Qt::Key_F1:
        pianoPlayer[8]->setPosition(0);
        pianoPlayer[8]->play();
        break;
    case Qt::Key_F2 :
        pianoPlayer[9]->setPosition(0);
        pianoPlayer[9]->play();
        break;
    case Qt::Key_F3 :
        pianoPlayer[0]->setPosition(0);
        pianoPlayer[0]->play();
        break;
    case Qt::Key_F4 :
        pianoPlayer[10]->setPosition(0);
        pianoPlayer[10]->play();
        break;
    case Qt::Key_F5 :
        pianoPlayer[11]->setPosition(0);
        pianoPlayer[11]->play();
        break;
    case Qt::Key_F6 :
        pianoPlayer[12]->setPosition(0);
        pianoPlayer[12]->play();
        break;
    case Qt::Key_F7 :
        pianoPlayer[13]->setPosition(0);
        pianoPlayer[13]->play();
        break;
    //case Qt::Key_A : ui->pushButton->move(x-10, y); break;

    //case Qt::Key_D : ui->pushButton->move(x+10, y); break;
default:break;
    }
    if(e->key()==Qt::Key_1)
  ｛
 if(e->key()==Qt::Key_0){

     ｝
                }

          ｝

}
