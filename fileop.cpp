#include "fileop.h"
#include"datastreamop.h"
#include<QFile>
#include<QDataStream>
#include<QDebug>
FileOp::FileOp()
{

}
bool FileOp::fileLoad(Data *gameData)
{
    QFile file("save.salty");
    if (!file.open((QIODevice::ReadOnly)))
        return false;
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_3);
    in>>*gameData;
    if(!file.flush())
    {
        qDebug("File loading incompleted.");
    }

    return true;
}

bool FileOp::fileCreate()
{
  QFile file("save.salty");
  if (!file.open((QIODevice::WriteOnly)))
      return false;
  QDataStream out(&file);
  out.setVersion(QDataStream::Qt_4_3);
  Data temp;
  out<<temp;
  if(!file.flush())
  {
      qDebug("File creating incompleted.");
  }

  return true;
}

bool FileOp::save(const Data *gameData)
{
    QFile file("save.salty");
    if (!file.open((QIODevice::WriteOnly)))
        return false;
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_3);
    out<< *gameData;
    if(!file.flush())
    {
        qDebug("Saving incompleted.");
    }

    return true;
}


