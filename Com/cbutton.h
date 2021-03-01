#ifndef CBUTTON_H
#define CBUTTON_H
#include <QPushButton>

class CButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CButton(QWidget *parent = 0);
    void set_button(int,int,int a=120,int b = 30);
private:


};

#endif // CBUTTON_H
