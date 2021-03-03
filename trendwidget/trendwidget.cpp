#include "trendwidget.h"
#include <QFrame>
#include <QDebug>
TrendWidget::TrendWidget(QWidget *parent) : QWidget(parent)
{
    QFrame * frame = new QFrame(this);
    frame->setObjectName("myframe");
    frame->resize(960,720);
    frame->setStyleSheet("QFrame#myframe{border-image:url(:/new/prefix1/Resource/MainWindow/background.jpg)}");
    ai = new ValueWidget(this);
    ai->setAidata();
    emg = new ValueWidget(this);
    emg->setEmgdata();
    initbuttons();
    setlabels();
    initcurvegraph();
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

void TrendWidget::initcurvegraph()
{
    curveplot = new QCustomPlot(this);
    curveplot->setGeometry(GRAPH_POS_X,GRAPH_POS_Y,GRAPH_WIDTH,GRAPH_HIGHT);
    curveplot->setBackground(QBrush(Qt::black));
    curveplot->xAxis->setVisible(false);
    curveplot->xAxis2->setVisible(true);
    curveplot->axisRect()->setAutoMargins(QCP::msNone);
    curveplot->xAxis2->grid()->setVisible(false);
    curveplot->xAxis2->setTickLabelSide(QCPAxis::lsInside);
    curveplot->xAxis2->setSubTicks(false);
    curveplot->xAxis2->setTickLabelColor(QColor(166,222,255));
    curveplot->xAxis2->setTickPen(QColor(166,222,255));

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm");
    dateTicker->setTickCount(2);
    curveplot->xAxis2->setTicker(dateTicker);

    curveplot->yAxis->grid()->setVisible(false);
    curveplot->yAxis->setSubTicks(false);
    curveplot->yAxis->setRange(0,100);
    curveplot->yAxis->setTickLabelColor(QColor(166,222,255));
    curveplot->yAxis->setTickPen(QColor(166,222,255));



    curveplot2 = new QCustomPlot(this);
    curveplot2->setGeometry(GRAPH2_POS_X,GRAPH2_POS_Y,GRAPH_WIDTH,GRAPH2_HIGHT);
    curveplot2->setBackground(QBrush(Qt::black));
    curveplot2->xAxis->setVisible(false);
    curveplot2->axisRect()->setAutoMargins(QCP::msNone);
    curveplot2->xAxis->grid()->setVisible(false);

    curveplot2->yAxis->grid()->setVisible(false);
    curveplot2->yAxis->setTickLabelSide(QCPAxis::lsInside);
    curveplot2->yAxis->setRange(0,100);
    curveplot2->yAxis->setTickPen(QColor(166,222,255));
    curveplot->yAxis->setTickLabelColor(QColor(166,222,255));

}
