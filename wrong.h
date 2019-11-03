#ifndef WRONG_H
#define WRONG_H

#include <QDialog>

namespace Ui {
class wrong;
}

class wrong : public QDialog
{
    Q_OBJECT

public:
    explicit wrong(QWidget *parent = nullptr);
    ~wrong();

private:
    Ui::wrong *ui;
};

#endif // WRONG_H
