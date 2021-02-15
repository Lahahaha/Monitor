#include "heartrate.h"
HeartRate::HeartRate(QWidget *parent) : QWidget(parent)
{
    this->resize(260,150);
    setproperty();
    setlocation();
}
void HeartRate::setlocation()
{
    this->move(700,5);
    hr->move(110,70);
    hrLabel->move(0,5);
    hrLabel->resize(80,40);
    unit->move(225,105);
    unit->resize(80,40);
}
void HeartRate::setproperty()
{
    hr = new QLabel(this);
    hr->setStyleSheet("QLabel{color: rgb(255, 0, 0);font: 55pt;}");
    hr->resize(110,75);
    hr->setText("120");
    //名称
    hrLabel = new QLabel(this);
    hrLabel->setText("心率(HR)");
    hrLabel->setStyleSheet("QLabel{color: rgb(0, 255, 0);font: 12pt;}");
    //单位标签
    unit = new QLabel(this);
    unit->setText("BMP");
    unit->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 12pt;}");
}

void HeartRate::setdata()
{
    hr->setText("120");
}
