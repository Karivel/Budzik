#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "secdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QDateTime *time;

private slots:
    void showTime();

    void on_exit_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    secdialog *secDialog;

};
#endif // MAINWINDOW_H
