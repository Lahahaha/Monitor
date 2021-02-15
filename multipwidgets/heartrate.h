#ifndef HEARTRATE_H
#define HEARTRATE_H

#include <QWidget>
#include <QLabel>
class HeartRate : public QWidget
{
    Q_OBJECT
public:
    explicit HeartRate(QWidget *parent = nullptr);

signals:

public slots:
    void setdata();
private:
    QLabel *hrLabel;
    QLabel *hr;
    QLabel *unit;

    void setlocation();
    void setproperty();


};

#endif // HEARTRATE_H
