#include "skill.h"
#include "ui_skill.h"
Skill::Skill(MainWindow* wptr, QWidget *parent) :
    w(wptr),QDialog(parent),
    ui(new Ui::Skill)
{
    ui->setupUi(this);
    this->setWindowTitle("Skill Learning");
    ui->tips->setVisible(false);
    ui->tips_2->setVisible(false);
    ui->songNote->setVisible(false);
    if(w->dataPtr->level<5)
    {
        ui->see->setEnabled(false);
    }
    if(w->dataPtr->level<10)
    {
        ui->double_2->setEnabled(false);
    }
    if(w->dataPtr->see==true)
    {
        ui->see->setEnabled(false);
        ui->see->setText("Learnt");
    }
    if(w->dataPtr->doubleDragon==true)
    {
        ui->double_2->setEnabled(false);
        ui->double_2->setText("Learnt");
    }
    QObject:: connect(ui->see, SIGNAL(clicked()),this, SLOT(see()));
    QObject:: connect(ui->double_2, SIGNAL(clicked()),this, SLOT(dragon()));
}

Skill::~Skill()
{
    delete ui;
}

void Skill::see()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
    QString sheet="QLabel{border-image: url(:/piano/mission);}";
    ui->songNote->setStyleSheet(sheet);
    ui->songNote->setVisible(true);
}

void Skill::dragon()
{
    ui->tips->setVisible(true);
    ui->tips_2->setVisible(true);
    QString sheet="QLabel{border-image: url(:/piano/youngbook);}";
    ui->songNote->setStyleSheet(sheet);
    ui->songNote->setVisible(true);
}

 void Skill::keyPressEvent(QKeyEvent *e)
 {
        w->keyPressEvent(e);
 }
