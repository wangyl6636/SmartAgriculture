#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "databasemanager.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    loadAdviceList(); // 进入界面自动加载
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::clearAdviceCards()
{
    QLayout *layout = ui->adviceLayout;
    // 保留emptyLabel，其余全部删除
    for (int i = layout->count() - 1; i >= 0; --i) {
        QLayoutItem *item = layout->itemAt(i);
        QWidget *widget = item->widget();
        if (widget && widget != ui->emptyLabel) {
            delete widget;
        }
    }
}

void AdminWindow::loadAdviceList()
{
    clearAdviceCards();
    DataBaseManager &db = DataBaseManager::instance();
    QVariantList adviceList = db.GetModelOptimizations();
    if (adviceList.isEmpty()) {
        ui->emptyLabel->setVisible(true);
        return;
    }
    ui->emptyLabel->setVisible(false);
    for (const QVariant &item : adviceList) {
        addAdviceCard(item.toList());
    }
}

void AdminWindow::addAdviceCard(const QVariantList &advice)
{
    // 假设字段顺序: id, user_id, role, content
    QString content = advice.value(3).toString();
    QString userId = advice.value(1).toString();
    QString role = advice.value(2).toString();
    QString id = advice.value(0).toString();
    QWidget *card = new QWidget();
    card->setMinimumHeight(80);
    card->setStyleSheet("QWidget { background: #ffffff; border-radius: 12px; padding: 18px; border: 1px solid #e0e6ed; margin-bottom: 8px; }");
    QVBoxLayout *vbox = new QVBoxLayout(card);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(6);
    QLabel *contentLabel = new QLabel(content);
    contentLabel->setStyleSheet("font-size: 15px; color: #2c3e50; font-weight: bold;");
    contentLabel->setWordWrap(true);
    vbox->addWidget(contentLabel);
    QLabel *metaLabel = new QLabel(QString("建议ID: %1  用户ID: %2  角色: %3").arg(id, userId, role));
    metaLabel->setStyleSheet("font-size: 12px; color: #95a5a6; margin-top: 4px;");
    vbox->addWidget(metaLabel);
    ui->adviceLayout->addWidget(card);
}

void AdminWindow::on_pushButton_refresh_clicked()
{
    clearAdviceCards();
    loadAdviceList();
}

