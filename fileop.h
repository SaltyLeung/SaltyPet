#ifndef FILEOP_H
#define FILEOP_H
#include"data.h"

class FileOp
{
public:
    FileOp();
    static bool fileLoad(Data* gameData);
    static bool fileCreate();
    static bool save(const Data* gameData);
};

#endif // FILEOP_H
