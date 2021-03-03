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
    void setimages(QString,QString);
    void setId(int);
signals:
    void mSignal(int);
private:
    int mid;
    QPixmap pixopen;
    QPixmap pixclose;

    bool isOpen = false;
protected:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
};


#endif // CSWITCH_H
