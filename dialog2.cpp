#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2( AdventureWindow* wptr,QWidget *parent) :
    QDialog(parent),adw(wptr),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    //ui->lineEdit->setCursor(QCursor(Qt::BlankCursor));
    this->setWindowFlags(Qt::FramelessWindowHint);
     QObject::connect(ui->quit, SIGNAL(clicked()), this, SLOT(quit()));
     ui->exp->setText(QString::number(adw->thisExp));
     ui->acexp->setText(QString::number(adw->acExp+adw->thisExp));
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::quit()
{
    adw->w->dataPtr->setExp(adw->w->dataPtr->exp+adw->acExp+adw->thisExp);
    this->close();
    adw->quit();
    //delete adw;
}
