#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    time = new QDateTime();
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

void MainWindow::showTime()
{
  QTime time=QTime::currentTime();
  QString time_text=time.toString("hh : mm : ss");
  ui->Digital_clock->setText(time_text);
  this->time->setTime(ui->timeEdit->time());
  this->time->setDate(ui->calendar->selectedDate());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_clicked()
{
    exit(0);
}


void MainWindow::on_start_clicked()
{
   // secdialog secdialog;
   // secdialog.setModal(true);
   // secdialog.exec();
    // 2 okna na raz
    hide();
    secDialog = new secdialog(this->time, this);
    secDialog->show();

}
