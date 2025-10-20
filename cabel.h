#ifndef CABEL_H
#define CABEL_H

#include <QString>

class Cabel
{
private:
    QString number;
    int quantity;
public:
    Cabel(QString v_number, int v_quantity);

    QString getNumber();
    int getQuantity();

    void setNumber(QString v_number);
    void setQuantity(int v_quantity);
};

#endif // CABEL_H
