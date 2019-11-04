#include "secdialog.h"
#include "ui_secdialog.h"

secdialog::secdialog(QDateTime selectedTime, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    ui->setupUi(this);
}

secdialog::~secdialog()
{
    delete ui;
}

void secdialog:: showTime(int days, int hours, int minutes)
{
    QString text = "Pozostało ";
    text.append(days);
    text.append(" dni, ");
    text.append(hours);
    text.append(" godzin i ");
    text.append(minutes);
    text.append(" minut");

    ui->Czas->setText(text);
}


void secdialog::on_pushButton_clicked()
{
    jeszczeraz = new wrong(this);
    jeszczeraz->show();
}
