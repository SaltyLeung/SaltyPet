#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(AdventureWindow * wptr,QWidget *parent) :
    QDialog(parent),adw(wptr),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //ui->lineEdit->setCursor(QCursor(Qt::BlankCursor));
    this->setWindowFlags(Qt::FramelessWindowHint);
    QObject::connect(ui->quit, SIGNAL(clicked()), this, SLOT(quit()));
    QObject::connect(ui->next, SIGNAL(clicked()), this, SLOT(next()));
    ui->exp->setText(QString::number(adw->thisExp));
    ui->acexp->setText(QString::number(adw->acExp+adw->thisExp));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::quit()
{
    adw->w->dataPtr->setExp(adw->w->dataPtr->exp+adw->acExp+adw->thisExp);
    this->close();
    adw->quit();
    //delete adw;
}

void Dialog::next()
{
    AdventureWindow *newadw=new AdventureWindow(adw->w,adw->acExp+adw->thisExp,adw->stage+1);
     (*newadw).setWindowFlags(adw->w->windowFlags()&~ (Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint));
     (*newadw).show();
    this->close();
    adw->close();
    //delete adw;
}
