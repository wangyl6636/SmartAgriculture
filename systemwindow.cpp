#include "systemwindow.h"
#include "databasemanager.h"
#include "gauge_widget.h"

// Qt Core and Widgets
#include <QApplication>
#include <QFileInfo>
#include <QDir>
#include <QTimer>
#include <QDateTime>
#include <cmath>
#include <QCloseEvent>

// Qt UI Components
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QSplitter>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QProgressDialog>
#include <QIcon>
#include <QFileDialog>
#include <QTextStream>

// Qt SQL and Charts
#include <QtSql>
#include <QtCharts>

/**
 * @brief 系统智能建议对话框构造函数，初始化UI
 * @param systemWindow 父窗口指针
 * @param parent 父窗口
 */
SystemSuggestionDialog::SystemSuggestionDialog(SystemWindow* systemWindow, QWidget *parent)
    : QDialog(parent)
{
    (void)systemWindow;
    setWindowTitle("系统智能建议");
    setMinimumSize(480, 420);

    auto layout = new QVBoxLayout(this);
    m_contentTextEdit = new QTextEdit(this);
    m_contentTextEdit->setReadOnly(true);

    layout->addWidget(new QLabel("<b>根据当前环境数据分析，系统建议如下：</b>"));
    layout->addWidget(m_contentTextEdit);

    auto buttonLayout = new QHBoxLayout();
    auto refreshButton = new QPushButton(QIcon::fromTheme("view-refresh"), " 刷新建议");
    auto closeButton = new QPushButton(QIcon::fromTheme("dialog-close"), " 关闭");

    buttonLayout->addStretch();
    buttonLayout->addWidget(refreshButton);
    buttonLayout->addWidget(closeButton);
    layout->addLayout(buttonLayout);

    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(refreshButton, &QPushButton::clicked, this, [=]() {
        emit refreshRequested(this);
    });
}

/**
 * @brief 设置系统建议内容
 * @param results 预测结果
 * @param wateringTip 灌溉建议
 */
void SystemSuggestionDialog::setSuggestionData(const std::vector<FertilizerPrediction::PredictionResult> &results, const QString &wateringTip)
{
    QString htmlContent;
    htmlContent += "<h3><font color='#2c3e50'>肥料推荐</font></h3>";
    htmlContent += "<table width='100%' cellspacing='0' cellpadding='5' style='background-color: #ffffff; border: 1px solid #ddd; border-radius: 4px;'>";
    htmlContent += "<tr style='background-color: #3498db; color: white;'><th>肥料类型</th><th>置信度</th></tr>";

    if (results.empty()) {
        htmlContent += "<tr><td colspan='2' align='center'>无可用肥料推荐。</td></tr>";
    } else {
        for (const auto &result : results) {
            htmlContent += QString("<tr><td>%1</td><td>%2%</td></tr>")
            .arg(QString::fromStdString(result.fertilizer))
                .arg(QString::number(result.confidence * 100, 'f', 1));
        }
    }
    htmlContent += "</table>";
    htmlContent += "<h3><font color='#2c3e50'>浇水建议</font></h3>";
    QString tipColor = wateringTip.contains("低") ? "#e74c3c" : (wateringTip.contains("高") ? "#f39c12" : "#2ecc71");
    htmlContent += QString("<p style='background-color: #ecf0f1; padding: 10px; border-radius: 5px;'><b><font color='%1'>%2</font></b></p>")
                       .arg(tipColor, wateringTip);
    m_contentTextEdit->setHtml(htmlContent);
}


// =================================================================
// SystemWindow Implementation
// =================================================================
/**
 * @brief 系统分析窗口构造函数，初始化成员变量
 * @param userCropIds 当前用户可访问的作物区ID列表
 * @param parent 父窗口指针
 */
SystemWindow::SystemWindow(const std::vector<int>& userCropIds, QWidget *parent)
    : QMainWindow(parent),
      m_userCropIds(userCropIds),
      m_retrainAction(nullptr), m_exportCsvAction(nullptr), m_exportImageAction(nullptr), m_aboutAction(nullptr),
      m_centralWidget(nullptr),
      m_mainSplitter(nullptr), m_chartSplitter(nullptr),
      m_tempGauge(nullptr), m_humidityGauge(nullptr),
      m_cropAreaCombo(nullptr), m_dataTypeCombo(nullptr),
      m_startTimeEdit(nullptr), m_endTimeEdit(nullptr),
      m_loadButton(nullptr), m_systemSuggestionButton(nullptr),
      m_autoRefreshCheckBox(nullptr), m_refreshIntervalSpinBox(nullptr),
      m_chartTooltip(nullptr),
      m_chartView(nullptr), m_pieChartView(nullptr),
      m_chart(nullptr), m_pieChart(nullptr),
      m_series(nullptr), m_pieSeries(nullptr),
      m_axisX(nullptr), m_axisY(nullptr),
      m_autoRefreshTimer(nullptr), m_dashboardUpdateTimer(nullptr),
      m_predictionSystem(nullptr),
      m_predictionSystemReady(false),
      m_timeUpdateTimer(nullptr)
{}

/**
 * @brief 初始化窗口，加载UI、数据库、模型等
 * @return 是否初始化成功
 */
bool SystemWindow::initialize()
{
    setWindowTitle("智慧农业数据可视化与决策系统");
    setMinimumSize(1360, 800);
    setWindowIcon(QIcon::fromTheme("applications-science"));

    initStyleSheet();
    initMenu();
    initUI();
    initChart();
    setupConnections();

    if (!initDatabase()) {
        QMessageBox::critical(this, "数据库错误", "无法连接到远程数据库。应用程序功能将受限。");
        if(m_loadButton) m_loadButton->setEnabled(false);
        if(m_systemSuggestionButton) m_systemSuggestionButton->setEnabled(false);
    } else {
        populateCropAreaCombo();
    }

    QDateTime now = QDateTime::currentDateTime();
    if (m_endTimeEdit) m_endTimeEdit->setDateTime(now);
    if (m_startTimeEdit) m_startTimeEdit->setDateTime(now.addDays(-7));

    m_autoRefreshTimer = new QTimer(this);
    connect(m_autoRefreshTimer, &QTimer::timeout, this, &SystemWindow::updateDataAuto);
    m_autoRefreshTimer->setInterval(60000); // 自动刷新间隔固定为60秒
    m_dashboardUpdateTimer = new QTimer(this);
    connect(m_dashboardUpdateTimer, &QTimer::timeout, this, &SystemWindow::updateDashboard);
    m_dashboardUpdateTimer->start(5000);

    // 新增：实时时间定时器
    m_timeUpdateTimer = new QTimer(this);
    m_timeUpdateTimer->start(10000); // 10秒刷新一次

    initFertilizerPredictionSystem();

    if (m_cropAreaCombo && m_cropAreaCombo->count() > 0) {
        onLoadDataClicked();
    } else {
        if(m_chart) m_chart->setTitle("当前用户无作物区，或数据库连接失败。");
    }

    statusBar()->showMessage("系统准备就绪。");
    return true;
}

SystemWindow::~SystemWindow() {}

/**
 * @brief 初始化全局样式表
 */
void SystemWindow::initStyleSheet()
{
    qApp->setStyleSheet(
        "QMainWindow { background-color: #f4f6f8; }"
        "QGroupBox { font-weight: bold; background-color: #ffffff; border: 1px solid #dfe4ea; border-radius: 8px; margin-top: 1ex; }"
        "QGroupBox::title { subcontrol-origin: margin; subcontrol-position: top center; padding: 0 10px; background-color: #ffffff; }"
        "QPushButton { background-color: #3498db; color: white; border: none; padding: 8px 16px; border-radius: 4px; font-size: 10pt; }"
        "QPushButton:hover { background-color: #2980b9; }"
        "QPushButton:pressed { background-color: #1f618d; }"
        "QPushButton:disabled { background-color: #bdc3c7; color: #7f8c8d; }"
        "QComboBox, QDateTimeEdit, QSpinBox { padding: 5px; border: 1px solid #ced4da; border-radius: 4px; background-color: white; }"
        "QLabel { color: #495057; }"
        "QChartView { border: 1px solid #dfe4ea; border-radius: 8px; background-color: white; }"
        "QMenuBar { background-color: #ffffff; border-bottom: 1px solid #dfe4ea; }"
        "QStatusBar { font-size: 9pt; color: #6c757d; }"
        "#chartTooltip { background: rgba(0, 0, 0, 0.7); color: white; padding: 5px; border-radius: 3px; border: 1px solid white; }"
        );
}

/**
 * @brief 初始化菜单栏
 */
void SystemWindow::initMenu()
{
    auto fileMenu = menuBar()->addMenu("文件(&F)");
    m_exportCsvAction = new QAction(QIcon::fromTheme("document-save"), "导出当前图表数据(&E)...", this);
    m_exportImageAction = new QAction(QIcon::fromTheme("image-x-generic"), "导出图表为图片(&I)...", this);
    m_retrainAction = new QAction(QIcon::fromTheme("system-run"), "重新训练模型(&R)...", this);
    fileMenu->addAction(m_exportCsvAction);
    fileMenu->addAction(m_exportImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(m_retrainAction);
    fileMenu->addSeparator();
    fileMenu->addAction(QIcon::fromTheme("application-exit"), "退出(&X)", qApp, &QApplication::quit);
    auto helpMenu = menuBar()->addMenu("帮助(&H)");
    m_aboutAction = new QAction(QIcon::fromTheme("help-about"), "关于(&A)", this);
    helpMenu->addAction(m_aboutAction);
}

/**
 * @brief 初始化主UI布局
 */
void SystemWindow::initUI()
{
    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);

    auto mainLayout = new QHBoxLayout(m_centralWidget);

    m_mainSplitter = new QSplitter(Qt::Horizontal);
    mainLayout->addWidget(m_mainSplitter);

    auto leftPanel = new QWidget();
    leftPanel->setFixedWidth(320);
    auto leftLayout = new QVBoxLayout(leftPanel);

    auto dashboardGroup = new QGroupBox("实时仪表盘");
    auto dashboardLayout = new QHBoxLayout(dashboardGroup);
    m_tempGauge = new GaugeWidget("温度", "°C");
    m_tempGauge->setRange(0, 50);
    m_humidityGauge = new GaugeWidget("土壤湿度", "%");
    m_humidityGauge->setRange(0, 100);
    dashboardLayout->addWidget(m_tempGauge);
    dashboardLayout->addWidget(m_humidityGauge);
    leftLayout->addWidget(dashboardGroup);

    auto controlGroup = new QGroupBox("数据控制");
    auto controlLayout = new QGridLayout(controlGroup);
    controlLayout->setSpacing(10);
    controlLayout->addWidget(new QLabel("作物区域:"), 0, 0); m_cropAreaCombo = new QComboBox(); controlLayout->addWidget(m_cropAreaCombo, 0, 1);
    controlLayout->addWidget(new QLabel("数据类型:"), 1, 0); m_dataTypeCombo = new QComboBox(); controlLayout->addWidget(m_dataTypeCombo, 1, 1);
    m_dataTypeCombo->addItems({"温度", "空气湿度", "土壤湿度", "土壤温度", "氮 (N)", "磷 (P)", "钾 (K)"});
    controlLayout->addWidget(new QLabel("开始时间:"), 2, 0); m_startTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
    m_startTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm");
    m_startTimeEdit->setCalendarPopup(true);
    m_startTimeEdit->setMaximumDateTime(QDateTime::currentDateTime());
    controlLayout->addWidget(m_startTimeEdit, 2, 1);
    controlLayout->addWidget(new QLabel("结束时间:"), 3, 0); m_endTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
    m_endTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm");
    m_endTimeEdit->setCalendarPopup(true);
    m_endTimeEdit->setMaximumDateTime(QDateTime::currentDateTime());
    controlLayout->addWidget(m_endTimeEdit, 3, 1);
    m_loadButton = new QPushButton(QIcon::fromTheme("document-open"), " 查询数据"); controlLayout->addWidget(m_loadButton, 4, 0, 1, 2);
    // 自动刷新相关控件
    m_autoRefreshCheckBox = new QCheckBox("自动刷新折线图");
    m_refreshIntervalSpinBox = new QSpinBox();
    m_refreshIntervalSpinBox->setRange(5, 3600);
    m_refreshIntervalSpinBox->setValue(60); // 固定为60秒
    m_refreshIntervalSpinBox->setSuffix(" 秒");
    m_refreshIntervalSpinBox->setEnabled(false); // 禁用编辑
    QLabel* intervalLabel = new QLabel("刷新间隔:");
    QPushButton* manualRefreshButton = new QPushButton(QIcon::fromTheme("view-refresh"), " 立即刷新");
    int row = 5;
    controlLayout->addWidget(m_autoRefreshCheckBox, row, 0, 1, 2);
    controlLayout->addWidget(intervalLabel, row+1, 0);
    controlLayout->addWidget(m_refreshIntervalSpinBox, row+1, 1);
    controlLayout->addWidget(manualRefreshButton, row+2, 0, 1, 2);
    leftLayout->addWidget(controlGroup);

    leftLayout->addStretch();

    m_systemSuggestionButton = new QPushButton(QIcon::fromTheme("system-help"), " 系统智能建议");
    leftLayout->addWidget(m_systemSuggestionButton);

    m_chartSplitter = new QSplitter(Qt::Vertical);
    m_chartView = new QChartView();
    m_pieChartView = new QChartView();
    m_chartSplitter->addWidget(m_chartView);
    m_chartSplitter->addWidget(m_pieChartView);
    m_chartSplitter->setStretchFactor(0, 3);
    m_chartSplitter->setStretchFactor(1, 2);

    m_mainSplitter->addWidget(leftPanel);
    m_mainSplitter->addWidget(m_chartSplitter);
    m_mainSplitter->setStretchFactor(1, 1);
}

void SystemWindow::initChart()
{
    m_chart = new QChart();
    m_series = new QLineSeries();
    m_series->setName("数据");
    m_chart->addSeries(m_series);
    m_chart->setAnimationOptions(QChart::SeriesAnimations);
    m_chart->legend()->hide();

    m_axisX = new QDateTimeAxis;
    m_axisX->setFormat("MM-dd hh:mm");
    m_axisX->setTitleText("时间");
    m_chart->addAxis(m_axisX, Qt::AlignBottom);

    m_axisY = new QValueAxis;
    m_chart->addAxis(m_axisY, Qt::AlignLeft);

    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);

    if(m_chartView) m_chartView->setChart(m_chart);
    if(m_chartView) m_chartView->setRenderHint(QPainter::Antialiasing);
    if(m_chartView) m_chartView->setRubberBand(QChartView::RectangleRubberBand);

    m_chart->setAcceptHoverEvents(true);
    m_chartTooltip = new QLabel(m_chartView);
    m_chartTooltip->setObjectName("chartTooltip");
    m_chartTooltip->hide();

    m_pieChart = new QChart();
    m_pieSeries = new QPieSeries();
    m_pieSeries->setHoleSize(0.35);
    m_pieChart->addSeries(m_pieSeries);
    m_pieChart->setAnimationOptions(QChart::AllAnimations);
    if(m_pieChartView) m_pieChartView->setChart(m_pieChart);
    if(m_pieChartView) m_pieChartView->setRenderHint(QPainter::Antialiasing);
}

void SystemWindow::setupConnections()
{
    if(m_loadButton) connect(m_loadButton, &QPushButton::clicked, this, &SystemWindow::onLoadDataClicked);
    if(m_systemSuggestionButton) connect(m_systemSuggestionButton, &QPushButton::clicked, this, &SystemWindow::onSystemSuggestionClicked);
    if(m_cropAreaCombo) connect(m_cropAreaCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SystemWindow::onLoadDataClicked);
    if(m_dataTypeCombo) connect(m_dataTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &SystemWindow::onLoadDataClicked);
    if(m_startTimeEdit) connect(m_startTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &SystemWindow::onStartTimeChanged);
    if(m_endTimeEdit) connect(m_endTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &SystemWindow::onEndTimeChanged);
    if(m_retrainAction) connect(m_retrainAction, &QAction::triggered, this, [this](){ onRetrainModelClicked(false); });
    if(m_exportCsvAction) connect(m_exportCsvAction, &QAction::triggered, this, &SystemWindow::onExportDataClicked);
    if(m_exportImageAction) connect(m_exportImageAction, &QAction::triggered, this, &SystemWindow::onExportImageClicked);
    if(m_aboutAction) connect(m_aboutAction, &QAction::triggered, this, &SystemWindow::showAboutDialog);
    if(m_series) connect(m_series, &QLineSeries::hovered, this, &SystemWindow::onSeriesHovered);
    // 自动刷新信号槽
    connect(m_autoRefreshCheckBox, &QCheckBox::toggled, this, &SystemWindow::onAutoRefreshToggled);
}

bool SystemWindow::initDatabase()
{
    return DataBaseManager::instance().InitDataBase();
}

void SystemWindow::initFertilizerPredictionSystem()
{
    m_predictionSystem = std::make_unique<FertilizerPrediction::FertilizerPredictionSystem>();
    QString modelPath = QApplication::applicationDirPath() + "/fertilizer_model.rf";
    QString csvPath = QApplication::applicationDirPath() + "/fertilizer_data.csv";

    if (QFile::exists(modelPath)) {
        qDebug() << "Found existing model, loading from:" << modelPath;
        if (m_predictionSystem->loadModel(modelPath.toStdString())) {
            m_predictionSystemReady = true;
            statusBar()->showMessage("肥料预测模型加载成功。", 5000);
        } else {
            m_predictionSystemReady = false;
            QMessageBox::critical(this, "模型加载失败", "找到模型文件但无法加载。请尝试删除 fertilizer_model.rf 并重启以重新训练。");
        }
    } else {
        qDebug() << "Model file not found. Attempting to train from CSV.";
        if (!QFile::exists(csvPath)) {
            m_predictionSystemReady = false;
            QMessageBox::critical(this, "严重错误", "未找到模型文件，也未找到训练数据！预测功能将不可用。\n请将 fertilizer_data.csv 文件复制到程序目录。");
        } else {
            onRetrainModelClicked(true);
        }
    }
    if(m_systemSuggestionButton) m_systemSuggestionButton->setEnabled(m_predictionSystemReady);
    if(m_retrainAction) m_retrainAction->setEnabled(QFile::exists(csvPath));
}

void SystemWindow::onRetrainModelClicked(bool isFirstRun)
{
    QString csvPath = QApplication::applicationDirPath() + "/fertilizer_data.csv";
    if (!isFirstRun) {
        if (QMessageBox::question(this, "确认重新训练", "这将使用 'fertilizer_data.csv' 重新训练并覆盖现有模型。过程可能需要一些时间。是否继续？", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
            return;
        }
    } else {
        QMessageBox::information(this, "首次运行", "未找到预训练模型。将使用 'fertilizer_data.csv' 进行一次性训练，请稍候...");
    }

    QProgressDialog progress("正在训练模型...", "取消", 0, 0, this);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();
    qApp->processEvents();

    if (m_predictionSystem->loadDataFromCSV(csvPath.toStdString())) {
        if (m_predictionSystem->trainModel()) {
            QString modelPath = QApplication::applicationDirPath() + "/fertilizer_model.rf";
            m_predictionSystem->saveModel(modelPath.toStdString());
            m_predictionSystemReady = true;
            if (!isFirstRun) {
                QMessageBox::information(this, "成功", "模型已成功重新训练和保存。");
            }
        } else {
            m_predictionSystemReady = false;
            QMessageBox::critical(this, "失败", "模型训练失败。");
        }
    } else {
        m_predictionSystemReady = false;
        QMessageBox::critical(this, "失败", "从CSV加载数据失败。");
    }

    progress.close();
    m_systemSuggestionButton->setEnabled(m_predictionSystemReady);
}

void SystemWindow::onSystemSuggestionClicked()
{
    if (!m_predictionSystemReady) { QMessageBox::critical(this, "错误", "预测模型未就绪。"); return; }
     QString inputData = getCurrentEnvironmentData();
    if (inputData.isEmpty()) {
        QMessageBox::warning(this, "数据不足", "无法获取当前作物区域的完整环境数据以进行预测。");
        return;
    }
    auto dialog = new SystemSuggestionDialog(this, this);
    refreshSuggestion(dialog);
    dialog->exec();
    delete dialog;
}

void SystemWindow::refreshSuggestion(SystemSuggestionDialog* dialog)
{
    if (!dialog) return;
    QString inputData = getCurrentEnvironmentData();
    if (inputData.isEmpty()) { QMessageBox::warning(this, "数据不足", "无法获取当前作物区域的完整环境数据以进行预测。"); return; }
    auto prediction = m_predictionSystem->predict(inputData.toStdString());
    dialog->setSuggestionData(prediction.first, QString::fromStdString(prediction.second));
    statusBar()->showMessage("建议已刷新。", 3000);
}

void SystemWindow::onLoadDataClicked()
{
    loadAndDisplayData();
    updateDashboard();
}

void SystemWindow::onRefreshClicked() { onLoadDataClicked(); }
void SystemWindow::onAutoRefreshToggled(bool enabled) {
    if(m_autoRefreshTimer) {
        if(enabled) m_autoRefreshTimer->start(); // 启动定时器，使用setInterval设定的60秒
        else m_autoRefreshTimer->stop();
    }
}
void SystemWindow::updateDataAuto() {
    if (m_startTimeEdit && m_endTimeEdit) {
        QDateTime fixedStart = m_startTimeEdit->dateTime(); // 固定不变
        QDateTime now = QDateTime::currentDateTime(); // 作为新的结束时间
        m_endTimeEdit->setDateTime(now);
        // 直接用fixedStart和now刷新数据
        loadAndDisplayData(fixedStart, now);
        return;
    } else if (m_endTimeEdit) {
        QDateTime now = QDateTime::currentDateTime();
        m_endTimeEdit->setDateTime(now);
    }
    onLoadDataClicked();
}
void SystemWindow::onStartTimeChanged(const QDateTime &dt) { if(m_endTimeEdit) m_endTimeEdit->setMinimumDateTime(dt); }
void SystemWindow::onEndTimeChanged(const QDateTime &dt) { if(m_startTimeEdit) m_startTimeEdit->setMaximumDateTime(dt); }

void SystemWindow::onSeriesHovered(const QPointF &point, bool state)
{
    if (state && m_chartTooltip) {
        m_chartTooltip->setText(QString("时间: %1\n数值: %2").arg(QDateTime::fromMSecsSinceEpoch(static_cast<qint64>(point.x())).toString("MM-dd hh:mm")).arg(point.y(), 0, 'f', 2));
        if(m_chartView) m_chartTooltip->move(m_chartView->mapFromGlobal(QCursor::pos()) + QPoint(15, 0));
        m_chartTooltip->adjustSize();
        m_chartTooltip->show();
    } else if (m_chartTooltip) {
        m_chartTooltip->hide();
    }
}

void SystemWindow::onExportDataClicked()
{
    if (!m_series || m_series->points().isEmpty()) { QMessageBox::warning(this, "无数据", "图表中没有可导出的数据。"); return; }
    QString defaultFileName = QString("export_%1_%2.csv").arg(m_cropAreaCombo->currentText().replace(" ", "_")).arg(QDate::currentDate().toString("yyyyMMdd"));
    QString fileName = QFileDialog::getSaveFileName(this, "导出为CSV", defaultFileName, "CSV 文件 (*.csv)");
    if (fileName.isEmpty()) return;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { QMessageBox::critical(this, "文件错误", "无法写入文件: " + file.errorString()); return; }
    QTextStream out(&file);
    out << "Timestamp,Value," << m_dataTypeCombo->currentText() << "\n";
    for (const QPointF &p : m_series->points()) out << QDateTime::fromMSecsSinceEpoch(static_cast<qint64>(p.x())).toString(Qt::ISODate) << "," << p.y() << "\n";
    file.close();
    statusBar()->showMessage("数据已成功导出至 " + fileName, 5000);
}

void SystemWindow::onExportImageClicked()
{
    if (!m_chartView) return;
    QString defaultFileName = QString("export_chart_%1.png").arg(QDate::currentDate().toString("yyyyMMdd"));
    QString fileName = QFileDialog::getSaveFileName(this, "导出图表为图片", defaultFileName, "PNG图片 (*.png)");
    if (fileName.isEmpty()) return;

    QPixmap p = m_chartView->grab();
    if (p.save(fileName, "PNG")) {
        statusBar()->showMessage("图表已成功导出至 " + fileName, 5000);
    } else {
        QMessageBox::critical(this, "导出失败", "无法保存图表图片。");
    }
}

void SystemWindow::showAboutDialog()
{
    QMessageBox::about(this, "关于本系统",
                       "<b>智慧农业数据可视化与决策系统 v1.3</b><br><br>"
                       "本系统集数据监控、图表可视化和智能决策支持于一体。<br><br>"
                       "<b>功能:</b><ul>"
                       "<li>实时传感器数据显示与历史趋势分析。</li>"
                       "<li>基于随机森林算法的智能施肥建议。</li>"
                       "<li>仪表盘实时监控。</li>"
                       "<li>图表交互与数据导出。");
}

void SystemWindow::updateDashboard()
{
    if (!m_cropAreaCombo || m_cropAreaCombo->currentIndex() < 0) return;
    int cropAreaId = m_cropAreaCombo->currentData().toInt();
    QVariantMap latestData = DataBaseManager::instance().GetLatestSoilAndThData(cropAreaId);
    if(m_tempGauge) m_tempGauge->setValue(latestData.value("temp", 0).toDouble());
    if(m_humidityGauge) m_humidityGauge->setValue(latestData.value("shum", 0).toDouble()*100);
}

void SystemWindow::populateCropAreaCombo()
{
    if (!m_cropAreaCombo) {
        qWarning() << "populateCropAreaCombo called but m_cropAreaCombo is null!";
        return;
    }

    m_cropAreaCombo->blockSignals(true);
    m_cropAreaCombo->clear();

    QVariantList allAreasFromDB = DataBaseManager::instance().GetAllCropAreas();

    for (int accessibleId :m_userCropIds) {
        for (const QVariant& areaVar : allAreasFromDB) {
            QVariantList details = areaVar.toList();
            if (details.size() >= 3 && details.at(0).toInt() == accessibleId) {
                QString cropType = details.at(2).toString();
                QString displayName = QString("作物区 %1 (%2)")
                                          .arg(accessibleId)
                                          .arg(cropType);
                m_cropAreaCombo->addItem(displayName, accessibleId);
                break;
            }
        }
    }

    m_cropAreaCombo->blockSignals(false);

    if (m_cropAreaCombo->count() > 0) {
        m_cropAreaCombo->setCurrentIndex(0);
    }
}

void SystemWindow::loadAndDisplayData(const QDateTime &start, const QDateTime &end)
{
    if (!m_series || !m_cropAreaCombo || m_cropAreaCombo->currentIndex() < 0) return;
    m_series->clear();

    int cropAreaId = m_cropAreaCombo->currentData().toInt();
    int dataTypeIndex = m_dataTypeCombo->currentIndex();
    QString startStr = start.toString(Qt::ISODate);
    QString endStr = end.toString(Qt::ISODate);

    QVariantList dataList;
    if (dataTypeIndex < 4) dataList = DataBaseManager::instance().GetSAThData(cropAreaId, startStr, endStr);
    else dataList = DataBaseManager::instance().GetSASoilData(cropAreaId, startStr, endStr);

    QList<QPointF> points;
    double minV = 1e9, maxV = -1e9;

    // 判断时间跨度
    qint64 days = start.daysTo(end);
    if (days >= 5) {
        // 按小时分组取平均
        QMap<qint64, QList<double>> groupMap; // key: 小时起点时间戳, value: 数据值列表
        for (const QVariant& rowVar : dataList) {
            QVariantList row = rowVar.toList();
            QDateTime dt = QDateTime::fromString(row.last().toString(), "yyyy-MM-ddTHH:mm:ss");
            if (!dt.isValid()) dt = QDateTime::fromString(row.last().toString(), Qt::ISODate);
            if(!dt.isValid()) continue;
            double val = 0.0;
            switch(dataTypeIndex) {
            case 0: val = row[0].toDouble(); break;
            case 1: val = row[2].toDouble(); break;
            case 2: val = row[3].toDouble(); break;
            case 3: val = row[1].toDouble(); break;
            case 4: val = row[0].toDouble(); break;
            case 5: val = row[1].toDouble(); break;
            case 6: val = row[2].toDouble(); break;
            }
            // 取整到小时
            QDateTime hour = dt;
            hour.setTime(QTime(dt.time().hour(), 0, 0));
            qint64 hourMs = hour.toMSecsSinceEpoch();
            groupMap[hourMs].append(val);
        }
        for (auto it = groupMap.begin(); it != groupMap.end(); ++it) {
            double sum = 0;
            for (double v : it.value()) sum += v;
            double avg = it.value().isEmpty() ? 0 : sum / it.value().size();
            points.append(QPointF(it.key(), avg));
            if (avg < minV) minV = avg;
            if (avg > maxV) maxV = avg;
        }
    } else {
        // 原有方式
        for (const QVariant& rowVar : dataList) {
            QVariantList row = rowVar.toList();
            QDateTime dt = QDateTime::fromString(row.last().toString(), "yyyy-MM-ddTHH:mm:ss");
            if (!dt.isValid()) dt = QDateTime::fromString(row.last().toString(), Qt::ISODate);
            if(!dt.isValid()) continue;
            double val = 0.0;
            switch(dataTypeIndex) {
            case 0: val = row[0].toDouble(); break;
            case 1: val = row[2].toDouble(); break;
            case 2: val = row[3].toDouble(); break;
            case 3: val = row[1].toDouble(); break;
            case 4: val = row[0].toDouble(); break;
            case 5: val = row[1].toDouble(); break;
            case 6: val = row[2].toDouble(); break;
            }
            points.append(QPointF(dt.toMSecsSinceEpoch(), val));
            if (val < minV) { minV = val; }
            if (val > maxV) { maxV = val; }
        }
    }

    m_series->replace(points);
    m_axisX->setRange(start, end);
    if(!points.isEmpty()) m_axisY->setRange(minV - (maxV-minV)*0.1 - 1, maxV + (maxV-minV)*0.1 + 1); else m_axisY->setRange(0, 100);
    m_chart->setTitle(m_cropAreaCombo->currentText() + " - " + m_dataTypeCombo->currentText());
    m_axisY->setTitleText(m_dataTypeCombo->currentText().split('(').first());

    updatePieChart(cropAreaId, start, end);
}

void SystemWindow::updatePieChart(int cropAreaId, const QDateTime &startTime, const QDateTime &endTime)
{
    if (!m_pieSeries || !m_pieChart) return;
    m_pieSeries->clear();
    QVariantList soilData = DataBaseManager::instance().GetSASoilData(cropAreaId, startTime.toString(Qt::ISODate), endTime.toString(Qt::ISODate));
    if(soilData.isEmpty()) {
        m_pieChart->setTitle("当前时段无土壤元素数据");
        return;
    }
    double n_sum = 0, p_sum = 0, k_sum = 0;
    for(const auto& rowVar : soilData) {
        QVariantList row = rowVar.toList();
        n_sum += row[0].toDouble(); p_sum += row[1].toDouble(); k_sum += row[2].toDouble();
    }
    double count = soilData.size();
    if (count == 0) {
        m_pieChart->setTitle("当前时段无土壤元素数据");
        return;
    }

    m_pieSeries->append("氮(N)", n_sum / count);
    m_pieSeries->append("磷(P)", p_sum / count);
    m_pieSeries->append("钾(K)", k_sum / count);
    for(QPieSlice *slice : m_pieSeries->slices()){
        slice->setLabel(QString("%1\n%2%").arg(slice->label()).arg(slice->percentage() * 100, 0, 'f', 1));
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
    }
    m_pieChart->setTitle("土壤 N-P-K 平均含量");
}

QString SystemWindow::translateCropType(const QString& chineseCropType)
{
    static const QMap<QString, QString> translationMap = {
        {"甘蔗", "Sugarcane"}, {"小米/谷子", "Millets"}, {"大麦", "Barley"},
        {"水稻", "Paddy"},   {"豆类", "Pulses"},     {"烟草", "Tobacco"},
        {"花生", "Ground Nuts"}, {"玉米", "Maize"},      {"棉花", "Cotton"},
        {"小麦", "Wheat"},   {"油籽作物", "Oil seeds"}
    };
    return translationMap.value(chineseCropType, "Wheat");
}

QString SystemWindow::getCurrentEnvironmentData()
{
    if (m_cropAreaCombo == nullptr || m_cropAreaCombo->currentIndex() < 0) return "";
    int cropAreaId = m_cropAreaCombo->currentData().toInt();
    QVariantMap latestData = DataBaseManager::instance().GetLatestSoilAndThData(cropAreaId);
    if (latestData.size() < 7) {
        qWarning() << "获取最新数据不完整，无法进行预测。";
        return "";
    }

    QString soilType = "Loamy";
    QString cropTypeChinese = "Wheat";
    QVariantList allAreas = DataBaseManager::instance().GetAllCropAreas();
    for(const auto& areaVar : allAreas) {
        QVariantList areaDetails = areaVar.toList();
        if(areaDetails.size() >= 6 && areaDetails.first().toInt() == cropAreaId) {
            cropTypeChinese = areaDetails[2].toString();
            QString detail = areaDetails[5].toString().toLower();
            if (detail.contains("sandy") || detail.contains("沙")) soilType = "Sandy";
            else if (detail.contains("clay") || detail.contains("黏")) soilType = "Clay";
            else if (detail.contains("red") || detail.contains("红")) soilType = "Red";
            else if (detail.contains("black") || detail.contains("黑")) soilType = "Black";
            break;
        }
    }

    QString cropTypeEnglish = translateCropType(cropTypeChinese);

    return QString("%1 %2 %3 %4 %5 %6 %7 %8")
        .arg(latestData["temp"].toDouble()).arg(latestData["hum"].toDouble()).arg(latestData["shum"].toDouble())
        .arg(soilType).arg(cropTypeEnglish)
        .arg(latestData["N"].toDouble()).arg(latestData["K"].toDouble()).arg(latestData["P"].toDouble());
}

void SystemWindow::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    QMainWindow::closeEvent(event);
}

// 新增：无参版本，兼容原有调用
void SystemWindow::loadAndDisplayData() {
    if (!m_startTimeEdit || !m_endTimeEdit) return;
    loadAndDisplayData(m_startTimeEdit->dateTime(), m_endTimeEdit->dateTime());
}
