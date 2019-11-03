#include "secdialog.h"
#include "ui_secdialog.h"

secdialog::secdialog(QWidget *parent, QString value) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    ui->setupUi(this);
    ui->Czas->setText(value);
}

secdialog::~secdialog()
{
    delete ui;
}

void secdialog::on_pushButton_clicked()
{
    jeszczeraz = new wrong(this);
    jeszczeraz->show();
}
