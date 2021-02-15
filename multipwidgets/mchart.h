#ifndef MCHART_H
#define MCHART_H

#include <QWidget>
#include <QtCharts/QLineSeries>
#include <QChartView>
#include <QValueAxis>

using namespace QtCharts;

class MyChart : public QWidget
{
    Q_OBJECT
public:
    explicit MyChart(QWidget *parent = nullptr);

private:
    QChart chart;
    QChartView chartview;

    void chartInit();


signals:

};

#endif // MCHART_H
