#ifndef EXPERTWINDOW_H
#define EXPERTWINDOW_H

#include <QMainWindow>

namespace Ui {
class ExpertWindow;
}

class ExpertWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExpertWindow(QWidget *parent = nullptr);
    ~ExpertWindow();

private:
    Ui::ExpertWindow *ui;
};

#endif // EXPERTWINDOW_H
