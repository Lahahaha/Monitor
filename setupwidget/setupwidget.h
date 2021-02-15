#ifndef SETUPWIDGET_H
#define SETUPWIDGET_H

#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>

class SetupWidget : public QDialog
{
    Q_OBJECT
public:
    explicit SetupWidget(QWidget *parent = nullptr);

signals:

private:
    void initButtons();
    QPushButton *okButton;
    QPushButton *cancelButton;
    void paintEvent(QPaintEvent *);
    QPixmap pix;
public slots:
    void okButton_clicked();
    void cancelButton_clicked();
};

#endif // SETUPWIDGET_H
