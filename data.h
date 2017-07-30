#ifndef DATA_H
#define DATA_H

#include <QObject>

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject *parent = 0);

    void setLevel(int);
    void setName(QString);
    void setAttr(int);
    void setExp(int);
    void setCoin(int);
    void setGender(bool);
    void setStatus(int);
    void setPeriod(int);

    int getLevel() const;
    QString getName() const;
    int getAttribute() const;
    int getExp() const;
    int getCoin() const;
    bool getGender() const;
    int getStatus() const;
    int getPeriod() const;
    void levelCheck();
    int level;
    QString name;
    int attribute;//0 for none;1 for fire; 2 for ice;
    int exp;
    int coin;
    bool gender;//true=man;false=female
    int status;//0 normal;1 hungry;2 dirty;3 both
    int period;//0 egg;1 little
signals:
    void dataChanged();
};

#endif // DATA_H
