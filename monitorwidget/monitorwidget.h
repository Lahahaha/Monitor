#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include "monitorwidget/curvegraph.h"
#include "monitorwidget/curvegraph2.h"
#include "monitorwidget/mainchannelwidget.h"
#include "monitorwidget/spectrumgraph.h"
#include "monitorwidget/subchannelwidget.h"

class MonitorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MonitorWidget(QWidget *parent = nullptr);

private:
    CurveGraph *cur;
    CurveGraph2 *cur2;
    MainChannelWidget *mainchannel;
    SpectrumGraph *spec;
    SubChannelWidget *sub;

signals:

};

#endif // MONITOR_H
