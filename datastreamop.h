#ifndef DATASTREAMOP_H
#define DATASTREAMOP_H
#include<QFile>
#include<QDataStream>
inline QDataStream& operator<<(QDataStream& out, const Data& gameData)
    {
        out<<gameData.level<<gameData.name<<gameData.attribute<<gameData.hp<<
             gameData.exp<<gameData.coin;
        return out;
    }

    inline QDataStream& operator>>(QDataStream& in,Data& gameData)
    {
        in>>gameData.level>>gameData.name>>gameData.attribute>>gameData.hp>>
             gameData.exp>>gameData.coin;
       return in;
    }
#endif // DATASTREAMOP_H
