#include "ecg.h"
#include <QTimer>

EcgWidget::EcgWidget(QWidget *parent) : QWidget(parent)
{
    ecgChartInit();

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateEcg()));
    timer->start(1000);
}
EcgWidget::~EcgWidget(){

}
void EcgWidget::ecgChartInit()
{
    //曲线添加到Chart中
    chart.addSeries(&series);
    chartview.setParent(this);
    chartview.move(3,3);
    chartview.resize(697,147);
    QLabel *lengend = new QLabel(&chartview);
    lengend->setText("ECG");


    //设置坐标轴
    axis_X = new QValueAxis();
    axis_Y = new QValueAxis();
    axis_X->setRange(0,50);
    axis_Y->setRange(-2,10);

    axis_X->setGridLineVisible(false);
    axis_Y->setGridLineVisible(false);

    axis_Y->setLineVisible(false);
    axis_X->setLinePenColor(QColor(0,134,139));


    //坐标轴添加到Chart中
    chart.addAxis(axis_X,Qt::AlignBottom);
    chart.addAxis(axis_Y,Qt::AlignLeft);

    QMargins margins(0,0,0,0);
    chart.setMargins(margins);
    chart.setBackgroundVisible(false);
    chart.legend()->hide();//隐藏图列


    //把曲线关联到坐标轴
    series.attachAxis(axis_X);
    series.attachAxis(axis_Y);
    series.setColor(Qt::red);
    series << QPoint(0,0) << QPoint(0,0)<<QPoint(0,0);//不知道为啥，没有这句话就画不了点，而且至少要三个点

    chartview.setChart(&chart);

}



void EcgWidget::updateEcg()
{

    amp = qrand()%9;

    p.setX(p.x()+1);
    p.setY(amp);

    //当显示范围超过 50 时动态设置 x 坐标的范围
    if(p.x() >= 50){
        i+=1;
        max+=1;
       axis_X->setRange(i,max);//心电的改变

    }
    series.append(p.x(),p.y());

}
