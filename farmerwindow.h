#ifndef FARMERWINDOW_H
#define FARMERWINDOW_H

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

private:
    int currentFarmerId;
    Ui::FarmerWindow *ui;

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
