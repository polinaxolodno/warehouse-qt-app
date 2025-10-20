#include "cabel.h"

Cabel::Cabel(QString v_number, int v_quantity)
{
    number=v_number;
    quantity=v_quantity;
}

QString Cabel::getNumber()
{
    return number;
}
int Cabel::getQuantity()
{
    return quantity;
}

void Cabel::setNumber(QString v_number)
{
    number=v_number;
}

void Cabel::setQuantity(int v_quantity)
{
    quantity=v_quantity;
}
