#include "mainchannelwidget.h"
#include "mainwindow/widget.h"

MainChannelWidget::MainChannelWidget(QWidget *parent) : QWidget(parent)
{
    infoInit();
}
MainChannelWidget::~MainChannelWidget()
{
}

void MainChannelWidget::infoInit()
{

    QLabel *label1 = new QLabel(this);//<-----EMG的label
    QLabel *label2 = new QLabel(this);//<-----SQI的label
    QLabel *label3 = new QLabel(this);//<----[90 - 100]


    emgNum = new QLabel(this);
    sqiNum = new QLabel(this);
    emgData = new QLabel(this);

    label1->setStyleSheet("color:blue;font: 26pt Arial");
    label2->setStyleSheet("color:rgb(81,168,237);font: 26pt Arial ");
    label3->setStyleSheet("color:rgb(255,255,255);font: 20pt Arial");

    emgNum->setStyleSheet("color:blue;font: 24pt Arial");
    sqiNum->setStyleSheet("color:rgb(81,168,237);font: 24pt Arial");
    emgData->setStyleSheet("color:yellow;font: 60pt Arial");


    emgNum->move(630,110);
    sqiNum->move(630,230);
    emgData->move(760,150);


    label1->move(620,70);
    label2->move(620,180);
    label3->move(710,260);

    label1->setText("EMG");
    label2->setText("SQI");

    label3->setText("[90 - 100]");

    emgNum->setText("11");
    sqiNum->setText("50");
    emgData->setText("--");


}
