#include "cabelback.h"

cabelback::cabelback(QDate v_DateBack, QString v_NumberBack, int v_QuantityBack, QString v_FIOBack)
{
    DateBack=v_DateBack;
    NumberBack=v_NumberBack;
    QuantityBack=v_QuantityBack;
    FIOBack=v_FIOBack;
}

QDate cabelback::getDateBack()
{
    return DateBack;
}

QString cabelback::getNumberBack()
{
    return NumberBack;
}

int cabelback::getQuantityBack()
{
    return QuantityBack;
}

QString cabelback::getFIOBack()
{
    return FIOBack;
}

void cabelback::setDateBack(QDate v_DateBack)
{
    DateBack=v_DateBack;
}

void cabelback::setNumberBack(QString v_NumberBack)
{
    NumberBack=v_NumberBack;
}

void cabelback::setQuantityBack(int v_QuantityBack)
{
    QuantityBack=v_QuantityBack;
}

void cabelback::setFIOBack(QString v_FIOBack)
{
    FIOBack=v_FIOBack;
}
