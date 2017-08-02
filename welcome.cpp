#include "welcome.h"
#include "ui_welcome.h"
#include"fileop.h"
#include "data.h"
#include"introduce.h"
#include<QPropertyAnimation>
#include<QMessageBox>
Welcome::Welcome(MainWindow* wptr, QWidget *parent) :
    w(wptr),QMainWindow(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    ui->start_button->setStyleSheet("QPushButton{border-image: url(:/ui/start);}"
                                    "QPushButton:hover{border-image: url(:/ui/start_press);}");
    ui->load_button->setStyleSheet("QPushButton{border-image: url(:/ui/load);}"
                                    "QPushButton:hover{border-image: url(:/ui/load_press);}");
    QObject::connect(ui->start_button, SIGNAL(clicked()), this, SLOT(start_clicked()));
    QObject::connect(ui->load_button, SIGNAL(clicked()), this, SLOT(load_clicked()));
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::start_clicked()
{
    bool isOpen=FileOp::fileCreate();
    if(isOpen==false)
    {
        QMessageBox message(QMessageBox::Information,"Information","File Create failed.",QMessageBox::Yes,NULL);
        //QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        message.exec();
    }
    QPropertyAnimation *animation = new QPropertyAnimation(&(*w),"windowOpacity");
            animation->setDuration(1000);
            animation->setStartValue(0);
            animation->setEndValue(1);
            animation->start();
    this->hide();
    Introduce *introduce=new Introduce(w);
    introduce->show();
}

void Welcome::load_clicked()
{
    bool isOpen=FileOp::fileLoad(w->dataPtr);
    if(isOpen==false)
    {
        QMessageBox message(QMessageBox::Information,"Information","File Create failed.",QMessageBox::Yes,NULL);
        //QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        message.exec();
    }
    QPropertyAnimation *animation = new QPropertyAnimation(&(*w),"windowOpacity");
            animation->setDuration(1000);
            animation->setStartValue(0);
            animation->setEndValue(1);
            animation->start();
    this->hide();
    w->dataUpdate();
    w->show();
}
