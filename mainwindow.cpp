#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRegister_clicked()
{
    this->hide();
    if(rWindow==nullptr){
        rWindow=new RegisterWindow();
        connect(rWindow, &RegisterWindow::closedSignal, this, &MainWindow::ReShow);
    }
    rWindow->show();
}

//保证注册界面的临时性
void MainWindow::ReShow(){
    this->show();
    delete rWindow;
    rWindow=nullptr;
}
