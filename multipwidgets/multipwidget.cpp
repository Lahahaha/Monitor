#include "multipwidget.h"

MultipWidget::MultipWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(960,720);
    ecg = new EcgWidget(this);
    spo = new Spo2Widget(this);
    resp = new RespWidget(this);
    temp = new TempWidget(this);
    hr = new HeartRate(this);

}

MultipWidget::~MultipWidget()
{
}
