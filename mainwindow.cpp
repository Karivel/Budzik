#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    ui->Dni_tygodnia->addItem("poniedziałek");
    ui->Dni_tygodnia->addItem("wtorek");
    ui->Dni_tygodnia->addItem("środa");
    ui->Dni_tygodnia->addItem("czwartek");
    ui->Dni_tygodnia->addItem("piątek");
    ui->Dni_tygodnia->addItem("sobota");
    ui->Dni_tygodnia->addItem("niedziela");
}

void MainWindow::showTime()
{
  QTime time=QTime::currentTime();
  QString time_text=time.toString("hh : mm : ss");
  ui->Digital_clock->setText(time_text);
  this->time.setTime(time);
  this->time.setDate(ui->calendar->selectedDate());
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_clicked()
{
    close();
}


void MainWindow::on_start_clicked()
{
   // secdialog secdialog;
   // secdialog.setModal(true);
   // secdialog.exec();
    // 2 okna na raz
    hide();
    secDialog = new secdialog(this, this->test);
    secDialog->show();

}
