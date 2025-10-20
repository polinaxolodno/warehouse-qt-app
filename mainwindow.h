#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cabellist.h"
#include "havelist.h"
#include "backlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showCabel();
    void showHave();
    void showBack();

private slots:
    void on_PHB_addnewcabel_clicked();
    void addNewCabelToList(Cabel *cl);
    void updateCabelList();

    void on_PHB_addnewhave_clicked();
    void addNewHaveToList(CabelHave *clh,int index);
    void updateHaveList();

    void on_PHB_addnewback_clicked();
    void addNewBackToList(cabelback *clb,int index);
    void updateBackList();

private:
    Ui::MainWindow *ui;
    cabellist *cabelList;
    havelist *haveList;
    backlist *backList;
};
#endif // MAINWINDOW_H
