#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "registerwindow.h"
#include "adminwindow.h"
#include "farmerwindow.h"
#include "expertwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onLogout();

private slots:
    void on_pushButtonRegister_clicked();
    void ReShow();

    void on_pushButtonLogin_clicked();

private:
    Ui::MainWindow *ui;
    RegisterWindow *rWindow;//注册界面指针
    AdminWindow *aWindow;//管理员界面指针
    FarmerWindow *fWindow;//农户界面指针
    ExpertWindow *eWindow;//专家界面指针
};
#endif // MAINWINDOW_H
