#ifndef TEMPWIDGET_H
#define TEMPWIDGET_H

#include <QWidget>
#include <QLabel>

class TempWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TempWidget(QWidget *parent = nullptr);
    ~TempWidget();

signals:

private:

    QLabel *tpLabel;
    QLabel *tpLabel1;

    void tempShow();

};

#endif // TEMPWIDGET_H
