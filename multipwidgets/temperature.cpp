#include "temperature.h"
TempWidget::TempWidget(QWidget *parent) : QWidget(parent)
{
    tempShow();
}
TempWidget::~TempWidget()
{}
void TempWidget::tempShow()
{
    //温度通道1
    QLabel *label_one = new QLabel(this);
    label_one->move(700,300+35);
    label_one->resize(50,50);
    label_one->setStyleSheet("QLabel{color:rgb(255,0,0);font: 11pt;}");
    label_one->setText("T1:");// <-----------温度1标签显示
    //温度通道2
    QLabel *label_two = new QLabel(this);
    label_two->move(700,300+70);
    label_two->resize(50,50);
    label_two->setStyleSheet("QLabel{color:rgb(255,0,0);font: 11pt;}");
    label_two->setText("T2:");// <-----------温度2标签显示
    //两通道温度差标签 TD
    QLabel *label_three = new QLabel(this);
    label_three->move(820,300+53);
    label_three->resize(50,50);
    label_three->setStyleSheet("QLabel{color:rgb(255,0,0);font: 11pt;}");
    label_three->setText("TD:");// <-----------温度 1，2 的温度差 TD 标签显示
    //温度 T1
    tpLabel1 = new QLabel;
    tpLabel1->setParent(this);
    tpLabel1->move(750,300+35);
    tpLabel1->resize(50,50);
    tpLabel1->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 18pt;}");
    tpLabel1->setText("36.7");// <-----------温度1显示
    //温度 T2
    tpLabel = new QLabel;
    tpLabel->setParent(this);
    tpLabel->move(750,300+70);
    tpLabel->resize(50,50);
    tpLabel->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 18pt;}");
    tpLabel->setText("36.2");// <-----------温度2显示
    //温度差
    QLabel *tpLabel3 = new QLabel;
    tpLabel3->setParent(this);
    tpLabel3->move(850,300+53);
    tpLabel3->resize(50,50);
    tpLabel3->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 18pt;}");
    tpLabel3->setText("0.5");// <-----------温度1显示
    //名称
    QLabel *tpNamelabel = new QLabel(this);
    tpNamelabel->setText("温度(Temp)");
    tpNamelabel->move(700,300+5);
    tpNamelabel->resize(150,40);
    tpNamelabel->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 12pt;}");
    //3 单位
    QLabel *unitlabel = new QLabel(this);
    unitlabel->setText("-");
    unitlabel->move(925,300+105);
    unitlabel->resize(80,40);
    unitlabel->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 12pt;}");
}
