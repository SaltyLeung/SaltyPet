#include "develop.h"
#include "ui_develop.h"
#include"mainwindow.h"
develop::develop(MainWindow* wptr,QWidget *parent) :
    w(wptr),QDialog(parent),
    ui(new Ui::develop)
{
    ui->setupUi(this);
    ui->tips->setVisible(false);
    ui->tips_2->setVisible(false);
    ui->songNote->setVisible(false);
    if(w->dataPtr->level<5)
    {
        ui->littleCat->setEnabled(false);
    }
    if(w->dataPtr->level<10)
    {
        ui->smallCat->setEnabled(false);
    }
    if(w->dataPtr->level<15)
    {
        ui->dilu->setEnabled(false);
    }
    if(w->dataPtr->level<20)
    {
        ui->iceCat->setEnabled(false);
        ui->ghostCat->setEnabled(false);
        ui->fireCat->setEnabled(false);
    }
    if(w->dataPtr->level<30)
    {
        ui->redCoat->setEnabled(false);
        ui->old->setEnabled(false);
        ui->ha->setEnabled(false);
    }
    QObject::connect(ui->littleCat, SIGNAL(clicked()), this, SLOT(littleCat_click()));
    QObject::connect(ui->smallCat, SIGNAL(clicked()), this, SLOT(smallCat_click()));
    QObject::connect(ui->dilu, SIGNAL(clicked()), this, SLOT(dilu_click()));
    QObject::connect(ui->iceCat, SIGNAL(clicked()), this, SLOT(iceCat_click()));
    QObject::connect(ui->ghostCat, SIGNAL(clicked()), this, SLOT(ghostCat_click()));
    QObject::connect(ui->fireCat, SIGNAL(clicked()), this, SLOT(fireCat_click()));
    QObject::connect(ui->redCoat, SIGNAL(clicked()), this, SLOT(redCoat_click()));
    QObject::connect(ui->old, SIGNAL(clicked()), this, SLOT(old_click()));
    QObject::connect(ui->ha, SIGNAL(clicked()), this, SLOT(ha_click())); //0 egg; 1 little; 2 small; 3 dilu; 4 fire; 5 chao; 6 cold; 7 red; 8 old; 9 ha
}

develop::~develop()
{
    delete ui;
}

void develop::littleCat_click()
{
    //w->dataPtr->setPeriod(1);
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
    ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/animal)}");
    ui->songNote->setVisible(true);
}

void develop::smallCat_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/bottle)}");
    ui->songNote->setVisible(true);
}

void develop::dilu_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/boy)}");
    ui->songNote->setVisible(true);
}

void develop::iceCat_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/mate)}");
    ui->songNote->setVisible(true);
}

void develop::ghostCat_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/national)}");
    ui->songNote->setVisible(true);
}

void develop::fireCat_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/onetime)}");
    ui->songNote->setVisible(true);
}

void develop::redCoat_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/scut)}");
    ui->songNote->setVisible(true);
}

void develop::old_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/secret)}");
    ui->songNote->setVisible(true);
}

void develop::ha_click()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
     ui->songNote->setStyleSheet("QLabel{border-image: url(:/song/snake)}");
    ui->songNote->setVisible(true);
}

void develop::keyPressEvent(QKeyEvent *e)
{
       w->keyPressEvent(e);
}

