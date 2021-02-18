#ifndef SPECTRUMGRAPH_H
#define SPECTRUMGRAPH_H

#include <QWidget>
#include "qcustomplot.h"

class SpectrumGraph : public QWidget
{
    Q_OBJECT
public:
    explicit SpectrumGraph(QWidget *parent = nullptr);

signals:
private:
    QCustomPlot *mPlot;
    void setupspectrum();//柱状图的坐标和数据
    void setposition_and_size(int x,int,int a,int b);//位置

};

#endif // SPECTRUMGRAPH_H
