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
    void setHungry(int);
    void setDirty(int);

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
    int period;//0 egg; 1 little; 2 small; 3 dilu; 4 fire; 5 chao; 6 cold; 7 red; 8 old; 9 ha
    bool see;
    bool doubleDragon;
    int hungry;
    int dirty;
signals:
    void dataChanged();
};

#endif // DATA_H
