#ifndef FARMERWINDOW_H
#define FARMERWINDOW_H
#include "changeinfowindow.h"
#include "systemadviceform.h"
#include "systemwindow.h"

#include <QMainWindow>
#include <QMap>

namespace Ui {
class FarmerWindow;
}

class FarmerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FarmerWindow(int farmerId, QWidget *parent = nullptr);
    ~FarmerWindow();

private slots:
    void refreshSuggestions();
    void UpdateButtonClicked();
    void ReShow();
    void on_suggestButton_clicked();
    void on_viewSystemAdviceButton_clicked();

private:
    int currentFarmerId;
    Ui::FarmerWindow *ui;

    //更改信息界面
    ChangeInfoWindow *changeWindow;

    // 系统建议界面
    SystemAdviceForm *systemAdviceForm;

    SystemWindow *sysWin;

    // 类别颜色映射
    QMap<QString, QString> categoryColors = {
        {"病虫害", "#e74c3c"},
        {"灌溉", "#3498db"},
        {"施肥", "#f39c12"},
        {"收获", "#27ae60"},
        {"其他", "#9b59b6"}
    };

    void initUI();
    void loadSuggestions();
    void createSuggestionCard(const QVariantMap& suggestion);
    void clearSuggestions();
    void showSuggestionDetail(const QVariantMap& suggestion);
};

#endif // FARMERWINDOW_H
