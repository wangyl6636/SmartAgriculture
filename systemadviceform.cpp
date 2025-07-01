#include "systemadviceform.h"
#include "ui_systemadviceform.h"
#include <QCloseEvent>
#include "databasemanager.h"
#include <QMessageBox>

SystemAdviceForm::SystemAdviceForm(int id, int roleIndex, QWidget *parent)
    : QWidget(parent),id(id),roleIndex(roleIndex)
    , ui(new Ui::SystemAdviceForm)
{
    ui->setupUi(this);
    connect(ui->submitButton, &QPushButton::clicked, this, &SystemAdviceForm::onSubmitButtonClicked);
}

SystemAdviceForm::~SystemAdviceForm()
{
    delete ui;
}

void SystemAdviceForm::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
    event->accept();
}

void SystemAdviceForm::onSubmitButtonClicked()
{
    QString content = ui->adviceTextEdit->toPlainText().trimmed();
    if(content.isEmpty()) {
        QMessageBox::warning(this, "提示", "建议内容不能为空！");
        return;
    }
    bool ok = DataBaseManager::instance().AddModelOptimization(id, roleIndex, content);
    if(ok) {
        QMessageBox::information(this, "成功", "建议提交成功！");
        ui->adviceTextEdit->clear();
    } else {
        QMessageBox::critical(this, "错误", "建议提交失败：" + DataBaseManager::instance().GetLastError());
    }
}
