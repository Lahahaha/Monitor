#ifndef WIDGET_H
#define WIDGET_H

#include "statusbar/statsbar.h"
#include "Com/cbutton.h"
#include "aboutwidget/aboutdialog.h"
#include "signalqualitydialog/signalqualitydialog.h"
#include "trendwidget/trendwidget.h"
#include "setupwidget/setupwidget.h"
#include "monitorwidget/monitorwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //各个模块
    StatusBar *s;

    MonitorWidget *monitor;
    AboutDialog *aboutDialog;
    SignalQualityDialog *sqlDialog;
    TrendWidget *trend;
    SetupWidget *setupwidget;




protected:
    void paintEvent(QPaintEvent *event);//<----------绘图事件

private:
    CButton *firstButton;//用于切换窗口
    CButton *secondButton;//<------检测
    CButton *thirdButton;//<------设置按键
    CButton *forthButton;//<------关于按键
    CButton *trendButton;//<------趋势
    CButton *sqlButton;//<------信号质量
    CButton *volumeButton;//声音
    CButton *quiet;

    CButton *battery;
    void initButtons();

    //“关于”对话框中的按键
    QPushButton *closeButton;
    QPushButton *updateButton;

    QLabel *timeLabel;

    void initLayout();//全局颜色

public slots:

    //切换窗口
    void changeWidget();

    //按键槽函数
    void forthButton_clicked();
    void thirdButton_clicked();
    void slot_button1_clicked();
    void slot_button2_clicked();


};
#endif // WIDGET_H
