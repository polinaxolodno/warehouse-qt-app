#ifndef ADDNEWBACK_H
#define ADDNEWBACK_H

#include <QMainWindow>
#include "cabelback.h"
#include "cabellist.h"
#include "havelist.h"

namespace Ui {
class addnewback;
}

class addnewback : public QMainWindow
{
    Q_OBJECT

public:
    explicit addnewback(QWidget *parent = nullptr);
    ~addnewback();
    void loadDataBack(havelist *clh);

signals:
    void backAdded(cabelback *clb, int index);

private slots:
    void on_PHB_addnewbackApply_clicked();
    void on_CB_numCableBack_currentIndexChanged(int index);

private:
    Ui::addnewback *ui;    
    cabellist *cl;
    havelist *clh;
};

#endif // ADDNEWBACK_H
