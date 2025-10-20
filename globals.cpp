#include "globals.h"

int showMessageBox(QString message, QString title, QMessageBox::Button button, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setText(message);
    msg.setWindowTitle(title);
    msg.setStandardButtons(button);
    msg.setIcon(icon);
    return msg.exec();
}

int showMessageBox(QString message, QString title, QList<QMessageBox::Button> buttons, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setText(message);
    msg.setWindowTitle(title);
    for(const auto &btn : buttons)
        msg.addButton(btn);
    msg.setDefaultButton(buttons.at(0));
    msg.setIcon(icon);
    return msg.exec();
}
