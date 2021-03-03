#include "mainwindow/widget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
//    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));//激活虚拟键盘键盘
    QApplication a(argc, argv);

    Widget w;
    w.resize(960,720);
    w.show();
    return a.exec();
}
