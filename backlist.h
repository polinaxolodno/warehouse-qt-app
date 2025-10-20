#ifndef BACKLIST_H
#define BACKLIST_H

#include "cabelback.h"
#include <QList>

class backlist
{
private:
    QList <cabelback*> backList;
public:
    backlist();
    void addBack(cabelback*NewBack);
    void deleteBack(int index);
    QList <cabelback*> getBackList();
};

#endif // BACKLIST_H
