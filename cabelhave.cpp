#include "cabelhave.h"

CabelHave::CabelHave(QDate v_DateHave, QString v_NumberHave, int v_QuantityHave, QString v_FIOHave)
{
    DateHave=v_DateHave;
    NumberHave=v_NumberHave;
    QuantityHave=v_QuantityHave;
    FIOHave=v_FIOHave;
}

QDate CabelHave::getDateHave()
{
    return DateHave;
}

QString CabelHave::getNumberHave()
{
    return NumberHave;
}

int CabelHave::getQuantityHave()
{
    return QuantityHave;
}

QString CabelHave::getFIOHave()
{
    return FIOHave;
}

void CabelHave::setDateHave(QDate v_DateHave)
{
    DateHave=v_DateHave;
}

void CabelHave::setNumberHave(QString v_NumberHave)
{
    NumberHave=v_NumberHave;
}

void CabelHave::setQuantityHave(int v_QuantityHave)
{
    QuantityHave=v_QuantityHave;
}

void CabelHave::setFIOHave(QString v_FIOHave)
{
    FIOHave=v_FIOHave;
}
