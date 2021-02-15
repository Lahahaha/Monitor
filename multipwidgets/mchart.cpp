#include "mchart.h"

MyChart::MyChart(QWidget *parent) : QWidget(parent)
{

}

void MyChart::chartInit()
{
    //曲线添加到Chart中

    chartview.setParent(this);
    chartview.resize(697,147);

    QMargins margins(0,0,0,0);
    chart.setMargins(margins);
    chart.setBackgroundVisible(false);
    chart.legend()->hide();//隐藏图列


    //把曲线关联到坐标轴


    chartview.setChart(&chart);

}
