#ifndef HAVELIST_H
#define HAVELIST_H

#include "cabelhave.h"
#include <QList>

class havelist
{
private:
    QList <CabelHave*> haveList;
public:
    havelist();
    void addHave(CabelHave*NewHave);
    void deleteHave(int index);
    QList <CabelHave*> getHaveList();
};

#endif // HAVELIST_H
