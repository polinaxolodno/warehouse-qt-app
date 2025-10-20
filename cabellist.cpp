#include "cabellist.h"
#include "globals.h"

cabellist::cabellist() {}

void cabellist::addCabel(Cabel *NewCabel)
{
    cabelList.push_back(NewCabel);
}

void cabellist::deleteCabel(int index)
{
    if (index >= 0 && index < cabelList.size())
    {
        cabelList.removeAt(index);
    }
    else
    {
        showMessageBox("Ошибка ввода № записи!", "Ошибка удаления!", QMessageBox::Ok, QMessageBox::Critical);
    }
}

QList<Cabel *> cabellist::getCabelList()
{
    return cabelList;
}
