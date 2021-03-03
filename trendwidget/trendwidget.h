#ifndef TRENDWIDGET_H
#define TRENDWIDGET_H

#define GRAPH_POS_X     (2)
#define GRAPH_POS_Y     (46)
#define GRAPH2_POS_X    (2)
#define GRAPH2_POS_Y    (343)
#define GRAPH_WIDTH     (662)
#define GRAPH_HIGHT     (295)
#define GRAPH2_HIGHT     (176)


#include "Com/trendwidgetbuttons.h"
#include <QWidget>
#include "trendwidget/valuewidget.h"
#include "Com/clabels.h"
#include "qcustomplot/qcustomplot.h"
class TrendWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrendWidget(QWidget *parent = nullptr);


private:

    ValueWidget *ai;
    ValueWidget *emg;

    //控制按键
    void initbuttons();
    TrendWidgetButtons *next;
    TrendWidgetButtons *previous;
    TrendWidgetButtons *left;
    TrendWidgetButtons *right;
    TrendWidgetButtons *plus;
    TrendWidgetButtons *minus;

    //参数信息
    void setlabels();
    CLabels *previousTrend;
    CLabels *currentTrend;
    CLabels *startTimeLabel;
    CLabels *lenth;

    void initcurvegraph();
    QCustomPlot *curveplot;
    QCustomPlot *curveplot2;


signals:

};

#endif // TRENDWIDGET_H
