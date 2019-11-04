#ifndef SECDIALOG_H
#define SECDIALOG_H
#include "wrong.h"
#include <QDialog>
#include <QMainWindow>
#include <string.h>
#include <QTimer>
#include <QDateTime>
#include <qlist.h>
#include <QRandomGenerator64>

namespace Ui {
class secdialog;
}

class secdialog : public QDialog
{
    Q_OBJECT

public:
    explicit secdialog(QDateTime *selectedTime, QWidget *parent = nullptr);
    ~secdialog();

private slots:
    void on_pushButton_clicked();
    void countTime();

private:
    Ui::secdialog *ui;
    wrong *jeszczeraz;
    void showTime(int days, int hours, int minutes);
    QTimer *timer;
    QDateTime *selectedTime;
    QList<QString> *answers;
    QList<QString> *questions;
    int randomQuestion;
};

#endif // SECDIALOG_H
