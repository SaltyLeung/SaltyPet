#include "develop.h"
#include "ui_develop.h"

develop::develop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::develop)
{
    ui->setupUi(this);
}

develop::~develop()
{
    delete ui;
}
