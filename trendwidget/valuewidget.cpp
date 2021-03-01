#include "valuewidget.h"

ValueWidget::ValueWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(250,600);
    move(690,70);

    setupAiname();
    setupEmgname();
}
void ValueWidget::setupAiname()
{
    QLabel *nameLabel = new QLabel(this);
    nameLabel->move(5,5);
    nameLabel->setStyleSheet("QLabel{font:30pt;color:rgb(255,255,0)}");
    nameLabel->setText("AI");
}

void ValueWidget::setAidata(int data)
{
    QLabel *dataLabel = new QLabel(this);
    dataLabel->move(85,100);
    dataLabel->setStyleSheet("QLabel{font:80pt;color:rgb(255,255,0)}");
    dataLabel->setText(QString::number(data));
}
void ValueWidget::setAidata()
{
    QLabel *dataLabel = new QLabel(this);
    dataLabel->move(85,100);
    dataLabel->setStyleSheet("QLabel{font:80pt;color:rgb(255,255,0)}");
    dataLabel->setText("--");
}


void ValueWidget::setupEmgname()
{
    QLabel *nameLabel = new QLabel(this);
    nameLabel->move(5,290);
    nameLabel->setStyleSheet("QLabel{font:25pt;color:rgb(0,0,255)}");
    nameLabel->setText("EMG");
}

void ValueWidget::setEmgdata(int data)
{
    QLabel *dataLabel = new QLabel(this);
    dataLabel->move(85,340);
    dataLabel->setStyleSheet("QLabel{font:60pt;color:rgb(0,0,255)}");
    dataLabel->setText(QString::number(data));
}
void ValueWidget::setEmgdata()
{
    QLabel *dataLabel = new QLabel(this);
    dataLabel->move(85,340);
    dataLabel->setStyleSheet("QLabel{font:60pt;color:rgb(0,0,255)}");
    dataLabel->setText("--");
}

