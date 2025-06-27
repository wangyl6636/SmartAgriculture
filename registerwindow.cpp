#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "databasemanager.h"

#include <QRegularExpression>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

static bool islegal=true;

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    //初始化界面信息
    //设置labelPhoneTip文本
    ui->labelPhoneTip->setText("输入正确的手机号");
    ui->labelPhoneTip->setStyleSheet("color:grey;");

    //连接函数
    // 实时检测手机号输入
    connect(ui->lineEditPhone, &QLineEdit::textChanged, this, &RegisterWindow::onPhoneTextChanged);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::onPhoneTextChanged(const QString &text)
{
    // 使用正则表达式验证格式正确性
    QRegularExpression reg("^1\\d{10}$");
    if (reg.match(text).hasMatch()) {
        ui->labelPhoneTip->setText("格式正确");
        ui->labelPhoneTip->setStyleSheet("color:green;");
        islegal=true;
    } else {
        ui->labelPhoneTip->setText("手机号格式不正确");
        ui->labelPhoneTip->setStyleSheet("color:red;");
        islegal=false;
    }
}



void RegisterWindow::on_pushButtonRegister_clicked()
{
    if(!islegal){
        QMessageBox::critical(this, "错误", "手机号格式不正确，请重新输入！");
        return;
    }

    DataBaseManager &db=DataBaseManager::instance();

    //查询注册的用户是否存在
    QString phone = ui->lineEditPhone->text();
    if (db.IsUserExists(phone)) {
        QMessageBox::warning(this, "警告", "该手机号已被注册，请使用其他手机号！");
        ui->lineEditPhone->clear();
        return;
    }

    //获取输入的用户名和密码以及角色
    QString username = ui->lineEditName->text();
    QString passwd = ui->lineEditPassword->text();
    QString role=ui->comboBoxRole->currentText();

    //将角色转换为英文
    if (role == "农户"){
        role = "farmer";
    } 
    else if (role == "专家") {
        role = "expert";
    } else if (role == "管理员") {
        role = "admin";
    }

    //检查用户名和密码是否为空
    if (username.isEmpty() || passwd.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名和密码不能为空，请重新输入！");
        return;
    }

    //注册用户
    QString sqlErrorMsg;
    if (db.AddUser(username, phone, passwd, role, &sqlErrorMsg)) {
        QMessageBox::information(this, "成功", "注册成功！");
        this->close(); // 关闭注册窗口
    } else {
        QMessageBox::critical(this, "错误", QString("注册失败，请稍后再试！\n错误信息：%1").arg(sqlErrorMsg));
    }
}

void RegisterWindow::closeEvent(QCloseEvent *event)
{
    emit closedSignal();
    QMainWindow::closeEvent(event);
}

void RegisterWindow::on_comboBoxRole_activated(int index)
{
    if(index==1){
        ui->labelField->setVisible(true);
        ui->lineEditField->setVisible(true);
    }else{
        ui->labelField->setVisible(false);
        ui->lineEditField->setVisible(false);
    }
}

