/*#ifndef DATA1_H
#define DATA1_H
#include<QString>
#include <QMetaType>
#include<QVariant>
//enum attr{NONE,FIRE,ICE};
class Data
{
public:
    Data();

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

signals:
    void dataChanged();

public:
    int level;
    QString name;
    int attribute;//0 for none;1 for fire; 2 for ice;
    int exp;
    int coin;
    bool gender;//true=man;false=female
    int status;//0 normal;1 hungry;2 dirty;3 both
    int period;//0 egg;1 little
};
#endif // DATA_H*/
