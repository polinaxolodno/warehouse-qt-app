#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomlabel.h"
#include "addnewcabel.h"
#include "addnewhave.h"
#include "addnewback.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //qDebug()<<"MainWindow запущен";
    ui->setupUi(this);
    ui->TAB_MainFlow->setCurrentIndex(0);

    cabelList = new cabellist();
    haveList = new havelist();
    backList = new backlist();

    ui->TW_cabellist->setColumnWidth(0, 60);
    ui->TW_cabellist->setColumnWidth(1, 350);

    ui->TW_cabellist->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | Qt::AlignVCenter | Qt::Alignment(Qt::TextWordWrap));
    ui->TW_cabellist->horizontalHeader()->setMinimumHeight(40);

    ui->TW_havelist->setColumnWidth(0, 60);
    ui->TW_havelist->setColumnWidth(1, 90);
    ui->TW_havelist->setColumnWidth(2, 180);
    ui->TW_havelist->setColumnWidth(3, 220);

    ui->TW_havelist->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | Qt::AlignVCenter | Qt::Alignment(Qt::TextWordWrap));
    ui->TW_havelist->horizontalHeader()->setMinimumHeight(40);

    ui->TW_backlist->setColumnWidth(0, 60);
    ui->TW_backlist->setColumnWidth(1, 90);
    ui->TW_backlist->setColumnWidth(2, 180);
    ui->TW_backlist->setColumnWidth(3, 220);

    ui->TW_backlist->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter | Qt::AlignVCenter | Qt::Alignment(Qt::TextWordWrap));
    ui->TW_backlist->horizontalHeader()->setMinimumHeight(40);

    connect(ui->LB_Have, &QCustomLabel::clicked, this, &MainWindow::showHave);
    connect(ui->LB_back, &QCustomLabel::clicked, this, &MainWindow::showBack);
    connect(ui->LB_cabel, &QCustomLabel::clicked, this, &MainWindow::showCabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showBack()
{
    ui->TAB_MainFlow->setCurrentIndex(2);
}

void MainWindow::showHave()
{
    ui->TAB_MainFlow->setCurrentIndex(1);
}

void MainWindow::showCabel()
{
    ui->TAB_MainFlow->setCurrentIndex(0);
}

void MainWindow::on_PHB_addnewcabel_clicked()
{
    addnewcabel *newCL = new addnewcabel();
    connect(newCL, &addnewcabel::cabelAdded, this, &MainWindow::addNewCabelToList);
    this->hide();
    newCL->show();
    while(newCL->isVisible())
    {
        QApplication::processEvents();
    }
    this->show();
}

void MainWindow::addNewCabelToList(Cabel *cl)
{
    //qDebug()<<"Метод addNewCabelToList начат";
    cabelList->addCabel(cl);
    updateCabelList();
    //qDebug()<<"Метод addNewCabelToList завершен";
}

void MainWindow::updateCabelList()
{
    while (ui->TW_cabellist->rowCount() > 0)
        ui->TW_cabellist->removeRow(0);

    int i = 0;
    for(const auto &cl : cabelList->getCabelList())
    {
        int rowCount = ui->TW_cabellist->rowCount();
        ui->TW_cabellist->insertRow(rowCount);
        ui->TW_cabellist->setItem(rowCount, 0, new QTableWidgetItem(QString::number(i)));
        ui->TW_cabellist->item(rowCount, 0)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_cabellist->setItem(rowCount, 1, new QTableWidgetItem(cl->getNumber()));
        ui->TW_cabellist->item(rowCount, 1)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_cabellist->setItem(rowCount, 2, new QTableWidgetItem(QString::number(cl->getQuantity())));
        ui->TW_cabellist->item(rowCount, 2)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        i++;
    }
    ui->TW_cabellist->resizeRowsToContents();
    //ui->TW_cabellist->resizeColumnsToContents();
}

void MainWindow::on_PHB_addnewhave_clicked()
{       
    addnewhave *newCLH = new addnewhave();
    newCLH->loadData(cabelList);
    connect(newCLH, &addnewhave::haveAdded, this, &MainWindow::addNewHaveToList);
    this->hide();
    newCLH->show();
    while(newCLH->isVisible())
    {
        QApplication::processEvents();
    }
    this->show();
}

void MainWindow::addNewHaveToList(CabelHave *clh, int index)
{
    haveList->addHave(clh);


    Cabel *cl = cabelList->getCabelList().at(index);
    cl->setQuantity(cl->getQuantity() - clh->getQuantityHave());
    cabelList->getCabelList().replace(index, cl);

    updateHaveList();
    updateCabelList();
}

void MainWindow::updateHaveList()
{
    while (ui->TW_havelist->rowCount() > 0)
        ui->TW_havelist->removeRow(0);

    int i = 0;
    for(const auto &clh : haveList->getHaveList())
    {
        int rowCount = ui->TW_havelist->rowCount();
        ui->TW_havelist->insertRow(rowCount);
        ui->TW_havelist->setItem(rowCount, 0, new QTableWidgetItem(QString::number(i)));
        ui->TW_havelist->item(rowCount, 0)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_havelist->setItem(rowCount, 1, new QTableWidgetItem(clh->getDateHave().toString("dd.MM.yyyy")));
        ui->TW_havelist->item(rowCount, 1)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_havelist->setItem(rowCount, 2, new QTableWidgetItem(clh->getNumberHave()));
        ui->TW_havelist->item(rowCount, 2)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_havelist->setItem(rowCount, 3, new QTableWidgetItem(clh->getFIOHave()));
        ui->TW_havelist->item(rowCount, 3)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_havelist->setItem(rowCount, 4, new QTableWidgetItem(QString::number(clh->getQuantityHave())));
        ui->TW_havelist->item(rowCount, 4)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        i++;
    }
    ui->TW_havelist->resizeRowsToContents();
   // ui->TW_havelist->resizeColumnsToContents();
}


void MainWindow::on_PHB_addnewback_clicked()
{
    addnewback *newCLB = new addnewback();
    newCLB->loadDataBack(haveList);
    connect(newCLB, &addnewback::backAdded, this, &MainWindow::addNewBackToList);
    this->hide();
    newCLB->show();
    while(newCLB->isVisible())
    {
        QApplication::processEvents();
    }
    this->show();
}

void MainWindow::addNewBackToList(cabelback *clb, int index)
{
    backList->addBack(clb);


    Cabel *cl = cabelList->getCabelList().at(index);
    cl->setQuantity(cl->getQuantity() + clb->getQuantityBack());
    cabelList->getCabelList().replace(index, cl);

    updateBackList();
    updateCabelList();
}

void MainWindow::updateBackList()
{
    while (ui->TW_backlist->rowCount() > 0)
        ui->TW_backlist->removeRow(0);

    int i = 0;
    for(const auto &clb : backList->getBackList())
    {
        int rowCount = ui->TW_backlist->rowCount();
        ui->TW_backlist->insertRow(rowCount);
        ui->TW_backlist->setItem(rowCount, 0, new QTableWidgetItem(QString::number(i)));
        ui->TW_backlist->item(rowCount, 0)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);

        ui->TW_backlist->setItem(rowCount, 1, new QTableWidgetItem(clb->getDateBack().toString("dd.MM.yyyy")));
        ui->TW_backlist->item(rowCount, 1)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_backlist->setItem(rowCount, 2, new QTableWidgetItem(clb->getNumberBack()));
        ui->TW_backlist->item(rowCount, 2)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_backlist->setItem(rowCount, 3, new QTableWidgetItem(clb->getFIOBack()));
        ui->TW_backlist->item(rowCount, 3)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        ui->TW_backlist->setItem(rowCount, 4, new QTableWidgetItem(QString::number(clb->getQuantityBack())));
        ui->TW_backlist->item(rowCount, 4)->setTextAlignment(Qt::AlignCenter | Qt::AlignTop);
        i++;
    }
    ui->TW_backlist->resizeRowsToContents();
    //ui->TW_backlist->resizeColumnsToContents();
}

