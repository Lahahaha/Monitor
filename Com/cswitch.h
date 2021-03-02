#ifndef CSWITCH_H
#define CSWITCH_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class CSwitch : public QPushButton
{
    Q_OBJECT
public:
    explicit CSwitch(QWidget *parent = nullptr);

    void setId(int);
signals:
    void mSignal(int);
private:
    int mid;
protected:
    void mouseReleaseEvent(QMouseEvent*);
};


#endif // CSWITCH_H
