#include "respgraph.h"
#include <QTimer>
RespWidget::RespWidget(QWidget *parent) : QWidget(parent)
{
    respChartInit();
    respShow();
    //定时器
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateResp()));
    timer->start(1000);
}

RespWidget::~RespWidget()
{
}
void RespWidget::respChartInit()
{
    //曲线添加到Chart中
    respChart.addSeries(&respSeries);
    respChartView.setParent(this);
    respChartView.move(0,450);
    respChartView.resize(700,150);
    //设置坐标轴
    resp_axis_X = new QValueAxis();
    resp_axis_Y = new QValueAxis();
    resp_axis_X->setRange(0,50);
    resp_axis_Y->setRange(-2,10);
    resp_axis_Y->setLineVisible(false);
    resp_axis_X->setLinePenColor(QColor(0,134,139));
    resp_axis_X->setGridLineVisible(false);
    resp_axis_Y->setGridLineVisible(false);
    //坐标轴添加到Chart中
//    respChart.setTheme(QChart::ChartThemeDark);
    respChart.addAxis(resp_axis_X,Qt::AlignBottom);
    respChart.addAxis(resp_axis_Y,Qt::AlignLeft);
    QMargins margins(0,0,0,0);
    respChart.setMargins(margins);
    respChart.setBackgroundVisible(false);
    respChart.legend()->hide();//隐藏图列
    //把曲线关联到坐标轴
    respSeries.attachAxis(resp_axis_X);
    respSeries.attachAxis(resp_axis_Y);
    respSeries.setColor(Qt::green);
    respSeries << QPoint(0,0) << QPoint(0,0)<<QPoint(0,0);//不知道为啥，没有这句话就画不了点，而且至少要三个点
    respChartView.setChart(&respChart);
//    qDebug()<<"调用呼吸初始化函数一次";
}

//呼吸频率显示
void RespWidget::respShow()
{
    //2 温度标题
    QLabel *rsNamelabel = new QLabel(this);
    rsNamelabel->setText("呼吸(RESP)");
    rsNamelabel->move(700,450+5);
    rsNamelabel->resize(150,40);
    //设置温度标题的颜色
    QPalette palette = rsNamelabel->palette();
    palette.setColor(QPalette::WindowText,Qt::yellow);
    rsNamelabel->setPalette(palette);
    QFont *namefont = new QFont;
    namefont->setPointSize(12);
    rsNamelabel->setFont(*namefont);
    //两通道温度差标签 TD
    QLabel *label = new QLabel;
    label->setParent(this);
    label->move(800,450+50);
    label->resize(100,50);
    QFont *font = new QFont;
    font->setPointSize(50);
    label->setFont(*font);
    label->setText("20");// <-----------呼吸数值显示
}

void RespWidget::updateResp()
{
    resp_amp = qrand()%10;
    resp_p.setX(resp_p.x()+1);
    resp_p.setY(resp_amp);
    //当显示范围超过 50 时动态设置 x 坐标的范围
    if(resp_p.x() >= 50){
        resp_chart_min+=1;
        resp_chart_max+=1;
        resp_axis_X->setRange(resp_chart_min,resp_chart_max);//呼吸的改变
    }
    respSeries.append(resp_p.x(),resp_p.y());
}
