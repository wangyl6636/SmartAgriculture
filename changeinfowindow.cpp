#include "changeinfowindow.h"
#include "ui_changeinfowindow.h"

ChangeInfoWindow::ChangeInfoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChangeInfoWindow)
{
    ui->setupUi(this);
}

ChangeInfoWindow::~ChangeInfoWindow()
{
    delete ui;
}
