#include "expertwindow.h"
#include "ui_expertwindow.h"

ExpertWindow::ExpertWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ExpertWindow)
{
    ui->setupUi(this);
}

ExpertWindow::~ExpertWindow()
{
    delete ui;
}
