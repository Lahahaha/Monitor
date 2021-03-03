#ifndef SETUPWIDGET_H
#define SETUPWIDGET_H

#define HF_BUTTON_POS_X             (20)
#define _50HZ_BUTTON_POS_X          (70)
#define SR_BUTTON_POS_X             (120)
#define SQI_BUTTON_POS_X            (170)
#define THRESHOLD_POS_X             (210)
#define SWITCH_BUTTON_Y             (145)
#define UPPER_POS_Y                 (60)
#define LOWER_POS_Y                 (100)
#define TIME_BUTTON_POS_X           (220)

#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include "Com/cbutton.h"
#include "Com/cswitch.h"
#include <QLabel>
#include <QTimer>
#include <QDateTime>


class SetupWidget : public QDialog
{
    Q_OBJECT
public:
    explicit SetupWidget(QWidget *parent = nullptr);

signals:


private:
    void initButtons();
    void initlabels();
    QPushButton *okButton;
    QPushButton *cancelButton;
    void paintEvent(QPaintEvent *);
    QPixmap pix;

    CButton *mGraphLabel;
    CButton *mUpperThresholdLabel;
    CButton *mLowerThresholdLabel;
    CButton *mTimeLabel;

    QLabel *mGraphLabelData;
    QLabel *mUpperThresholdLabelData;
    QLabel *mLowerThresholdLabelData;

    CSwitch *mHFButton;
    CSwitch *m50HzButton;
    CSwitch *mSRButton;
    CSwitch *mSQIButton;

    QTimer *mTimer;

    enum
    {
        HF,
        _50Hz,
        SQI,
        ESI,
        SR
    };


public slots:
    void okButton_clicked();
    void cancelButton_clicked();
    void slotSwitch(int);
};

#endif // SETUPWIDGET_H
