#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>
#include <QDebug>


class DataManager : public QObject
{
    Q_OBJECT
public:
    explicit DataManager(QObject *parent = nullptr);
    ~DataManager();

    void openPort();//打开串口

private slots:
     void receiveData();

private:
     QSerialPort *serial;

signals:

};

#endif // DATAMANAGER_H
