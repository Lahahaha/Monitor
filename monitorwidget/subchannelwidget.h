#ifndef SUBCHANNELWIDGET_H
#define SUBCHANNELWIDGET_H

#include <QWidget>
#include <QLabel>

class SubChannelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubChannelWidget(QWidget *parent = nullptr);
    ~SubChannelWidget();
signals:
private:

    QLabel *srNum;
    void infoInit();//设置子窗口标签

};

#endif // SUBCHANNELWIDGET_H
