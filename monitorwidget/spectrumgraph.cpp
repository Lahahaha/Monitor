#include "spectrumgraph.h"

SpectrumGraph::SpectrumGraph(QWidget *parent) : QWidget(parent)
{
    mPlot = new QCustomPlot(this);
    setposition_and_size(2,500,956,118);
    setupspectrum();
}

void SpectrumGraph::setupspectrum()
{
    //设置坐标
    QColor mcolor1 = QColor(166,222,255);
    mPlot->setBackground(QColor(20,20,20));
    mPlot->yAxis->setTickPen(mcolor1);
    mPlot->yAxis->setTickLabelColor(mcolor1);
    mPlot->yAxis->setTickLabelSide(QCPAxis::LabelSide::lsInside);
    mPlot->axisRect()->setAutoMargins(QCP::msNone);
    mPlot->yAxis->setRange(-200,200);
    mPlot->xAxis->grid()->setVisible(false);

    //准备数据
    QVector<QCPGraphData> dataRandom(100);
    for (int i=0; i<dataRandom.size(); ++i)
    {
      dataRandom[i].key = i/(double)dataRandom.size()*10;
      dataRandom[i].value = (qrand()/(double)RAND_MAX-2*dataRandom[qMax(0, i-1)].value)*0.6;
    }

    QCPAxisRect *mRect = new QCPAxisRect(mPlot, false);
    QCPGraph *graphRandom = mPlot->addGraph(mRect->axis(QCPAxis::atBottom), mRect->axis(QCPAxis::atLeft));
    graphRandom->data()->set(dataRandom);
    graphRandom->setLineStyle(QCPGraph::lsImpulse);
    graphRandom->setPen(QPen(QColor("#FFA100"), 1.5));
//    graphRandom->rescaleAxes();
}

void SpectrumGraph::setposition_and_size(int x=2,int y=51,int a=579,int b=276)
{
//    2,51 579,276
    mPlot->move(x,y);
    mPlot->resize(a,b);
}
