#ifndef MENU_H
#define MENU_H
#include <QWidget>
#include "cbutton.h"
#include <QPushButton>

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
private:
    //界面上的按钮
//    CButton *firstButton;//用于切换窗口
//    CButton *secondButton;//<------EMG 的按键
//    CButton *thirdButton;//<------设置按键
//    CButton *forthButton;//<------关于按键
//    void initButtons();

//    //关于对话框中的按钮
//    QPushButton *closeButton;
//    QPushButton *updateButton;

private slots:
//    //切换窗口操作
//    void changeWidget();

//    //按键
//    void forthButton_clicked();
//    void thirdButton_clicked();
//    void closeButton_clicked();
};

#endif // MENU_H
