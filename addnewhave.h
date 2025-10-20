#ifndef ADDNEWHAVE_H
#define ADDNEWHAVE_H

#include <QMainWindow>
#include "cabelhave.h"
#include "cabellist.h"

namespace Ui {
class addnewhave;
}

class addnewhave : public QMainWindow
{
    Q_OBJECT

public:
    explicit addnewhave(QWidget *parent = nullptr);
    ~addnewhave();
    void loadData(cabellist *cl);

signals:
    void haveAdded(CabelHave *clh, int index);

private slots:
    void on_PHB_addnewhaveApply_clicked();
    void on_CBB_cabelnumHave_currentIndexChanged(int index);

private:
    Ui::addnewhave *ui;
    cabellist *cl;
};

#endif // ADDNEWHAVE_H
