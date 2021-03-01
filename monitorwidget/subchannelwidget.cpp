#include "subchannelwidget.h"
#include "mainwindow/widget.h"

SubChannelWidget::SubChannelWidget(QWidget *parent) : QWidget(parent)
{
    infoInit();
}
SubChannelWidget::~SubChannelWidget()
{

}
void SubChannelWidget::infoInit()
{
    srNum = new QLabel(this);
    QLabel *label3 = new QLabel(this);//<-----SR的label

    label3->move(625,343);
    srNum->move(750,380);

    label3->setStyleSheet("color:rgb(11,230,110);font: 36pt Arial");
    srNum->setStyleSheet("color:yellow;font: 60pt Arial");

    label3->setText("SR");
    srNum->setText("--");
}
