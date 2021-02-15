#include "spo2widget.h"
Spo2Widget::Spo2Widget(QWidget *parent) : QWidget(parent)
{
    bpChartInit();
    init_SpO2Info();
}
Spo2Widget::~Spo2Widget()
{
}

void Spo2Widget::bpChartInit()
{
    //曲线添加到Chart中
    bpChart.addSeries(&bpSeries);
    bpChartView.setParent(this);
    bpChartView.move(0,150);
    bpChartView.resize(700,150);
    //设置坐标轴
    bp_axis_X = new QValueAxis();
    bp_axis_Y = new QValueAxis();
    bp_axis_X->setRange(0,50);
    bp_axis_Y->setRange(-2,10);
    bp_axis_X->setGridLineVisible(false);
    bp_axis_Y->setGridLineVisible(false);
    bp_axis_Y->setLineVisible(false);
    bp_axis_X->setLinePenColor(QColor(0,134,139));
    //坐标轴添加到Chart中
    bpChart.addAxis(bp_axis_X,Qt::AlignBottom);
    bpChart.addAxis(bp_axis_Y,Qt::AlignLeft);
    bpChart.legend()->hide();//隐藏图列
    QMargins margins(0,0,0,0);
    bpChart.setMargins(margins);
    bpChart.setBackgroundVisible(false);
    //把曲线关联到坐标轴
    bpSeries.attachAxis(bp_axis_X);
    bpSeries.attachAxis(bp_axis_Y);
    bpSeries.setColor(Qt::green);
    bpSeries << QPoint(0,0) << QPoint(0,0)<<QPoint(0,0);//不知道为啥，没有这句话就画不了点，而且至少要三个点
    bpChartView.setChart(&bpChart);
}
void Spo2Widget::init_SpO2Info()
{
    //添加 Label
    bpLabel = new QLabel;
    bpLabel->setParent(this);
    bpLabel->move(810,150+70);
    bpLabel->resize(110,75);
    //1 数值标签中的字体
    QFont *font = new QFont;
    font->setPointSize(55);
    bpLabel->setFont(*font);
    bpLabel->setText("100");
    //2 血氧饱和度名称标签
    QLabel *namelabel = new QLabel(this);
    namelabel->setText("血氧饱和度(SpO2)");
    namelabel->move(700,150+5);
    namelabel->resize(150,40);
    QPalette palette = namelabel->palette();
    palette.setColor(QPalette::WindowText,Qt::green);
    namelabel->setPalette(palette);
    QFont *namefont = new QFont;
    namefont->setPointSize(12);
    namelabel->setFont(*namefont);
    //3 单位标签
    QLabel *unitlabel = new QLabel(this);
    unitlabel->setText("%");
    unitlabel->move(925,150+105);
    unitlabel->resize(80,40);
    QPalette unitpalette = unitlabel->palette();
    unitpalette.setColor(QPalette::WindowText,Qt::white);
    unitlabel->setPalette(unitpalette);
    QFont *unitfont = new QFont;
    unitfont->setPointSize(12);
    unitlabel->setFont(*unitfont);
}

void Spo2Widget::updateBp()
{
    bp_amp = qrand()%10;
    bp_p.setX(bp_p.x()+1);
    bp_p.setY(bp_amp);
    //当显示范围超过 50 时动态设置 x 坐标的范围
    if(bp_p.x() >= 50){
        bp_chart_min+=1;
        bp_chart_max+=1;
        bp_axis_X->setRange(bp_chart_min,bp_chart_max);//脉搏的改变
    }
    bpSeries.append(bp_p.x(),bp_p.y());
}
