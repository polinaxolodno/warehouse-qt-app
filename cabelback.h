#ifndef CABELBACK_H
#define CABELBACK_H

#include <QString>
#include <QDate>

class cabelback
{
private:
    QDate DateBack;
    QString NumberBack;
    int QuantityBack;
    QString FIOBack;

public:
    cabelback(QDate v_DateBack, QString v_NumberBack, int v_QuantityBack, QString v_FIOBack);

    QDate getDateBack();
    QString getNumberBack();
    int getQuantityBack();
    QString getFIOBack();

    void setDateBack(QDate v_DateBack);
    void setNumberBack(QString v_NumberBack);
    void setQuantityBack(int v_QuantityBack);
    void setFIOBack(QString v_FIOBack);

};

#endif // CABELBACK_H
