#ifndef DATASTREAMOP_H
#define DATASTREAMOP_H
#include<QFile>
#include<QDataStream>
//#define level getLevel()
//#define name getName()
//#define attribute getAttribute()
//#define exp getExp()
//#define coin getCoin()
//#define gender getGender()
//#define status getStatus()
//#define period getPeriod()
QDataStream& operator<<(QDataStream& out, const Data& gameData)
    {
         //out.setVersion(QDataStream::Qt_4_3);
        out<<gameData.level<<gameData.name<<gameData.attribute<<
             gameData.exp<<gameData.coin<<gameData.gender<<gameData.status<<gameData.period;
        return out;
    }

    QDataStream& operator>>(QDataStream& in,Data& gameData)
    {
         //in.setVersion(QDataStream::Qt_4_3);
         in>>gameData.level>>gameData.name>>gameData.attribute>>
             gameData.exp>>gameData.coin>>gameData.gender>>gameData.status>>gameData.period;
       return in;
    }
#endif // DATASTREAMOP_H
