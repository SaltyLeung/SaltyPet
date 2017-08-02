#include "mainwindow.h"
#include"fileop.h"
#include <QApplication>
#include<QPropertyAnimation>
#include<QMessageBox>
#include<QFontDatabase>
#include<QFont>
#include"random.h"
#include"welcome.h"
#include<QtMultimedia/QMediaPlayer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QFontDatabase::addApplicationFont(":/TTF/FZXS");
        //a.setFont(QFont(":/TTF/FZXS"));


    Data gameData;
    /*bool restart=true;
    bool isOpen=false;
    if(restart==true) isOpen=FileOp::fileCreate();
    else isOpen=FileOp::fileLoad(&gameData);
    if(isOpen==false)
    {
        QMessageBox message(QMessageBox::Information,"Information","File Create failed.",QMessageBox::Yes,NULL);
        //QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        message.exec();
    }*/

    MainWindow w(&gameData);
    //w.setWindowFlags(windowFlags()&~ Qt::WindowMinMaxButtonsHint);
    w.setWindowTitle("Salty Pet");

    Welcome welcome(&w);
    welcome.setWindowTitle("Salty Pet");
    QPropertyAnimation *animation1 = new QPropertyAnimation(&welcome,"windowOpacity");
            animation1->setDuration(1000);
            animation1->setStartValue(0);
            animation1->setEndValue(1);
            animation1->start();
    welcome.show();


    /*QPropertyAnimation *animation = new QPropertyAnimation(&w,"windowOpacity");
            animation->setDuration(1000);
            animation->setStartValue(0);
            animation->setEndValue(1);
            animation->start();
    w.show();*/
    return a.exec();
}
