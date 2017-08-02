#include "introduce.h"
#include "ui_introduce.h"
#include<QGraphicsOpacityEffect>
#include<QPropertyAnimation>
#include"name.h"
Introduce::Introduce(MainWindow* wptr,QWidget *parent) :
    w(wptr),QMainWindow(parent),
    ui(new Ui::Introduce)
{
    ui->setupUi(this);
    QObject:: connect(ui->next, SIGNAL(clicked()), this, SLOT(next_clicked()));
}

Introduce::~Introduce()
{
    delete ui;
}

void Introduce::next_clicked()
{
    static int p=1;
    if(p==8)
    {
        Name *name=new Name(w,this);
        name->exec();
        return;
    }
    QGraphicsOpacityEffect *effect1=new QGraphicsOpacityEffect(),*effect2=new QGraphicsOpacityEffect();
        effect1->setOpacity(1);
        ui->label->setGraphicsEffect(effect1);
        QPropertyAnimation*m_animation1= new QPropertyAnimation(effect1,"opacity",effect1);
        m_animation1->setStartValue(1);
        //m_animation->setKeyValueAt(0.3, 1);
        //m_animation->setKeyValueAt(0.7, 1);
        m_animation1->setEndValue(0);
        m_animation1->setDuration(600);
        //ui->label->setStyleSheet("QLabel{border-image:url(:/ui/p"+QString::number(p)+")}");
        ui->next->setEnabled(false);
        m_animation1->start();
        sleep(600);

        effect2->setOpacity(0);
        ui->label->setGraphicsEffect(effect2);
        QPropertyAnimation*m_animation2= new QPropertyAnimation(effect2,"opacity",effect2);
        m_animation2->setStartValue(0);
        //m_animation->setKeyValueAt(0.3, 1);
        //m_animation->setKeyValueAt(0.7, 1);
        m_animation2->setEndValue(1);
        m_animation2->setDuration(600);
        ui->label->setStyleSheet("QLabel{border-image:url(:/ui/p"+QString::number(p+1)+")}");
        m_animation2->start();
        sleep(600);
        p+=1;
        ui->next->setEnabled(true);
}
