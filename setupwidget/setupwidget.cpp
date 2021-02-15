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

//    okButton->setText("OK");
//    cancelButton->setText("Cancel");
    okButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/ok_d.png)}");
    cancelButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/cancel.png)}"
                              "QPushButton:pressed{border-image: url(:/new/prefix1/Resource/Dialog/SetupDate/cancel_d.png)}");

}
