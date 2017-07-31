#ifndef DEVELOP_H
#define DEVELOP_H

#include <QDialog>

namespace Ui {
class develop;
}

class develop : public QDialog
{
    Q_OBJECT

public:
    explicit develop(QWidget *parent = 0);
    ~develop();

private:
    Ui::develop *ui;
};

#endif // DEVELOP_H
