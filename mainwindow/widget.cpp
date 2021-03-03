#include "widget.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QLayout>
#include <QPalette>
#include <QFont>
#include <QPainter>
#include <QDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    DataManager *por = new DataManager;
//    addWidgets();



//添加界面元素
    monitor = new MonitorWidget(this);
    aboutDialog = new AboutDialog(this);
    sqlDialog = new SignalQualityDialog(this);
    setupwidget = new SetupWidget(this);
    trend = new TrendWidget(this);
    trend->hide();
//    SYSTEM_POWER_STATUS systemPowerSatus;
//    GetSystemPowerStatus(&systemPowerSatus);
//    int remaindPower=(int)systemPowerSatus.BatteryLifePercent;
   initLayout();
   initButtons();
   s = new StatusBar(this);
}

Widget::~Widget()
{
}


//绘制框架
void Widget::paintEvent(QPaintEvent *)
{
    QPainter paint;
    paint.begin(this);
    QRectF rectangle(1, 1, 958, 618);
    paint.setPen(QPen(QColor(166, 222, 255), 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    paint.drawRect(rectangle);//<------画一个矩形框
    paint.drawLine(0, 50, 960, 50);//<------方框内第一条直线，起始点y=50
    paint.drawLine(0, 328, 960, 328);//<------方框内第二条直线，起始点y2=y3-150=498-170=328
    paint.drawLine(0, 498, 960, 498);//<------方框内第三条直线，起始点y3=618-120=498
    paint.drawLine(600, 50, 600, 498);//<------方框内的垂直线，起始点y4=960-360=600
    paint.end();
}

//设置widget默认颜色
void Widget::initLayout()
{

//    获取容器的调色板
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::black);
    palette.setColor(QPalette::WindowText,Qt::white);
    this->setPalette(palette);
//    qDebug()<<"初始化Widget";
}

//按键
void Widget::initButtons()
{
    firstButton = new CButton(this);
    secondButton = new CButton(this);
    thirdButton = new CButton(this);
    forthButton = new CButton(this);
    trendButton = new CButton(this);
    sqlButton = new CButton(this);
    quiet = new CButton(this);
    volumeButton = new CButton(this);
    battery = new CButton(this);

    firstButton->move(0,640);
    firstButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/home.png)}");

    secondButton->move(96,640);
    secondButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/monitoring.png)}"
                              "QPushButton:checked{border-image: url(:/new/prefix1/Resource/MainWindow/1/monitoring_press.png)}");
    secondButton->setChecked(true);

    trendButton->move(192,640);
    trendButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/trend.png)}"
                              "QPushButton:checked{border-image: url(:/new/prefix1/Resource/MainWindow/1/trend_press.png)}");

    thirdButton->move(288,640);
    thirdButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/setup.png)}"
                              "QPushButton:checked{border-image: url(:/new/prefix1/Resource/MainWindow/1/setup_press.png)}");

    sqlButton->move(384,640);
    sqlButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/signalquality.png)}"
                              "QPushButton:checked{border-image: url(:/new/prefix1/Resource/MainWindow/1/signalquality_press.png)}");

    forthButton->move(480,640);
    forthButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/help_about.png)}"
                              "QPushButton:checked{border-image: url(:/new/prefix1/Resource/MainWindow/1/help_about_d.png)}");


    volumeButton->move(864,640);
    volumeButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/volunme.png)}");
    volumeButton->setCheckable(false);
    quiet->move(864,640);
    quiet->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/1/quiet.png)}");
    quiet->setCheckable(false);

    battery->move(680,640);
    battery->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/MainWindow/power_5.png)}");

    connect(firstButton,&CButton::clicked,this,&Widget::changeWidget);
    connect(secondButton,&CButton::clicked,this,&Widget::changeWidget);
    connect(trendButton,&CButton::clicked,this,&Widget::changeWidget);

    connect(thirdButton,&CButton::clicked,this,&Widget::thirdButton_clicked);
    connect(forthButton,&CButton::clicked,this,&Widget::forthButton_clicked);
    connect(sqlButton,&CButton::clicked,this,[=](){sqlDialog->show();});

    connect(volumeButton,&CButton::clicked,this,&Widget::slot_button1_clicked);
    connect(quiet,&CButton::clicked,this,&Widget::slot_button2_clicked);

}

//窗口切换
void Widget::changeWidget()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button == firstButton)
    {
//        stackedwidget->setCurrentIndex(1);
    }
    else if(button == secondButton)
    {
//        stackedwidget->setCurrentIndex(0);
        monitor->show();
        trend->hide();
    }
    else if(button == trendButton)
    {
//        stackedwidget->setCurrentIndex(2);
        trend->show();
        monitor->hide();
    }
}

void Widget::thirdButton_clicked()
{
    setupwidget->show();
}

void Widget::forthButton_clicked()
{
    aboutDialog->show();
}

void Widget::slot_button1_clicked()
{
    volumeButton->hide();
    quiet->show();
}

void Widget::slot_button2_clicked()
{
    volumeButton->show();
    quiet->hide();
}
