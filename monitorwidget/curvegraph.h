#ifndef CURVEGRAPH_H
#define CURVEGRAPH_H

#include <QWidget>
#include "qcustomplot.h"
class CurveGraph : public QWidget
{
    Q_OBJECT
public:
    explicit CurveGraph(QWidget *parent = nullptr);


signals:

private slots:
    void timerSlot();//准备曲线数据

private:    
    QCustomPlot *mPlot;
    QPointer<QCPGraph> mGraph;
    QTimer mDataTimer;
    void setposition_and_size(int x,int,int a,int b);//设置绘制位置和大小
};

#endif // CURVEGRAPH_H
