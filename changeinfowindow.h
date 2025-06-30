#ifndef CHANGEINFOWINDOW_H
#define CHANGEINFOWINDOW_H

#include <QMainWindow>

namespace Ui {
class ChangeInfoWindow;
}

class ChangeInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChangeInfoWindow(QWidget *parent = nullptr);
    ~ChangeInfoWindow();

private:
    Ui::ChangeInfoWindow *ui;
};

#endif // CHANGEINFOWINDOW_H
