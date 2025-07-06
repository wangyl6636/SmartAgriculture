#ifndef SYSTEMWINDOW_H
#define SYSTEMWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <memory>
#include <vector> // Required for std::vector
#include "prediction.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
class QAction;
class QSplitter;
class QComboBox;
class QDateTimeEdit;
class QPushButton;
class QCheckBox;
class QSpinBox;
class QWidget;
class QLabel;
class QTimer;
class QTextEdit;
class QChartView;
class QChart;
class QLineSeries;
class QDateTimeAxis;
class QValueAxis;
class QPieSeries;
QT_END_NAMESPACE

class SystemSuggestionDialog;
class GaugeWidget;

class SystemWindow : public QMainWindow
{
    Q_OBJECT

public:
    // 构造函数接受作物区ID列表
    explicit SystemWindow(const std::vector<int>& userCropIds, QWidget *parent = nullptr);
    ~SystemWindow();

    bool initialize();
    void refreshSuggestion(SystemSuggestionDialog* dialog);

    signals:
        void closeSignal();

private slots:
    void onLoadDataClicked();
    void onRefreshClicked();
    void onSystemSuggestionClicked();
    void onRetrainModelClicked(bool isFirstRun = false);
    void onExportDataClicked();
    void showAboutDialog();
    void onSeriesHovered(const QPointF &point, bool state);
    void onAutoRefreshToggled(bool enabled);
    void updateDataAuto();
    void updateDashboard();
    void onStartTimeChanged(const QDateTime &dateTime);
    void onEndTimeChanged(const QDateTime &dateTime);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void initStyleSheet();
    void initMenu();
    bool initDatabase();
    void initUI();
    void initChart();
    void setupConnections();
    void populateCropAreaCombo();
    void loadAndDisplayData();
    QString getCurrentEnvironmentData();
    void updatePieChart(int cropAreaId, const QDateTime &startTime, const QDateTime &endTime);
    void initFertilizerPredictionSystem();

    std::vector<int> m_userCropIds;

    // --- UI Components ---
    QAction *m_retrainAction, *m_exportAction, *m_aboutAction;
    QWidget *m_centralWidget;
    QSplitter *m_mainSplitter, *m_chartSplitter;
    GaugeWidget *m_tempGauge, *m_humidityGauge;
    QComboBox *m_cropAreaCombo, *m_dataTypeCombo;
    QDateTimeEdit *m_startTimeEdit, *m_endTimeEdit;
    QPushButton *m_loadButton, *m_systemSuggestionButton;
    QCheckBox *m_autoRefreshCheckBox;
    QSpinBox *m_refreshIntervalSpinBox;
    QLabel *m_chartTooltip;
    QChartView *m_chartView, *m_pieChartView;
    QChart *m_chart, *m_pieChart;
    QLineSeries *m_series;
    QPieSeries *m_pieSeries;
    QDateTimeAxis *m_axisX;
    QValueAxis *m_axisY;

    // --- Backend Components ---
    QTimer *m_autoRefreshTimer, *m_dashboardUpdateTimer;
    std::unique_ptr<FertilizerPrediction::FertilizerPredictionSystem> m_predictionSystem;
    bool m_predictionSystemReady;
};

class SystemSuggestionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SystemSuggestionDialog(SystemWindow* systemWindow, QWidget *parent = nullptr);
    void setSuggestionData(const std::vector<FertilizerPrediction::PredictionResult> &results, const QString &wateringTip);
signals:
    void refreshRequested(SystemSuggestionDialog* dialog);
private:
    QTextEdit *m_contentTextEdit;
};

#endif // SYSTEMWINDOW_H
