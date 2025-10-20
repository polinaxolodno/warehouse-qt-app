#include "addnewhave.h"
#include "ui_addnewhave.h"
#include "globals.h"

addnewhave::addnewhave(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addnewhave)
{
    ui->setupUi(this);
}

addnewhave::~addnewhave()
{
    delete ui;
}

void addnewhave::loadData(cabellist *cl)
{
    this->cl = cl;

    for(const auto& shit : cl->getCabelList())
    {
        ui->CBB_cabelnumHave->addItem(shit->getNumber());
    }

    ui->CBB_cabelnumHave->setCurrentIndex(-1);
}

void addnewhave::on_PHB_addnewhaveApply_clicked()
{
    QDate haveDate=ui->DE_DateHave->date();
    QDate currentDate=QDate::currentDate();
    if(haveDate <= currentDate)
    {
        if(ui->CBB_cabelnumHave->currentIndex() > -1)
        {
            if(ui->LE_FIOHave->text().remove(" ").length() > 0)
            {
                if(ui->SB_quanthave->value() > 0)
                {
                    CabelHave *clh = new CabelHave(ui->DE_DateHave->date(), ui->CBB_cabelnumHave->currentText(), ui->SB_quanthave->value(), ui->LE_FIOHave->text());
                    emit haveAdded(clh, ui->CBB_cabelnumHave->currentIndex());
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
        showMessageBox("Дата выдачи не может быть больше текущей даты!", "Прервано!", QMessageBox::Ok, QMessageBox::Warning);
    }
}

void addnewhave::on_CBB_cabelnumHave_currentIndexChanged(int index)
{
    if(index == -1) return;
    else
    {
        Cabel *temp = cl->getCabelList().at(index);
        ui->LB_quantAll->setText(QString::number(temp->getQuantity()));
        ui->SB_quanthave->setMaximum(temp->getQuantity());
        ui->SB_quanthave->setEnabled(1);
    }
}

