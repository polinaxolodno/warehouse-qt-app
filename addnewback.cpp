#include "addnewback.h"
#include "ui_addnewback.h"
#include "globals.h"


addnewback::addnewback(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addnewback)
{
    ui->setupUi(this);
}

addnewback::~addnewback()
{
    delete ui;
}

void addnewback::loadDataBack(havelist *clh)
{

    this->clh = clh;

    for(const auto& shit : clh->getHaveList())
    {
        ui->CB_numCableBack->addItem(shit->getNumberHave());
        ui->CBB_FIOback->addItem(shit->getFIOHave());
    }

    ui->CB_numCableBack->setCurrentIndex(-1);
    ui->CBB_FIOback->setCurrentIndex(-1);

}

void addnewback::on_PHB_addnewbackApply_clicked()
{
    if(ui->DE_dateback->date() <= QDate::currentDate())
    {
        if(ui->CB_numCableBack->currentIndex() > -1)
        {
            if(ui->CBB_FIOback->currentIndex() > -1)
            {
                if(ui->SB_quntityBack->value() > 0)
                {
                    cabelback *clb = new cabelback(ui->DE_dateback->date(), ui->CB_numCableBack->currentText(),
                                                   ui->SB_quntityBack->value(), ui->CBB_FIOback->currentText());

                    emit backAdded(clb, ui->CB_numCableBack->currentIndex());

                    if(showMessageBox("Новая запись выдачи успешно добавлена", "Успешно!", QMessageBox::Ok, QMessageBox::Information) == QMessageBox::Ok)
                    {

                    }
                    this->close();
                }
                else
                {
                    showMessageBox("Поле 'Количество' обязательно для заполнения!", "Прервано!", QMessageBox::Ok, QMessageBox::Warning);
                }
            }
            else
            {
                showMessageBox("Поле 'ФИО' обязательно для заполнения!", "Прервано!", QMessageBox::Ok, QMessageBox::Warning);
            }
        }
        else
        {
            showMessageBox("Поле 'Номер кабеля' обязательно для заполнения!", "Прервано!", QMessageBox::Ok, QMessageBox::Warning);
        }
    }
    else
    {
        showMessageBox("Дата возврата не может быть больше текущей даты!", "Прервано!", QMessageBox::Ok, QMessageBox::Warning);
    }
}

void addnewback::on_CB_numCableBack_currentIndexChanged(int index)
{
    if(index == -1) return;
    else
    {
        CabelHave *temp = clh->getHaveList().at(index);
        ui->LB_valueHave->setText(QString::number(temp->getQuantityHave()));
        ui->SB_quntityBack->setMaximum(temp->getQuantityHave());
        ui->SB_quntityBack->setEnabled(1);

    }
}


