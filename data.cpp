#include "data.h"
#include<cmath>
Data::Data(QObject *parent) : QObject(parent)
{
    level=0;//setLevel(0);
    attribute=0;//setAttr(0);
    exp=0;//setExp(0);
    coin=0;//setCoin(0);
    gender=0;//setGender(true);//true=man;false=female
    status=0;//setStatus(0);//0 normal;1 hungry;2 dirty;3 both
    period=0;//setPeriod(0);//0 egg;1 little
    see=false;
    doubleDragon=false;
    hungry=0;//setHungry(0);
    dirty=0;
    setName("anonymous");
}
void Data::setLevel(int x)
{
    level=x;
    emit dataChanged();
}
void Data::setName(QString x)
{
    name=x;
    emit dataChanged();
}

void Data::setAttr(int x)
{
    attribute=x;
    emit dataChanged();
}

void Data::setExp(int x)
{
    exp=x;
    hungry+=5;
    dirty+=10;
    if(hungry>=100&&dirty>=100)status=3;
    else if(dirty>=100)status=2;
    else if(hungry>=100)status=1;
    else status=0;
    emit dataChanged();
}

void Data::setCoin(int x)
{
    coin=x;
    emit dataChanged();
}

void Data::setGender(bool x)
{
    gender=x;
    emit dataChanged();
}

void Data::setStatus(int x)
{
    status=x;
    emit dataChanged();
}

void Data::setPeriod(int x)
{
    period=x;
    emit dataChanged();
}

int Data::getLevel() const
{
    return level;
}

QString Data::getName() const
{
    return name;
}

int Data::getAttribute() const
{
    return attribute;
}

int Data::getExp() const
{
    return exp;
}

int Data::getCoin() const
{
    return coin;
}

bool Data::getGender() const
{
    return gender;
}

int Data::getStatus() const
{
    return status;
}

int Data::getPeriod() const
{
    return period;
}

void Data::levelCheck()
{
    if(exp>pow(2,(level+1)))
        setLevel(level+1);
}

void Data::setHungry(int x)
{
    hungry=x;
    emit dataChanged();
}

void Data::setDirty(int x)
{
    dirty=x;
    emit dataChanged();
}
