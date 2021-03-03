#include "curvegraph.h"


CurveGraph::CurveGraph(QWidget *parent) : QWidget(parent),mPlot(0)
{

    mPlot = new QCustomPlot(this);
    setposition_and_size(2,51,596,276);
    mPlot->axisRect()->setAutoMargins(QCP::msNone);

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("hh:mm");
    dateTicker->setTickCount(2);
    mPlot->xAxis2->setTicker(dateTicker);

    QColor mcolor1 = QColor(166,222,255);
    mPlot->setBackground(QColor(20,20,20));
    mPlot->xAxis2->setTickPen(mcolor1);
    mPlot->xAxis2->setTickLabelColor(mcolor1);
    mPlot->xAxis2->setVisible(true);
    mPlot->xAxis2->setTickLabelSide(QCPAxis::LabelSide::lsInside);
    mPlot->xAxis->grid()->setVisible(false);
    mPlot->xAxis2->setSubTicks(false);

    mPlot->yAxis->setTickPen(mcolor1);
    mPlot->yAxis->setTickLabelColor(mcolor1);
    mPlot->yAxis->setTickLabelSide(QCPAxis::LabelSide::lsInside);
    mPlot->yAxis->setRange(0,100);
    mPlot->yAxis->grid()->setVisible(false);
    mPlot->yAxis->setSubTicks(false);



     // create graphs:
     mGraph = mPlot->addGraph(mPlot->xAxis2, mPlot->yAxis /*axisRect()->axis(QCPAxis::atLeft, 0)*/);
     mGraph->setPen(QPen(Qt::red));
     connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
     mDataTimer.start(20);




}
void CurveGraph::setposition_and_size(int x=2,int y=51,int a=579,int b=276)
{
//    2,51 579,276
    mPlot->move(x,y);
    mPlot->resize(a,b);

}
void CurveGraph::timerSlot()
{
  // calculate and add a new data point to each graph:
  mGraph->addData(mGraph->dataCount(), 50+40*qSin(mGraph->dataCount()/50.0)+40*qSin(mGraph->dataCount()/50.0/0.3843)*0.25);

  // make key axis range scroll with the data:
  mPlot->xAxis2->rescale();
//  mGraph->rescaleValueAxis(false, true);
  mPlot->xAxis2->setRange(mPlot->xAxis2->range().upper, 1000, Qt::AlignRight);

  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:

  mPlot->replot();
}

