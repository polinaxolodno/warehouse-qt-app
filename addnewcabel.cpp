#include "addnewcabel.h"
#include "ui_addnewcabel.h"
#include "globals.h"

addnewcabel::addnewcabel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addnewcabel)
{
    ui->setupUi(this);
}

addnewcabel::~addnewcabel()
{
    delete ui;
}

void addnewcabel::on_PHB_newcabelApply_clicked()
{
    if(ui->LE_cabelnum->text().remove(" ").length() > 0)
    {
        if(ui->SB_quantitycabel->value() > 0)
        {
            Cabel *cl = new Cabel(ui->LE_cabelnum->text(), ui->SB_quantitycabel->value());
            emit cabelAdded(cl);
            if(showMessageBox("Новый кабель успешно добавлен!", "Успешно!", QMessageBox::Ok, QMessageBox::Information) == QMessageBox::Ok)
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
        showMessageBox("Поле 'Номер кабеля' обязательно для заполнения!", "Прервано!", QMessageBox::Ok, QMessageBox::Warning);
    }
}

