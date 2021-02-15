#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>

class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    QPushButton *closeButton;
    QPushButton *updateButton;
    QLineEdit *passwLineEdit;
    void aboutDialogInit();//显示信息
    void initDialogButtons();//添加按钮
    void paintEvent(QPaintEvent *);

    QPixmap pix;

private slots:
    void updateButton_clicked();
    void closeButton_clicked();


};

#endif // ABOUTDIALOG_H
