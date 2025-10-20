#ifndef CABELHAVE_H
#define CABELHAVE_H

#include <QString>
#include <QDate>

class CabelHave
{
private:
    QDate DateHave;
    QString NumberHave;
    int QuantityHave;
    QString FIOHave;


public:
    CabelHave(QDate v_DateHave, QString v_NumberHave, int v_QuantityHave, QString v_FIOHave);

    QDate getDateHave();
    QString getNumberHave();
    int getQuantityHave();
    QString getFIOHave();

    void setDateHave(QDate v_DateHave);
    void setNumberHave(QString v_NumberHave);
    void setQuantityHave(int v_QuantityHave);
    void setFIOHave(QString v_FIOHave);
};

#endif // CABELHAVE_H
