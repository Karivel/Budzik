#ifndef SECDIALOG_H
#define SECDIALOG_H
#include "wrong.h"
#include <QDialog>

namespace Ui {
class secdialog;
}

class secdialog : public QDialog
{
    Q_OBJECT

public:
    explicit secdialog(QWidget *parent = nullptr, QString value = nullptr);
    ~secdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::secdialog *ui;
    wrong *jeszczeraz;
};

#endif // SECDIALOG_H
