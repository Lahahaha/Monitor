#include "trendwidget.h"
#include <QFrame>
#include <QDebug>
TrendWidget::TrendWidget(QWidget *parent) : QWidget(parent)
{
    QFrame * frame = new QFrame(this);
    frame->setObjectName("myframe");
    frame->resize(960,720);
    frame->setStyleSheet("QFrame#myframe{border-image:url(:/new/prefix1/Resource/MainWindow/background.jpg)}");
    ai = new ShowValueWideget(this);
    ai->setAidata();
    emg = new ShowValueWideget(this);
    emg->setEmgdata();
    initbuttons();
    setlabels();
}
void TrendWidget::initbuttons()
{
    next = new TrendWidgetButtons(this);
    previous = new TrendWidgetButtons(this);
    left = new TrendWidgetButtons(this);
    right = new TrendWidgetButtons(this);
    plus = new TrendWidgetButtons(this);
    minus = new TrendWidgetButtons(this);
    next->move(20,540);
    next->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/TrendWidget/next.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/TrendWidget/next_press.png)}");
    previous->move(130,540);
    previous->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/TrendWidget/previous.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/TrendWidget/previous_press.png)}");
    left->move(240,540);
    left->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/TrendWidget/left.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/TrendWidget/left_press.png)}");
    right->move(350,540);
    right->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/TrendWidget/right.png)}"
                                  "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/TrendWidget/right_press.png)}");
    plus->move(460,540);
    plus->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/TrendWidget/plus.png)}"
                                  "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/TrendWidget/plus_press.png)}");
    minus->move(570,540);
    minus->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/TrendWidget/minus.png)}"
                                  "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/TrendWidget/minus_press.png)}");
}
void TrendWidget::setlabels()
{
    previousTrend = new CLabels(this);
    currentTrend = new CLabels(this);
    startTimeLabel = new CLabels(this);
    lenth = new CLabels(this);
    previousTrend->move(700,535);
    previousTrend->setText("历史趋势数量");
    currentTrend->move(700,575);
    currentTrend->setText("当前趋势");
    startTimeLabel->move(700,595);
    startTimeLabel->setText("-");
    lenth->move(700,615);
    lenth->setText("时长");
}
