#include "setupwidget.h"
#include <QFrame>

SetupWidget::SetupWidget(QWidget *parent) : QDialog(parent)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去除边框
    setAttribute(Qt::WA_TranslucentBackground);
    pix.load(":/new/prefix1/Resource/Dialog/SetupDate/background.png");
    resize(pix.size());

    setModal(true);//设置为模态
    initButtons();
    initlabels();
    connect(okButton,&QPushButton::clicked,this,&SetupWidget::okButton_clicked);
    connect(cancelButton,&QPushButton::clicked,this,&SetupWidget::cancelButton_clicked);

}

void SetupWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);

}
void SetupWidget::okButton_clicked()
{
    close();
}

void SetupWidget::cancelButton_clicked()
{
    close();
}
void SetupWidget::initButtons()
{

    //关于对话框中的键
    okButton = new QPushButton(this);//<------Ok键，按下关闭对话框
    cancelButton = new QPushButton(this);//<-----升级键 按下输入密码

    //设置关于对话框两个按键的位置
    okButton->move(100,200);
    cancelButton->move(250,200);

    okButton->resize(37,37);
    cancelButton->resize(37,37);

    okButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok_d.png)}");
    cancelButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/cancel.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/cancel_d.png)}");

}

void SetupWidget::initlabels()
{
    mHFButton = new CSwitch(this);
    m50HzButton = new CSwitch(this);
    mSRButton = new CSwitch(this);
    mSQIButton = new CSwitch(this);
    mGraphLabel = new CButton(this);

    mHFButton->move(HF_BUTTON_POS_X,140);
    mHFButton->setStyleSheet("QPushButton{color:rgb(255,255,255);border-image: url(:/new/prefix1/Resource/SetupWidget/hf_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    mHFButton->setText("HF");

    m50HzButton->move(_50HZ_BUTTON_POS_X,140);
    m50HzButton->setStyleSheet("QPushButton{color:rgb(255,255,255);border-image: url(:/new/prefix1/Resource/SetupWidget/_50hz_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    m50HzButton->setText("50HZ");

    mSRButton->move(SR_BUTTON_POS_X,140);

    mSRButton->setStyleSheet("QPushButton{color:rgb(255,255,255);border-image: url(:/new/prefix1/Resource/SetupWidget/sr_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    mSRButton->setText("SR");

    mSQIButton->move(SQI_BUTTON_POS_X,140);
    mSQIButton->setStyleSheet("QPushButton{color:rgb(255,255,255);border-image: url(:/new/prefix1/Resource/SetupWidget/sqi_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    mSQIButton->setText("SQI");

    mGraphLabel->set_button(30,60);
    mGraphLabel->setStyleSheet("QPushButton{color:rgb(255,255,255);border-image: url(:/new/prefix1/Resource/SetupWidget/label_button.png);}"
                               "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button_press.png)}");
    mGraphLabel->setText("图像       ");
}
