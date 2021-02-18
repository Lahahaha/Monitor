#include "monitorwidget.h"

MonitorWidget::MonitorWidget(QWidget *parent) : QWidget(parent)
{
    cur = new CurveGraph(this);
    cur2 = new CurveGraph2(this);
    mainchannel = new MainChannelWidget(this);
    spec = new SpectrumGraph(this);
    sub = new SubChannelWidget(this);

    cur->show();
    cur2->show();
    mainchannel->show();
    spec->show();
    sub->show();
}
