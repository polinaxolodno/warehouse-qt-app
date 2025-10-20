#ifndef CABELLIST_H
#define CABELLIST_H

#include "cabel.h"
#include <QList>

class cabellist
{
private:
    QList <Cabel*> cabelList;
public:
    cabellist();
    void addCabel(Cabel*NewCabel);
    void deleteCabel(int index);
    QList <Cabel*> getCabelList();
};

#endif // CABELLIST_H

