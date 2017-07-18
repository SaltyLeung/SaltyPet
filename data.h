#ifndef DATA_H
#define DATA_H
#include<QString>
//enum attr{NONE,FIRE,ICE};
class Data
{
public:
    Data();
    int level;
    QString name;
    int attribute;//0 for none;1 for fire; 2 for ice;
    int hp;
    int exp;
    int coin;
};

#endif // DATA_H
