#ifndef FARMERWINDOW_H
#define FARMERWINDOW_H

#include <QMainWindow>

namespace Ui {
class FarmerWindow;
}

class FarmerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FarmerWindow(QWidget *parent = nullptr);
    ~FarmerWindow();

private:
    Ui::FarmerWindow *ui;
};

#endif // FARMERWINDOW_H
