#ifndef RESPWIDGET_H
#define RESPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QtCharts/QLineSeries>
#include <QPointF>
#include <QChartView>
#include <QValueAxis>

using namespace QtCharts;

class RespWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RespWidget(QWidget *parent = nullptr);
    ~RespWidget();
signals:

private slots:
    void updateResp();

private:
    int resp_chart_min = 0;
    int resp_chart_max = 50;//chart 中 x 坐标的最大值

    float resp_amp = 0;
    QPointF resp_p;

    QLineSeries respSeries;//曲线
    QChart respChart;
    QChartView respChartView;
    QValueAxis *resp_axis_X;
    QValueAxis *resp_axis_Y;
    void respChartInit();
    void respShow();


};

#endif // RESPWIDGET_H
