#ifndef STATSBAR_H
#define STATSBAR_H
#include <QWidget>
#include <QLabel>
#include <QDateTime>

class StatusBar : public QWidget
{
    Q_OBJECT

public:
    StatusBar(QWidget *parent = nullptr);
    ~StatusBar();

private:
    //时间
    QLabel *timeLabel;
    QDateTime *time;
    void timeInit();


private slots:
    //更新时间
    void timeUpdate();
};
#endif // STATSBAR_H
