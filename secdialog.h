#ifndef SECDIALOG_H
#define SECDIALOG_H
#include "wrong.h"
#include <QDialog>
#include <QMainWindow>
#include <string.h>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class secdialog;
}

class secdialog : public QDialog
{
    Q_OBJECT

public:
    explicit secdialog(QDateTime selectedTime, QWidget *parent = nullptr);
    ~secdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::secdialog *ui;
    wrong *jeszczeraz;
    void showTime(int days, int hours, int minutes);
};

#endif // SECDIALOG_H
