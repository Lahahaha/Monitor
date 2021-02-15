#ifndef MULTIPWIDGET_H
#define MULTIPWIDGET_H

#include <QWidget>
#include "ecg.h"
#include "spo2widget.h"
#include "respgraph.h"
#include "temperature.h"
#include "multipwidgets/heartrate.h"

class MultipWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MultipWidget(QWidget *parent = nullptr);
    ~MultipWidget();
    EcgWidget *ecg;
    Spo2Widget *spo;
    RespWidget *resp;
    TempWidget *temp;
    HeartRate *hr;

signals:

private:


};

#endif // MULTIPWIDGET_H
