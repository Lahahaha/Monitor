#include "setupwidget.h"
#include <QFrame>
#include <QDebug>

SetupWidget::SetupWidget(QWidget *parent) : QDialog(parent)
{
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去除边框
    setAttribute(Qt::WA_TranslucentBackground);
    pix.load(":/new/prefix1/Resource/Dialog/SetupDate/background.png");
    resize(pix.size());
    setStyleSheet("color:rgb(255,255,255)");
    mTimer = new QTimer(this);
    mTimer->start(1000);

    setModal(true);//设置为模态
    initButtons();
    initlabels();
    connect(okButton,&QPushButton::clicked,this,&SetupWidget::okButton_clicked);
    connect(cancelButton,&QPushButton::clicked,this,&SetupWidget::cancelButton_clicked);
    connect(mTimer,&QTimer::timeout,this,[=](){
        QDateTime datetime = QDateTime::currentDateTime();
        mTimeLabel->setText(datetime.toString("yyyy/MM/dd hh:mm"));
    });
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
    okButton->move(30,200);
    cancelButton->move(280,200);

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

    mUpperThresholdLabel = new CButton(this);
    mLowerThresholdLabel = new CButton(this);
    mTimeLabel = new CButton(this);

    mHFButton->move(HF_BUTTON_POS_X,SWITCH_BUTTON_Y);
    mHFButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/hf_button.png);}");
    mHFButton->setId(SetupWidget::HF);
    mHFButton->setText("HF");
    mHFButton->setimages(":/new/prefix1/Resource/SetupWidget/hf_button.png",
                         ":/new/prefix1/Resource/SetupWidget/button_press.png");

    m50HzButton->move(_50HZ_BUTTON_POS_X,SWITCH_BUTTON_Y);
    m50HzButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/_50hz_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    m50HzButton->setText("50Hz");
    m50HzButton->setId(SetupWidget::_50Hz);


    mSRButton->move(SR_BUTTON_POS_X,SWITCH_BUTTON_Y);

    mSRButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/sr_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    mSRButton->setText("SR");
    mSRButton->setId(SetupWidget::SR);


    mSQIButton->move(SQI_BUTTON_POS_X,SWITCH_BUTTON_Y);
    mSQIButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/sqi_button.png);}"
                             "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/button_press.png)}");
    mSQIButton->setText("SQI");
    mSQIButton->setId(SetupWidget::SQI);

    connect(mHFButton,SIGNAL(mSignal(int)),this,SLOT(slotSwitch(int)));
    connect(m50HzButton,SIGNAL(mSignal(int)),this,SLOT(slotSwitch(int)));
    connect(mSRButton,SIGNAL(mSignal(int)),this,SLOT(slotSwitch(int)));
    connect(mSQIButton,SIGNAL(mSignal(int)),this,SLOT(slotSwitch(int)));

    mGraphLabel->set_button(30,50);
    mGraphLabel->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button.png);}"
                               "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button_press.png)}");
    mGraphLabel->setText("图像       ");

    mTimeLabel->set_button(TIME_BUTTON_POS_X,SWITCH_BUTTON_Y,120,40);
    mTimeLabel->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/time_button.png)}");



    mUpperThresholdLabel->set_button(THRESHOLD_POS_X,UPPER_POS_Y);
    mUpperThresholdLabel->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button.png);}"
                               "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button_press.png)}");
    mUpperThresholdLabel->setText("AI上限       ");

    mLowerThresholdLabel->set_button(THRESHOLD_POS_X,LOWER_POS_Y);
    mLowerThresholdLabel->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button.png);}"
                                        "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/SetupWidget/label_button_press.png)}");
    mLowerThresholdLabel->setText("AI下限       ");


}
void SetupWidget::slotSwitch(int id)
{
    switch (id){
    case SetupWidget::HF:
        qDebug()<<"HF";
        break;
    case SetupWidget::_50Hz:
        qDebug()<<"50Hz";
        break;
    case SetupWidget::SR:
        qDebug()<<"SR";
        break;
    case SetupWidget::SQI:
        qDebug()<<"SQI";
    default:
        break;
    }

}
