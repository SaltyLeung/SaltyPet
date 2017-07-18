#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fileop.h"
#include<QFontDatabase>
#include<QFont>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFontDatabase::addApplicationFont(":/TTF/FZXS");
        ui->MainWindow->setFont(QFont(":/TTF/FZXS", 34));
    ui->feed_button->setStyleSheet("QPushButton{border-image: url(:/image/feed);}"
                                 "QPushButton:hover{border-image: url(:/image/feed_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/feed_press);}");
        ui->bath_button->setStyleSheet("QPushButton{border-image: url(:/image/bath);}"
                                 "QPushButton:hover{border-image: url(:/image/bath_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/bath_press);}");
        ui->adventure_button->setStyleSheet("QPushButton{border-image: url(:/image/adventure);}"
                                 "QPushButton:hover{border-image: url(:/image/adventure_hover);}"
                                    "QPushButton:pressed{border-image: url(:/image/adventure_press);}");
        QObject::connect(ui->feed_button, SIGNAL(clicked()), this, SLOT(feed_clicked()));
        QObject::connect(ui->bath_button, SIGNAL(clicked()), this, SLOT(bath_clicked()));
        QObject::connect(ui->adventure_button, SIGNAL(clicked()), this, SLOT(adventure_clicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
    FileOp::save(dataPtr);
}

void MainWindow::bath_clicked()
{

}

void MainWindow::feed_clicked()
{

}

void MainWindow::adventure_clicked()
{

}
