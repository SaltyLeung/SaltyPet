#include "mainwindow.h"
#include"fileop.h"
#include <QApplication>
#include<QPropertyAnimation>
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Data gameData;
    bool restart=true;
    bool isOpen=false;
    if(restart==true) isOpen=FileOp::fileCreate();
    else isOpen=FileOp::fileLoad(&gameData);
    if(isOpen==false)
    {
        QMessageBox message(QMessageBox::Information,"Information","File Create failed.",QMessageBox::Yes,NULL);
        //QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        message.exec();
    }
    MainWindow w;
    w.setWindowTitle("Salty Pet");
    w.dataPtr=&gameData;
    QPropertyAnimation *animation = new QPropertyAnimation(&w,"windowOpacity");
            animation->setDuration(1000);
            animation->setStartValue(0);
            animation->setEndValue(1);
            animation->start();
    w.show();

    return a.exec();
}
