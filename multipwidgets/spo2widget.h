#ifndef SPO2WIDGET_H
#define SPO2WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QtCharts/QLineSeries>
#include <QPointF>
#include <QChartView>
#include <QValueAxis>

using namespace QtCharts;

class Spo2Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Spo2Widget(QWidget *parent = nullptr);
    ~Spo2Widget();
signals:
public slots:
    void updateBp();

private:

    QLineSeries bpSeries;//曲线
    QChart bpChart;
    QChartView bpChartView;
    QValueAxis *bp_axis_X;
    QValueAxis *bp_axis_Y;

    QLabel *bpLabel;

    int bp_chart_min = 0;
    int bp_chart_max = 50;//chart 中 x 坐标的最大值
    float bp_amp = 0;
    QPointF bp_p;//坐标点

    void bpChartInit();
    void init_SpO2Info();

};

#endif // SPO2WIDGET_H
