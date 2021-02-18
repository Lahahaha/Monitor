#ifndef MAINCHANNELWIDGET_H
#define MAINCHANNELWIDGET_H

#include <QWidget>
#include <QLabel>

class MainChannelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainChannelWidget(QWidget *parent = nullptr);
    ~MainChannelWidget();
signals:

private:
     QLabel *emgNum;
     QLabel *sqiNum;
     QLabel *emgData;

     void infoInit();//设置标签和位置


};

#endif // MAINCHANNELWIDGET_H
