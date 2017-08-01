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
#include"help.h"
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
    ui->dragon_learn->setVisible(false);
    ui->develop_fire->setVisible(false);
    ui->develop_ghost->setVisible(false);
    ui->develop_ha->setVisible(false);
    ui->develop_ice->setVisible(false);
    ui->develop_little->setVisible(false);
    ui->develop_old->setVisible(false);
    ui->develop_dilu->setVisible(false);
    ui->develop_red->setVisible(false);
    ui->develop_small->setVisible(false);
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
    s2process=0;
    s3process=0;
    s4process=0;
    s5process=0;
    s6process=0;
    s7process=0;
    s8process=0;
    s9process=0;
    s10process=0;
    s11process=0;
    s12process=0;
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
    if((dataPtr->dirty)>25)dataPtr->setDirty(dataPtr->dirty-25);
    else dataPtr->setDirty(0);

}

void MainWindow::feed_clicked()
{
    if((dataPtr->hungry)>25)dataPtr->setHungry(dataPtr->hungry-25);
    else dataPtr->setHungry(0);
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

    if(dataPtr->hungry==0&&dataPtr->dirty==0) dataPtr->status=0;
    else if(dataPtr->hungry==0) dataPtr->status=2;
    else if(dataPtr->dirty==0) dataPtr->status=1;
    else dataPtr->status=3;
     QString status;
     switch(dataPtr->status)
     {
     case 0:
         status="Nice";
         ui->status->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         break;
     case 1:
         status="Hungry";
         ui->status->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
         break;
     case 2:
         status="Dirty";
         ui->status->setStyleSheet("QLabel{color: rgb(0, 0, 255);}");
         break;
     case 3:
         status="Hungry & Dirty";
         ui->status->setStyleSheet("QLabel{color: rgb(255, 0, 255);}");
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
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_egg);}");
         period="Egg";
         break;
     case 1:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_little);}");
         period="Ball Cat";
     break;
     case 2:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_small);}");
         period="Small Cat";
         break;
     case 3:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 0);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_dilu);}");
         period="Fake Tailmon";
         break;
     case 4:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_fire);}");
         dataPtr->attribute=1;
         period="Burst Fire";
         break;
     case 5:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 255);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_ghost);}");
         period="Ghost";
         break;
     case 6:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 255);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_ice);}");
         dataPtr->attribute=2;
         period="Enternal Blizzard";
         break;
     case 7:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 0);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_red);}");
         dataPtr->attribute=1;
         period="Red Coat";
         break;
     case 8:
         ui->period->setStyleSheet("QLabel{color: rgb(255, 0, 255);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_old);}");
         period="Elder";
         break;
     case 9:
         ui->period->setStyleSheet("QLabel{color: rgb(0, 0, 255);}");
         ui->pet->setStyleSheet("QLabel{border-image:url(:/image/pet_hallice);}");
         dataPtr->attribute=2;
         period="Hallace";
         break;
     default:
         period="Crazy Cat";
         break;
     }
     ui->period->setText(period);

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
     dataPtr->levelCheck();
     ui->level->setText(QString::number(dataPtr->level));
}

void MainWindow::finger_clicked()
{
    dataPtr->setLevel(30);
}

void MainWindow::help_clicked()
{
    Help *hlp=new Help(this);
    (*hlp).setWindowFlags(windowFlags()&~ (Qt::FramelessWindowHint|Qt::WindowMinMaxButtonsHint));
    (*hlp).show();
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
   song2_check(e->key());
   song3_check(e->key());
   song4_check(e->key());
    song5_check(e->key());
   song6_check(e->key());
   song7_check(e->key());
   song8_check(e->key());
   song9_check(e->key());
   song10_check(e->key());
   song11_check(e->key());
   song12_check(e->key());
    //qDebug()<<count;
}

void MainWindow::song1_check(int key)//谍中谍√
{
    static int song1[8]={Qt::Key_6,Qt::Key_6,Qt::Key_F1,Qt::Key_F2,Qt::Key_6,Qt::Key_6,Qt::Key_5,Qt::Key_6};
    static bool already=false;
    if(s1process>=8)
        return;
    if(key==song1[s1process])
        s1process+=1;
    else  s1process=0;

    qDebug()<<s1process;
    if(s1process==8)
    {
        if(already==false)dataPtr->see=true;
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
            s1process=0;
            already=true;
    }
    return;
}

void MainWindow::song2_check(int key)// 青花瓷√
{
    static int song2[11]={Qt::Key_F5,Qt::Key_F5,Qt::Key_F3,Qt::Key_F2,Qt::Key_F3,Qt::Key_6,Qt::Key_F2,Qt::Key_F3,Qt::Key_F5,Qt::Key_F3,Qt::Key_F2};
    static bool already=false;
    if(s2process>=11)
        return;
    if(key==song2[s2process])
        s2process+=1;
    else  s2process=0;

    qDebug()<<s2process;
    if(s2process==11)
    {
        if(already==false)
        {
            dataPtr->setPeriod(2);
        }
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_small->setVisible(true);
        ui->develop_small->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s2process";
            s2process=0;
            already=true;
    }
    return;
}

void MainWindow::song3_check(int key)//男儿当自强√
{
    static int song3[14]={Qt::Key_6,Qt::Key_F1,Qt::Key_6,Qt::Key_F1,Qt::Key_6,Qt::Key_5,Qt::Key_6,Qt::Key_6,Qt::Key_F1,Qt::Key_6,Qt::Key_F1,Qt::Key_5,Qt::Key_6,Qt::Key_F2};
    static bool already=false;
    if(s3process>=14)
        return;
    if(key==song3[s3process])
        s3process+=1;
    else  s3process=0;

    qDebug()<<s3process;
    if(s3process==14)
    {
        if(already==false)dataPtr->setPeriod(3);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_dilu->setVisible(true);
        ui->develop_dilu->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s3process";
            s3process=0;
            already=true;
    }
    return;
}

void MainWindow::song4_check(int key)//同桌的你√
{
    static int song4[15]={Qt::Key_F5,Qt::Key_F5,Qt::Key_F5,Qt::Key_F5,Qt::Key_F3,Qt::Key_F4,Qt::Key_F5,Qt::Key_F7,Qt::Key_F6,Qt::Key_F6,Qt::Key_F6,Qt::Key_F6,Qt::Key_F4,Qt::Key_F6,Qt::Key_F5};
    static bool already=false;
    if(s4process>=15)
        return;
    if(key==song4[s4process])
        s4process+=1;
    else  s4process=0;

    qDebug()<<s4process;
    if(s4process==15)
    {
        if(already==false)dataPtr->setPeriod(6);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_ice->setVisible(true);
        ui->develop_ice->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s4process";
            s4process=0;
            already=true;
    }
    return;
}

void MainWindow::song5_check(int key)
{
    static int song5[19]={Qt::Key_6,Qt::Key_6,Qt::Key_5,Qt::Key_6,Qt::Key_F1,Qt::Key_F2,Qt::Key_F3,Qt::Key_F1,Qt::Key_F2,Qt::Key_F3,Qt::Key_F3,Qt::Key_F6,Qt::Key_F6,Qt::Key_F5,Qt::Key_F3,Qt::Key_F2,Qt::Key_F1,Qt::Key_F2,Qt::Key_F3};
    static bool already=false;
    if(s5process>=19)
        return;
    if(key==song5[s5process])
        s5process+=1;
    else  s5process=0;

    qDebug()<<s5process;
    if(s5process==19)
    {
        if(already==false)dataPtr->setPeriod(5);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_ghost->setVisible(true);
        ui->develop_ghost->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s5process";
            s5process=0;
            already=true;
    }
    return;
}

void MainWindow::song6_check(int key)
{
    static int song6[13]={Qt::Key_F3,Qt::Key_F2,Qt::Key_F2,Qt::Key_F1,Qt::Key_F1,Qt::Key_F2,Qt::Key_F1,Qt::Key_F2,Qt::Key_F1,Qt::Key_F2,Qt::Key_F5,Qt::Key_F6,Qt::Key_F5};
    static bool already=false;
    if(s6process>=13)
        return;
    if(key==song6[s6process])
        s6process+=1;
    else  s6process=0;

    qDebug()<<s6process;
    if(s6process==13)
    {
        if(already==false)dataPtr->setPeriod(4);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_fire->setVisible(true);
        ui->develop_fire->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s6process";
            s6process=0;
            already=true;
    }
    return;
}

void MainWindow::song7_check(int key)
{
    static int song7[17]={Qt::Key_F1,Qt::Key_F1,Qt::Key_6,Qt::Key_5,Qt::Key_F5,Qt::Key_F5,Qt::Key_F6,Qt::Key_F5,Qt::Key_F6,Qt::Key_F5,Qt::Key_F5,Qt::Key_F3,Qt::Key_F1,Qt::Key_6,Qt::Key_F4,Qt::Key_F5,Qt::Key_F2};
    static bool already=false;
    if(s7process>=17)
        return;
    if(key==song7[s7process])
        s7process+=1;
    else  s7process=0;

    qDebug()<<s7process;
    if(s7process==17)
    {
        if(already==false)dataPtr->setPeriod(7);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_red->setVisible(true);
        ui->develop_red->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s7process";
            s7process=0;
            already=true;
    }
    return;
}

void MainWindow::song8_check(int key)
{
    static int song8[24]={Qt::Key_1,Qt::Key_F1,Qt::Key_7,Qt::Key_F1,Qt::Key_F1,Qt::Key_5,Qt::Key_5,Qt::Key_5,Qt::Key_5,Qt::Key_4,Qt::Key_4,Qt::Key_3,Qt::Key_1,Qt::Key_F1,Qt::Key_7,Qt::Key_F1,Qt::Key_F1,Qt::Key_5,Qt::Key_5,Qt::Key_5,Qt::Key_5,Qt::Key_F2,Qt::Key_F2,Qt::Key_F1};
    static bool already=false;
    if(s8process>=24)
        return;
    if(key==song8[s8process])
        s8process+=1;
    else  s8process=0;

    qDebug()<<s8process;
    if(s8process==24)
    {
        if(already==false)dataPtr->setPeriod(8);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_old->setVisible(true);
        ui->develop_old->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s8process";
            s8process=0;
            already=true;
    }
    return;
}

void MainWindow::song9_check(int key)
{
    static int song9[26]={Qt::Key_F7,Qt::Key_F3,Qt::Key_F6,Qt::Key_F6,Qt::Key_F3,Qt::Key_F5,Qt::Key_F7,Qt::Key_F3,Qt::Key_F6,Qt::Key_F6,Qt::Key_F3,Qt::Key_F5,Qt::Key_F7,Qt::Key_F3,Qt::Key_F6,Qt::Key_F6,Qt::Key_F6,Qt::Key_F3,Qt::Key_F5,Qt::Key_F7,Qt::Key_F3,Qt::Key_F6,Qt::Key_F6,Qt::Key_F6,Qt::Key_F3,Qt::Key_F5};
    static bool already=false;
    if(s9process>=26)
        return;
    if(key==song9[s9process])
        s9process+=1;
    else  s9process=0;

    qDebug()<<s9process;
    if(s9process==26)
    {
        if(already==false)dataPtr->setPeriod(9);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_ha->setVisible(true);
        ui->develop_ha->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s9process";
            s9process=0;
            already=true;
    }
    return;
}

void MainWindow::song10_check(int key)
{
    static int song10[20]={Qt::Key_F1,Qt::Key_F2,Qt::Key_F5,Qt::Key_F3,Qt::Key_F3,Qt::Key_F4,Qt::Key_F5,Qt::Key_F6,Qt::Key_F2,Qt::Key_F2,Qt::Key_F4,Qt::Key_F3,Qt::Key_F2,Qt::Key_F1,Qt::Key_3,Qt::Key_F2,Qt::Key_F1,Qt::Key_7,Qt::Key_7,Qt::Key_6};
    static bool already=false;
    if(s10process>=20)
        return;
    if(key==song10[s10process])
        s10process+=1;
    else  s10process=0;

    qDebug()<<s10process;
    if(s10process==20)
    {
        if(already==false)dataPtr->setPeriod(0);
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
            qDebug()<<"s10process";
            s10process=0;
            already=true;
    }
    return;
}

void MainWindow::song11_check(int key)
{
    static int song11[12]={Qt::Key_5,Qt::Key_F1,Qt::Key_F2,Qt::Key_F3,Qt::Key_5,Qt::Key_F4,Qt::Key_F3,Qt::Key_F2,Qt::Key_F1,Qt::Key_7,Qt::Key_7,Qt::Key_F5};
    static bool already=false;
    if(s11process>=12)
        return;
    if(key==song11[s11process])
        s11process+=1;
    else  s11process=0;

    qDebug()<<s11process;
    if(s11process==12)
    {
        if(already==false)dataPtr->doubleDragon=true;
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->dragon_learn->setVisible(true);
        ui->dragon_learn->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s11process";
            s11process=0;
            already=true;
    }
    return;
}



void MainWindow::song12_check(int key)
{
    static int song12[19]={Qt::Key_6,Qt::Key_F1,Qt::Key_F3,Qt::Key_F6,Qt::Key_F5,Qt::Key_F6,Qt::Key_F5,Qt::Key_F2,Qt::Key_F3,Qt::Key_F5,Qt::Key_F2,Qt::Key_F1,Qt::Key_6,Qt::Key_F6,Qt::Key_F5,Qt::Key_F6,Qt::Key_F5,Qt::Key_F2,Qt::Key_F3};
    static bool already=false;
    if(s12process>=19)
        return;
    if(key==song12[s12process])
        s12process+=1;
    else  s12process=0;

    qDebug()<<s12process;
    if(s12process==19)
    {
        if(already==false)dataPtr->setPeriod(1);
        static QGraphicsOpacityEffect *effect;
        effect=new QGraphicsOpacityEffect();
        effect->setOpacity(0);
        ui->develop_little->setVisible(true);
        ui->develop_little->setGraphicsEffect(effect);
            QPropertyAnimation*m_animation= new QPropertyAnimation(effect,"opacity",effect);
            m_animation->setStartValue(0);
            m_animation->setKeyValueAt(0.3, 1);
            m_animation->setKeyValueAt(0.7, 1);
            m_animation->setEndValue(0);
            m_animation->setDuration(1200);
            m_animation->start();
            qDebug()<<"s12process";
            s12process=0;
            already=true;
    }
    return;
}
