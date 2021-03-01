#ifndef CURVEGRAPH2_H
#define CURVEGRAPH2_H

#include <QWidget>
#include "qcustomplot/qcustomplot.h"
class CurveGraph2 : public QWidget
{
    Q_OBJECT
public:
    explicit CurveGraph2(QWidget *parent = nullptr);    

signals:

private slots:
  void timerSlot();//准备曲线数据

private:
  QCustomPlot *mPlot;
  QPointer<QCPGraph> mGraph;
  QTimer mDataTimer;
  void setposition_and_size(int x,int,int a,int b);//设置绘制位置和大小
};

#endif // CURVEGRAPH2_H
