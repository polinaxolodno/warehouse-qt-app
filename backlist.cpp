#include "backlist.h"
#include "globals.h"

backlist::backlist() {}

void backlist::addBack(cabelback *NewBack)
{
    backList.push_back(NewBack);
}

void backlist::deleteBack(int index)
{
    if (index >= 0 && index < backList.size())
    {
        backList.removeAt(index);
    }
    else
    {
        showMessageBox("Ошибка ввода № записи!", "Ошибка удаления!", QMessageBox::Ok, QMessageBox::Critical);
    }
}

QList<cabelback *> backlist::getBackList()
{
    return backList;
}
