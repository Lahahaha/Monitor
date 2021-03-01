#include "menu.h"
//#include "widget.h"

Menu::Menu(QWidget *parent):QWidget(parent)
{

//    qDebug() << stackedwidget->currentIndex();
//    initButtons();

}

Menu::~Menu()
{
}
//void Menu::initButtons()
//{
//    //主界面菜单的四个按键
//    firstButton = new CButton(this);//<------第一个键 监视
//    secondButton = new CButton(this);//<------第二个键 趋势
//    thirdButton = new CButton(this);//<------第三个键 设置
//    forthButton = new CButton(this);//<------第四个键 关于

//    firstButton->move(10,670);
//    firstButton->setText("监测");

//    secondButton->move(65,670);
//    secondButton->setText("EMG");

//    thirdButton->move(120,670);
//    thirdButton->setText("设置");

//    forthButton->move(175,670);
//    forthButton->setText("关于");

//    connect(firstButton,&CButton::clicked,this,&Menu::changeWidget);
//    connect(secondButton,&CButton::clicked,this,&Menu::changeWidget);
//    connect(thirdButton,&CButton::clicked,this,&Menu::thirdButton_clicked);
//    connect(forthButton,&CButton::clicked,this,&Menu::forthButton_clicked);
//}



////切换窗口槽函数
//void Menu::changeWidget()
//{
//    QPushButton *button = qobject_cast<QPushButton*>(sender());
//    if(button == firstButton)
//        stackedwidget->setCurrentIndex(0);
//    else if(button == secondButton)
//        stackedwidget->setCurrentIndex(1);
//    widget2->show();
////    qDebug() << stackedwidget->currentIndex();
//}

//void Menu::thirdButton_clicked()
//{
////    qDebug() << "第三个建按下";
//}

//void Menu::forthButton_clicked()
//{
////    qDebug() << "第四个建按下";
////    aboutDialog->show();
//}

//void Menu::closeButton_clicked()
//{
////    aboutDialog->close();
//}
