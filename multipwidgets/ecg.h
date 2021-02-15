#ifndef ECGWIDGET_H
#define ECGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QtCharts/QLineSeries>
#include <QPointF>
#include <QChartView>
#include <QValueAxis>
//#include "mchart.h"

using namespace QtCharts;

class EcgWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EcgWidget(QWidget *parent = nullptr);
    ~EcgWidget();
signals:
public slots:
    void updateEcg();
private:
        QLabel *ecgLable;
        void ecgChartInit();


        //心电的一系列对象
        QLineSeries series;//曲线
        QPointF p;//坐标点
        QChart chart;
        QChartView chartview;
        QValueAxis *axis_X;
        QValueAxis *axis_Y;

        int i = 0;
        int max = 50;//chart 中 x 坐标的最大值

        float amp = 0;

};

#endif // ECGWIDGET_H
