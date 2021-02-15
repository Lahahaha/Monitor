

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
//    mHFLabel->setButtonLabel("HF(dB)" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mHFLabel->setButtonTextSize(25*SCALE_VALUE);
//    mHFLabel->set_click_enable(false);

    m50HzLabel = new CButton(this);
    m50HzLabel->set_button(_50HZ_LABEL_POS_X, _50HZ_LABEL_POS_Y);
    m50HzLabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

//    m50HzLabel->setButtonLabel("50Hz(dB)" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    m50HzLabel->setButtonTextSize(25*SCALE_VALUE);
//    m50HzLabel->set_click_enable(false);

    mESILabel = new CButton(this);
    mESILabel->set_button(ESI_LABEL_POS_X, ESI_LABEL_POS_Y);
    mESILabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

//    mESILabel->setButtonLabel("ESI(dB)" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mESILabel->setButtonTextSize(25*SCALE_VALUE);
//    mESILabel->set_click_enable(false);

    mSQILabel = new CButton(this);
    mSQILabel->set_button(SQI_PERCENT_LABEL_POS_X, SQI_PERCENT_LABEL_POS_Y);
    mSQILabel->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

//    mSQILabel->setButtonLabel("SQI(%)" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mSQILabel->setButtonTextSize(25*SCALE_VALUE);
//    mSQILabel->set_click_enable(false);

    mZ1Label = new CButton(this);
    mZ1Label->set_button(Z1_LABEL_POS_X, Z1_LABEL_POS_Y);
    mZ1Label->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

//    mZ1Label->setButtonLabel("Z1" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mZ1Label->setButtonTextSize(25*SCALE_VALUE);
//    mZ1Label->set_click_enable(false);

    mZ2Label = new CButton(this);
    mZ2Label->set_button(Z2_LABEL_POS_X, Z2_LABEL_POS_Y);
    mZ2Label->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

//    mZ2Label->setButtonLabel("Z2" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mZ2Label->setButtonTextSize(25*SCALE_VALUE);
//    mZ2Label->set_click_enable(false);

    mZ3Label = new CButton(this);
    mZ3Label->set_button(Z3_LABEL_POS_X, Z3_LABEL_POS_Y);
    mZ3Label->setStyleSheet("QPushButton{border-image: url(:/SignalQualityWidget/Resource/SignalQualityWidget/label_background.png)}");

//    mZ3Label->setButtonLabel("Z3" + LABEL_OFFSET_SPACE,
//                             LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mZ3Label->setButtonTextSize(25*SCALE_VALUE);
//    mZ3Label->set_click_enable(false);


//    mHFLabelData = new QLabel(mHFLabel);
//    mHFLabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                              LABEL_DATA_POS_Y*SCALE_VALUE,
//                              LABEL_DATA_WIDTH*SCALE_VALUE,
//                              LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mHFLabelData->setText("0");
//    mHFLabelData->setFont(textFont);
//    mHFLabelData->setPalette(textColor);
//    mHFLabelData->setAlignment(Qt::AlignCenter);
//    mHFLabelData->show();

//    m50HzLabelData = new QLabel(m50HzLabel);
//    m50HzLabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                                LABEL_DATA_POS_Y*SCALE_VALUE,
//                                LABEL_DATA_WIDTH*SCALE_VALUE,
//                                LABEL_DATA_HEIGHT*SCALE_VALUE);
//    m50HzLabelData->setText("0");
//    m50HzLabelData->setFont(textFont);
//    m50HzLabelData->setPalette(textColor);
//    m50HzLabelData->setAlignment(Qt::AlignCenter);
//    m50HzLabelData->show();

//    mESILabelData = new QLabel(mESILabel);
//    mESILabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                               LABEL_DATA_POS_Y*SCALE_VALUE,
//                               LABEL_DATA_WIDTH*SCALE_VALUE,
//                               LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mESILabelData->setText("0");
//    mESILabelData->setFont(textFont);
//    mESILabelData->setPalette(textColor);
//    mESILabelData->setAlignment(Qt::AlignCenter);
//    mESILabelData->show();

//    mSQILabelData = new QLabel(mSQILabel);
//    mSQILabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                               LABEL_DATA_POS_Y*SCALE_VALUE,
//                               LABEL_DATA_WIDTH*SCALE_VALUE,
//                               LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mSQILabelData->setText("0");
//    mSQILabelData->setFont(textFont);
//    mSQILabelData->setPalette(textColor);
//    mSQILabelData->setAlignment(Qt::AlignCenter);
//    mSQILabelData->show();

//    mZ1LabelData = new QLabel(mZ1Label);
//    mZ1LabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                              LABEL_DATA_POS_Y*SCALE_VALUE,
//                              LABEL_DATA_WIDTH*SCALE_VALUE,
//                              LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mZ1LabelData->setText("0");
//    mZ1LabelData->setFont(textFont);
//    mZ1LabelData->setPalette(textColor);
//    mZ1LabelData->setAlignment(Qt::AlignCenter);
//    mZ1LabelData->show();

//    mZ2LabelData = new QLabel(mZ2Label);
//    mZ2LabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                              LABEL_DATA_POS_Y*SCALE_VALUE,
//                              LABEL_DATA_WIDTH*SCALE_VALUE,
//                              LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mZ2LabelData->setText("0");
//    mZ2LabelData->setFont(textFont);
//    mZ2LabelData->setPalette(textColor);
//    mZ2LabelData->setAlignment(Qt::AlignCenter);
//    mZ2LabelData->show();

//    mZ3LabelData = new QLabel(mZ3Label);
//    mZ3LabelData->setGeometry(LABEL_DATA_POS_X*SCALE_VALUE,
//                              LABEL_DATA_POS_Y*SCALE_VALUE,
//                              LABEL_DATA_WIDTH*SCALE_VALUE,
//                              LABEL_DATA_HEIGHT*SCALE_VALUE);
//    mZ3LabelData->setText("0");
//    mZ3LabelData->setFont(textFont);
//    mZ3LabelData->setPalette(textColor);
//    mZ3LabelData->setAlignment(Qt::AlignCenter);
//    mZ3LabelData->show();
}
