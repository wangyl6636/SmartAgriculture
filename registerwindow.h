#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private:
    Ui::RegisterWindow *ui;

    //页面关闭，手动发送信号
    void closeEvent(QCloseEvent *event);

private slots:
    void onPhoneTextChanged(const QString &text);
    void on_pushButtonRegister_clicked();

    void on_comboBoxRole_activated(int index);

signals:
    void closedSignal();
};

#endif // REGISTERWINDOW_H
