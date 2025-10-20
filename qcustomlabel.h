#ifndef QCUSTOMLABEL_H
#define QCUSTOMLABEL_H

#include <QLabel>
#include <QWidget>

class QCustomLabel : public QLabel
{
    Q_OBJECT
public:
    explicit QCustomLabel(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    virtual bool event(QEvent *e);
};

#endif // QCUSTOMLABEL_H
