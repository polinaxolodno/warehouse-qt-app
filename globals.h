#ifndef GLOBALS_H
#define GLOBALS_H

#include <QMessageBox>

int showMessageBox(QString message, QString title, QMessageBox::Button button, QMessageBox::Icon icon);
int showMessageBox(QString message, QString title, QList<QMessageBox::Button> buttons, QMessageBox::Icon icon);


#endif // GLOBALS_H
