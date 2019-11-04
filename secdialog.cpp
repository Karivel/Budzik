#include "secdialog.h"
#include "ui_secdialog.h"

secdialog::secdialog(QDateTime *selectedTime, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secdialog)
{
    randomQuestion = 0;
    questions = new QList<QString>();
    answers = new QList<QString>();
    questions->append("∫1dx");
    questions->append("∫x^ndx");
    questions->append("∫xdx");
    questions->append("∫1/xdx");
    questions->append("∫a^xdx");
    questions->append("∫e^xdx");
    questions->append("∫sinxdx");
    questions->append("∫cosxdx");
    questions->append("∫tgxdx");
    questions->append("∫ctgxdx");
    questions->append("∫e^axdx");
    answers->append("x+C");
    answers->append("1/n+1*x^n+1+C");
    answers->append("1/2*x^2+C");
    answers->append("ln|x|+C");
    answers->append("a^x/lna+C");
    answers->append("e^x+C");
    answers->append("-cosx+C");
    answers->append("sinx+C");
    answers->append("-ln|cosx|+C");
    answers->append("ln|sinx|+C");
    answers->append("1/a*e^ax");
    this->selectedTime = selectedTime;
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(countTime()));
    timer->start();
}

secdialog::~secdialog()
{
    delete ui;
}

void secdialog::countTime()
{
  QDateTime currentTime = QDateTime::currentDateTime();
  //int days = currentTime.daysTo(*(this->selectedTime));
  int seconds = currentTime.secsTo(*selectedTime);
  int minutes = seconds/60;
  int hours = minutes/60;
  minutes -= hours*60;
  if(hours == 0 && minutes == 0)
  {
      timer->stop();
      QRandomGenerator QRandomGenerator;
      randomQuestion = QRandomGenerator.bounded(0, 10);
      ui->textBrowser->setText(questions->value(randomQuestion));
  }
  showTime(0, hours, minutes);
}

void secdialog:: showTime(int days, int hours, int minutes)
{
    QString text = "Pozostało ";
    //text.append(QString::number(days));
    //text.append(" dni, ");
    text.append(QString::number(hours));
    text.append(" godzin i ");
    text.append(QString::number(minutes));
    text.append(" minut");
    ui->Czas->setText(text);
}


void secdialog::on_pushButton_clicked()
{
    QString test = ui->textEdit->toPlainText();
    if(!QString::compare(ui->textEdit->toPlainText().toLower().replace(" ", ""),
                      answers->value(randomQuestion).toLower().replace(" ", "")))
    {
        exit(0);
    }
    jeszczeraz = new wrong(this);
    jeszczeraz->show();
}
