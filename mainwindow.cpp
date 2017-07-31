#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fileop.h"
#include"adventurewindow.h"
#include<QString>
#include<QtMultimedia/QMediaPlayer>
#include<QSignalMapper>
#include<QGraphicsOpacityEffect>
#include<QPropertyAnimation>
#include"skill.h"
#include"develop.h"
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
    ui->see_learn->setVisible(false);
    ui->note_1->setVisible(false);
    ui->note_2->setVisible(false);
    ui->note_3->setVisible(false);
    ui->note_4->setVisible(false);
    ui->note_5->setVisible(false);
    ui->note_6->setVisible(false);
    ui->note_7->setVisible(false);
    ui->note_8->setVisible(false);
    ui->note_9->setVisible(false);
    ui->note_10->setVisible(false);
    ui->note_11->setVisible(false);
    ui->note_12->setVisible(false);
    ui->note_13->setVisible(false);
    ui->note_14->setVisible(false);

    ui->feed_button->setStyleSheet("QPushButton{border-image: url(:/image/feed);}"
                                 "QPushButton:hover{border-image: url(:/image/feed_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/feed_press);}");
    ui->bath_button->setStyleSheet("QPushButton{border-image: url(:/image/bath);}"
                                 "QPushButton:hover{border-image: url(:/image/bath_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/bath_press);}");
    ui->adventure_button->setStyleSheet("QPushButton{border-image: url(:/image/adventure);}"
                                 "QPushButton:hover{border-image: url(:/image/adventure_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/adventure_press);}");
    ui->help->setStyleSheet("QPushButton{border-image: url(:/image/help);}"
                                 "QPushButton:hover{border-image: url(:/image/help_hover);}");
    ui->develop->setStyleSheet("QPushButton{border-image: url(:/image/develop);}"
                                 "QPushButton:hover{border-image: url(:/image/develop_hover);}");
    ui->finger->setStyleSheet("QPushButton{border-image: url(:/image/finger);}"
                                 "QPushButton:hover{border-image: url(:/image/finger_hover);}");
    ui->skill->setStyleSheet("QPushButton{border-image: url(:/image/skill);}"
                                 "QPushButton:hover{border-image: url(:/image/skill_hover);}");
    dataUpdate();
    QObject::connect(gameData, SIGNAL(dataChanged()), this, SLOT(dataUpdate()));

    QObject::connect(ui->feed_button, SIGNAL(clicked()), this, SLOT(feed_clicked()));
    QObject::connect(ui->bath_button, SIGNAL(clicked()), this, SLOT(bath_clicked()));
    QObject::connect(ui->adventure_button, SIGNAL(clicked()), this, SLOT(adventure_clicked()));
    QObject::connect(ui->music_button, SIGNAL(clicked()), this, SLOT(music_clicked()));
    QObject::connect(ui->finger, SIGNAL(clicked()), this, SLOT(finger_clicked()));
    QObject::connect(ui->help, SIGNAL(clicked()), this, SLOT(help_clicked()));
    QObject::connect(ui->skill, SIGNAL(clicked()), this, SLOT(skill_clicked()));
    QObject::connect(ui->develop, SIGNAL(clicked()), this, SLOT(develop_clicked()));


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
    s1process=0;
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
   AdventureWindow *adw=new AdventureWindow(this,0,1);
    (*adw).setWindowFlags(windowFlags()&~ (Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));
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
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         period="Egg";
         break;
     case 1:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         period="Ball Cat";
     break;
     case 2:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         period="Small Cat";
         break;
     case 3:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         period="Fake Tailmon";
         break;
     case 4:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
         period="Burst Fire";
     case 5:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 255);}");
         period="Ghost";
     case 6:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 255);}");
         period="Enternal Blizzard";
     case 7:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
         period="Red Coat";
     case 8:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 255);}");
         period="Elder";
     case 9:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 255);}");
         period="Hallace";
         break;
     default:
         period="Crazy Cat";
         break;
     }
     ui->period->setText(period);
     dataPtr->levelCheck();
     ui->level->setText(QString::number(dataPtr->level));
}

void MainWindow::finger_clicked()
{

}

void MainWindow::help_clicked()
{

}

void MainWindow::skill_clicked()
{
     Skill *skl=new Skill(this);
     (*skl).setWindowFlags(windowFlags()&~ (Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint));
     (*skl).show();
}

void MainWindow::develop_clicked()
{
    develop*dvl=new develop(this);
    (*dvl).setWindowFlags(windowFlags()&~ (Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint));
    (*dvl).show();
}

void MainWindow::keyPressEvent(QKeyEvent *e)

{
    static int count=0;
    static QGraphicsOpacityEffect *effect[14];
    for(int i=0;i<=13;++i){
    effect[i]=new QGraphicsOpacityEffect();
    effect[i]->setOpacity(0);
    }

    ui->note_1->setGraphicsEffect(effect[0]);
    ui->note_2->setGraphicsEffect(effect[1]);
    ui->note_3->setGraphicsEffect(effect[2]);
    ui->note_4->setGraphicsEffect(effect[3]);
    ui->note_5->setGraphicsEffect(effect[4]);
    ui->note_6->setGraphicsEffect(effect[5]);
    ui->note_7->setGraphicsEffect(effect[6]);
    ui->note_8->setGraphicsEffect(effect[7]);
    ui->note_9->setGraphicsEffect(effect[8]);
    ui->note_10->setGraphicsEffect(effect[9]);
    ui->note_11->setGraphicsEffect(effect[10]);
    ui->note_12->setGraphicsEffect(effect[11]);
    ui->note_13->setGraphicsEffect(effect[12]);
    ui->note_14->setGraphicsEffect(effect[13]);

    static QPropertyAnimation* m_animation[13];
    for(int i=0;i<=13;++i){
        m_animation[i]= new QPropertyAnimation(effect[i],"opacity",effect[i]);
        m_animation[i]->setStartValue(0);
        m_animation[i]->setKeyValueAt(0.45, 1);
        m_animation[i]->setKeyValueAt(0.55, 1);
        m_animation[i]->setEndValue(0);
        m_animation[i]->setDuration(600);
    }
    //int x = ui->pushButton->x();

    //int y = ui->pushButton->y();

    switch (e->key())

    {
    case Qt::Key_1 :
        pianoPlayer[1]->setPosition(0);
        pianoPlayer[1]->play();
        m_animation[0]->start();
        ui->note_1->setVisible(true);
        count+=1;
        break;
    case Qt::Key_2 :
        pianoPlayer[2]->setPosition(0);
        pianoPlayer[2]->play();
        m_animation[1]->start();
        count+=1;
        ui->note_2->setVisible(true);
        break;
    case Qt::Key_3 :
        pianoPlayer[3]->setPosition(0);
        pianoPlayer[3]->play();
        m_animation[2]->start();
        ui->note_3->setVisible(true);
        count+=1;
        break;
    case Qt::Key_4 :
        pianoPlayer[4]->setPosition(0);
        pianoPlayer[4]->play();
        m_animation[3]->start();
        ui->note_4->setVisible(true);
        count+=1;
        break;
    case Qt::Key_5 :
        pianoPlayer[5]->setPosition(0);
        pianoPlayer[5]->play();
        m_animation[4]->start();
        ui->note_5->setVisible(true);
        count+=1;
        break;
    case Qt::Key_6 :
        pianoPlayer[6]->setPosition(0);
        pianoPlayer[6]->play();
        m_animation[5]->start();
        ui->note_6->setVisible(true);
        count+=1;
        break;
    case Qt::Key_7 :
        pianoPlayer[7]->setPosition(0);
        pianoPlayer[7]->play();
        m_animation[6]->start();
        ui->note_7->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F1:
        pianoPlayer[8]->setPosition(0);
        pianoPlayer[8]->play();
        m_animation[7]->start();
        ui->note_8->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F2 :
        pianoPlayer[9]->setPosition(0);
        pianoPlayer[9]->play();
        m_animation[8]->start();
        ui->note_9->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F3 :
        pianoPlayer[0]->setPosition(0);
        pianoPlayer[0]->play();
        m_animation[9]->start();
        ui->note_10->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F4 :
        pianoPlayer[10]->setPosition(0);
        pianoPlayer[10]->play();
        m_animation[10]->start();
        ui->note_11->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F5 :
        pianoPlayer[11]->setPosition(0);
        pianoPlayer[11]->play();
        m_animation[11]->start();
        ui->note_12->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F6 :
        pianoPlayer[12]->setPosition(0);
        pianoPlayer[12]->play();
        m_animation[12]->start();
        ui->note_13->setVisible(true);
        count+=1;
        break;
    case Qt::Key_F7 :
        pianoPlayer[13]->setPosition(0);
        pianoPlayer[13]->play();
        m_animation[13]->start();
        ui->note_14->setVisible(true);
        count+=1;
        break;
    //case Qt::Key_A : ui->pushButton->move(x-10, y); break;

    //case Qt::Key_D : ui->pushButton->move(x+10, y); break;
    default:
    break;
    }
    if(count>=10)
    {
        dataPtr->setExp(dataPtr->exp+1);
        count=0;
    }
    song1_check(e->key());
    //qDebug()<<count;
}

void MainWindow::song1_check(int key)
{
    static int song1[8]={Qt::Key_6,Qt::Key_6,Qt::Key_F1,Qt::Key_F2,Qt::Key_6,Qt::Key_6,Qt::Key_5,Qt::Key_6};
    if(s1process>=8)
        return;
    if(key==song1[s1process])
        s1process+=1;
    else  s1process=0;

    qDebug()<<s1process;
    if(s1process==8)
    {
        dataPtr->see=true;
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->see_learn->setVisible(true);
        ui->see_learn->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s1process";
    }
    return;
}
