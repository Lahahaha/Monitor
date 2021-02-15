#ifndef TRENDWIDGET_H
#define TRENDWIDGET_H
#include "buttons/trendwidgetbuttons.h"
#include <QWidget>
#include "trendwidget/showvaluewideget.h"
#include "buttons/clabels.h"
class TrendWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TrendWidget(QWidget *parent = nullptr);


private:

    //趋势中显示数值的俩窗口
    ShowValueWideget *ai;
    ShowValueWideget *emg;

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
//    CLabels *previousTrend_Amount;
//    CLabels *timeticks;
    CLabels *currentTrend;
//    CLabels *currentTrend_Num;
    CLabels *startTimeLabel;
//    CLabels *startTime;
    CLabels *lenth;
//    CLabels *lenth_Num;

signals:

};

#endif // TRENDWIDGET_H
