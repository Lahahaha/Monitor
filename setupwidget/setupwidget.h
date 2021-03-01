#ifndef SETUPWIDGET_H
#define SETUPWIDGET_H

#define HF_BUTTON_POS_X             (30)
#define _50HZ_BUTTON_POS_X          (90)
#define SR_BUTTON_POS_X             (150)
#define SQI_BUTTON_POS_X            (210)
#define TIME_BUTTON_POS_X           (270)

#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include "Com/cbutton.h"
#include "Com/cswitch.h"
#include <QLabel>

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


public slots:
    void okButton_clicked();
    void cancelButton_clicked();
};

#endif // SETUPWIDGET_H
