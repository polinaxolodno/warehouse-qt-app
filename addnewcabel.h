#ifndef ADDNEWCABEL_H
#define ADDNEWCABEL_H

#include <QMainWindow>
#include "cabel.h"

namespace Ui {
class addnewcabel;
}

class addnewcabel : public QMainWindow
{
    Q_OBJECT

public:
    explicit addnewcabel(QWidget *parent = nullptr);
    ~addnewcabel();

signals:
    void cabelAdded(Cabel *cl);

private slots:
    void on_PHB_newcabelApply_clicked();

private:
    Ui::addnewcabel *ui;
};

#endif // ADDNEWCABEL_H
