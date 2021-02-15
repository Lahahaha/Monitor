#ifndef SHOWVALUEWIDEGET_H
#define SHOWVALUEWIDEGET_H

#include <QWidget>
#include <QLabel>
class ShowValueWideget : public QWidget
{
    Q_OBJECT
public:
    explicit ShowValueWideget(QWidget *parent = nullptr);


private:

    //设置参数名称
    void setupAiname();
    void setupEmgname();

public slots:

    //准备数据
    void setAidata(int);
    void setEmgdata(int);
    void setAidata();
    void setEmgdata();


signals:

};

#endif // SHOWVALUEWIDEGET_H
