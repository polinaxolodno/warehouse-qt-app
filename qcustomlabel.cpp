#include "qcustomlabel.h"
#include <QMouseEvent>

QCustomLabel::QCustomLabel(QWidget *parent)
    : QLabel{parent}
{}

bool QCustomLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonRelease)
    {
        emit clicked();
    }

    return QWidget::event(e);
}
