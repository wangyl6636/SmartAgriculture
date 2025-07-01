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
    explicit ChangeInfoWindow(int id, int roleIndex, QWidget *parent = nullptr);
    ~ChangeInfoWindow();

private:
    int id;
    int roleIndex;
    Ui::ChangeInfoWindow *ui;

    //页面关闭，手动发送信号
    void closeEvent(QCloseEvent *event);

    //实现农作物区的动态加载
    void InitSpecificUi();
    void LoadCropAreas();
    void ClearCropArea();
    void AddCropCard(const QVariantMap &area);

signals:
    void closeSignal();
private slots:
    void on_cancelButton_clicked();
    void on_addCropButton_clicked();
    void on_saveButton_clicked();
};

#endif // CHANGEINFOWINDOW_H
