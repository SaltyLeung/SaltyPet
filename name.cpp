#include "name.h"
#include "ui_name.h"
#include"mainwindow.h"
#include<QLineEdit>
Name::Name(MainWindow*wptr,Introduce* iptr,QWidget *parent) :
    w(wptr),i(iptr),QDialog(parent),
    ui(new Ui::Name)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(ui->ok, SIGNAL(clicked()), this, SLOT(ok()));
    QObject::connect(ui->lineEdit, SIGNAL(textChanged ( const QString &)), this, SLOT(getText(const QString & )));
}

Name::~Name()
{
    delete ui;
}

void Name::ok()
{
    qDebug()<<text;
    w->dataPtr->setName(text);
    w->show();
    this->close();
    i->close();
}

void Name::getText(const QString & t)
{
    text=t;
}
