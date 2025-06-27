#include "farmerwindow.h"
#include "ui_farmerwindow.h"

FarmerWindow::FarmerWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FarmerWindow)
{
    ui->setupUi(this);
}

FarmerWindow::~FarmerWindow()
{
    delete ui;
}
