#include "aboutdialog.h"
#include <QLabel>

AboutDialog::AboutDialog(QWidget *parent):
    QDialog(parent)
{

    pix.load(":/new/prefix1/Resource/Dialog/SetupDate/background.png");
    this->resize(pix.size());
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//去除边框
    this->setAttribute(Qt::WA_TranslucentBackground);//透明

//    //设置背景
//    QFrame * frame = new QFrame(this);
//    frame->setObjectName("myframe");
//    frame->resize(350,250);
//    frame->setStyleSheet("QFrame#myframe{border-image:url(:/new/prefix1/Resource/Dialog/SetupDate/background.png)}");
    aboutDialogInit();
    initDialogButtons();
    connect(closeButton,&QPushButton::clicked,this,&AboutDialog::closeButton_clicked);
    connect(updateButton,&QPushButton::clicked,this,&AboutDialog::updateButton_clicked);
}
AboutDialog::~AboutDialog()
{
}

void AboutDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
//初始化关于对话框及其按键
void AboutDialog::aboutDialogInit()
{
    QLabel *label1 = new QLabel(this);
    QLabel *label2 = new QLabel(this);
    label1->setStyleSheet("QLabel{color:white }");
    label2->setStyleSheet("QLabel{color:white}");
    label1->setText("系统软件版本:");
    label2->setText("2020.11.11");
    label1->move(60,70);
    label2->move(110,110);
    this->setModal(true);
}
//按下之后弹出升级对话框输入密码
void AboutDialog::updateButton_clicked()
{
    QDialog *passwDialog = new QDialog(this);//<-----输入密码界面
    passwDialog->resize(200,100);
    passwDialog->setModal(true);
    passwLineEdit = new QLineEdit(passwDialog);//<-----输入密码文本框
    passwLineEdit->resize(100,20);
    passwLineEdit->move(40,20);
    passwDialog->show();
}
void AboutDialog::initDialogButtons()
{
    //关于对话框中的键
    closeButton = new QPushButton(this);//<------Ok键，按下关闭对话框
    updateButton = new QPushButton(this);//<-----升级键 按下输入密码
    //设置关于对话框两个按键的位置
    updateButton->move(100,200);
    closeButton->move(250,200);
    updateButton->resize(80,37);
    closeButton->resize(37,37);
    updateButton->setText("升级");
    updateButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/About/button.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/About/button_d.png)}"
                                "QPushButton{color:rgb(255, 255, 255)}");
    closeButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok_d.png)}");
}
void AboutDialog::closeButton_clicked()
{
    close();
}
