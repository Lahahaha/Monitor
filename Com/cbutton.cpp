#include "cbutton.h"

CButton::CButton(QWidget *parent):
    QPushButton(parent)
{
    this->resize(92,78);
    setCheckable(true);
    setAutoExclusive(true);

}
void CButton::set_button( int x,int y,int a, int b)
{
    setCheckable(false);
    setAutoExclusive(false);
    this->resize(a,b);
    this->move(x,y);
}
