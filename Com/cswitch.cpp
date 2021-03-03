#include "cswitch.h"
#include <QDebug>
#include <QBrush>

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
void CSwitch::mouseReleaseEvent(QMouseEvent *)
{
    QPalette p = this->palette();
    if(isOpen)
    {
        p.setBrush(QPalette::Window,QBrush(pixopen));
    }
    else
    {
        p.setBrush(QPalette::Window,QBrush(pixclose));
    }
    this->setPalette(p);
    isOpen = !isOpen;
    qDebug()<<isOpen;
    emit mSignal(mid);
}
void CSwitch::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void CSwitch::mouseMoveEvent(QMouseEvent *e)
{
    e->ignore();
}
void CSwitch::setimages(QString openimage, QString closeimage)
{
    pixopen = openimage;
    pixclose = closeimage;

}
