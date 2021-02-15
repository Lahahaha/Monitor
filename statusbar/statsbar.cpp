#include "statsbar.h"
#include <QTimer>

StatusBar::StatusBar(QWidget *parent)
    :QWidget(parent)
{
    timeInit();
    QTimer *timer2 = new QTimer(this);
    timer2->start(1000);
    connect(timer2,SIGNAL(timeout()),this,SLOT(timeUpdate()));
}

StatusBar::~StatusBar(){

}

void StatusBar::timeInit()
{
    timeLabel = new QLabel(this);
    timeLabel->resize(250,30);
    timeLabel->move(700,10);

    QFont *font1 = new QFont;
    font1->setPointSize(12);
    timeLabel->setFont(*font1);

    QPalette tLabelpalette = timeLabel->palette();
    tLabelpalette.setColor(QPalette::WindowText,Qt::white);
    timeLabel->setPalette(tLabelpalette);


    timeLabel->show();
}

void StatusBar::timeUpdate()
{
    timeLabel->setText(time->currentDateTime().toString("yyyy.MM.dd  hh:mm:ss"));//<-----将时间更新显示到 label 中

}
