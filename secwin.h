#ifndef ALARM_H
#define ALARM_H

#include <QDialog>

namespace Ui {
class Alarm;
}

class Alarm : public QDialog
{
    Q_OBJECT

public:
    explicit Alarm(QWidget *parent = nullptr);
    ~Alarm();

private:
    Ui::Alarm *ui;
};

#endif // ALARM_H
