#ifndef SIGNALQUALITYDIALOG_H
#define SIGNALQUALITYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include "buttons/cbutton.h"
#include <QLabel>

#define OK_BUTTON_POS_X             (93)
#define OK_BUTTON_POS_Y             (614)
#define CANCEL_BUTTON_POS_X         (829)
#define CANCEL_BUTTON_POS_Y         (614)
#define MEASURING_BUTTON_POS_X      (200)
#define MEASURING_BUTTON_POS_Y      (160)

#define TITLE_LABEL_POS_X           (387)
#define TITLE_LABEL_POS_Y           (8)
#define TITLE_LABEL_WIDTH           (250)
#define TITLE_LABEL_HEIGHT          (39)
#define HF_LABEL_POS_X              (30)
#define HF_LABEL_POS_Y              (40)
#define _50HZ_LABEL_POS_X           (30)
#define _50HZ_LABEL_POS_Y           (80)
#define ESI_LABEL_POS_X             (30)
#define ESI_LABEL_POS_Y             (120)
#define SQI_PERCENT_LABEL_POS_X             (30)
#define SQI_PERCENT_LABEL_POS_Y             (160)
#define Z1_LABEL_POS_X              (200)
#define Z1_LABEL_POS_Y              (40)
#define Z2_LABEL_POS_X              (200)
#define Z2_LABEL_POS_Y              (80)
#define Z3_LABEL_POS_X              (200)
#define Z3_LABEL_POS_Y              (120)

#define LABEL_DATA_POS_X            (173)
#define LABEL_DATA_POS_Y            (0)
#define LABEL_DATA_WIDTH            (173)
#define LABEL_DATA_HEIGHT           (86)

class SignalQualityDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SignalQualityDialog(QWidget *parent = nullptr);

signals:
private:
    void initButtons();
    void initLabel();
    QPushButton *okButton;
    QPushButton *cancelButton;
    CButton *measuringButton;

    CButton *mHFLabel;
    CButton *m50HzLabel;
    CButton *mESILabel;
    CButton *mSQILabel;
    CButton *mZ1Label;
    CButton *mZ2Label;
    CButton *mZ3Label;

    QLabel *mHFLabelData;
    QLabel *m50HzLabelData;
    QLabel *mESILabelData;
    QLabel *mSQILabelData;
    QLabel *mZ1LabelData;
    QLabel *mZ2LabelData;
    QLabel *mZ3LabelData;


    void paintEvent(QPaintEvent *);
    QPixmap pix;

};

#endif // SIGNALQUALITYDIALOG_H
