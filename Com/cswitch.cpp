#include "cswitch.h"
#include <QDebug>

CSwitch::CSwitch(QWidget *parent) : QPushButton(parent)
{
    mid = -1;
    resize(40,40);
}
void CSwitch::setId(int id)
{
    mid = id;
    qDebug()<<"setID";

}
void CSwitch::mouseReleaseEvent(QMouseEvent *e)
{
    e->ignore();
    emit mSignal(mid);
}
