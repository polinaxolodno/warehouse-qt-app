#include "havelist.h"
#include "globals.h"

havelist::havelist() {}

void havelist::addHave(CabelHave *NewHave)
{
    haveList.push_back(NewHave);
}

void havelist::deleteHave(int index)
{
    if (index >= 0 && index < haveList.size())
    {
        haveList.removeAt(index);
    }
    else
    {
        showMessageBox("Ошибка ввода № записи!", "Ошибка удаления!", QMessageBox::Ok, QMessageBox::Critical);
    }
}

QList<CabelHave *> havelist::getHaveList()
{
    return haveList;
}
