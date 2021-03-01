

#include "signalqualitydialog.h"

SignalQualityDialog::SignalQualityDialog(QWidget *parent) : QDialog(parent)
{


    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去除边框
    setAttribute(Qt::WA_TranslucentBackground);
    pix.load(":/new/prefix1/Resource/Dialog/SetupDate/background.png");
    resize(pix.size());

    setModal(true);//设置为模态
    initButtons();
    initLabel();
    connect(okButton,&QPushButton::clicked,this,[=](){close();});
    connect(cancelButton,&QPushButton::clicked,this,[=](){close();});
}
void SignalQualityDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);

}

void SignalQualityDialog::initButtons()
{

    //关于对话框中的键
    okButton = new QPushButton(this);//<------Ok键，按下关闭对话框
    cancelButton = new QPushButton(this);//<-----升级键 按下输入密码
    measuringButton = new CButton(this);

    //设置关于对话框两个按键的位置
    okButton->move(100,200);
    cancelButton->move(250,200);

    okButton->resize(37,37);
    cancelButton->resize(37,37);

    measuringButton->set_button(MEASURING_BUTTON_POS_X, MEASURING_BUTTON_POS_Y);
    measuringButton->setText("手动测量");

    measuringButton->setStyleSheet("QPushButton{color:rgb(255,255,255);border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/measuring.png);}"
                                   "QPushButton:pressed{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/measuring_press.png)}");

    okButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok_d.png)}");
    cancelButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/cancel.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/cancel_d.png)}");



}

void SignalQualityDialog::initLabel()
{
    QPalette textColor;
    textColor.setColor(QPalette::WindowText, Qt::white);


    mHFLabel = new CButton(this);
    mHFLabel->set_button(HF_LABEL_POS_X, HF_LABEL_POS_Y);
    mHFLabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");


    m50HzLabel = new CButton(this);
    m50HzLabel->set_button(_50HZ_LABEL_POS_X, _50HZ_LABEL_POS_Y);
    m50HzLabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");



    mESILabel = new CButton(this);
    mESILabel->set_button(ESI_LABEL_POS_X, ESI_LABEL_POS_Y);
    mESILabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

    mSQILabel = new CButton(this);
    mSQILabel->set_button(SQI_PERCENT_LABEL_POS_X, SQI_PERCENT_LABEL_POS_Y);
    mSQILabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");


    mZ1Label = new CButton(this);
    mZ1Label->set_button(Z1_LABEL_POS_X, Z1_LABEL_POS_Y);
    mZ1Label->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

    mZ2Label = new CButton(this);
    mZ2Label->set_button(Z2_LABEL_POS_X, Z2_LABEL_POS_Y);
    mZ2Label->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");


}
