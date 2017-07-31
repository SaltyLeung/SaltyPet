#ifndef SKILL_H
#define SKILL_H

#include <QDialog>
#include"mainwindow.h"
namespace Ui {
class Skill;
}

class Skill : public QDialog
{
    Q_OBJECT

public:
    explicit Skill(MainWindow* , QWidget *parent = 0);
    ~Skill();

private:
    Ui::Skill *ui;
    void keyPressEvent(QKeyEvent *);
    //MainWindow* w;
private slots:
    void see();
    void dragon();
};

#endif // SKILL_H
