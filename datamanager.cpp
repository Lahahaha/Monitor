#include "datamanager.h"

DataManager::DataManager(QObject *parent) : QObject(parent)
{

    serial = new QSerialPort;
//    connect(this->serial,SIGNAL(readyRead()),this,SLOT(resolveDataFromSerialport()));
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    qDebug() << "Total numbers of ports: " << serialPortInfos.count();
}


void DataManager::openPort()
{
    //获得串口名字
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }

    if (!serial->isOpen())
    {
        serial->clear();
        serial->close();

    }
    serial->setPortName(m_serialPortName[0]);
    if(!serial->open(QIODevice::ReadWrite))
    {
        qDebug()<<m_serialPortName[0]<<"打开失败";
        return;
    }
    serial->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::OddParity);

    connect(serial,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

void DataManager::receiveData()
{
    QByteArray info = serial->readAll();
    QByteArray hexData = info.toHex();
    qDebug()<<"receive info:"<<info;

    //这里面的协议 自己定义
    if(hexData == "0x10000")
    {
        //do something
    }
    else if(hexData  == "0x100001")
    {
        //do something
    }
}

DataManager::~DataManager()
{
    if (serial->isOpen())
    {
        serial->close();
    }
    delete serial;
}

