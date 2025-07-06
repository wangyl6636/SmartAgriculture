#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "databasemanager.h"

#include <QRegularExpression>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

static bool islegal=false;

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    //初始化界面信息
    //设置labelPhoneTip文本
    ui->labelPhoneTip->setText("输入正确的手机号");
    ui->labelPhoneTip->setStyleSheet("color:grey;");

    //设置labelAreaTip文本
    ui->labelAreaTip->setText("允许最多 4 位整数和最多 2 位小数");
    ui->labelAreaTip->setStyleSheet("color:grey;");

    //设置labelArea输入
    // 定义正则表达式，允许最多 4 位整数和最多 2 位小数
    QRegularExpression reg("^[0-9]{1,4}(\\.[0-9]{1,2})?$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(reg, this);
    ui->lineEditArea->setValidator(validator);

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

    //判断数据库是否连接
    if (!db.TestConnection()) {
        QMessageBox::warning(this, "警告", "数据库连接不稳定，请检查网络后重试！");
        return;
    }

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
    } else if (role == "专家") {
        role = "expert";
    }

    //检查用户名和密码是否为空
    if (username.isEmpty() || passwd.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名和密码不能为空，请重新输入！");
        return;
    }

    //注册用户
    // 开始事务
    if (!db.BeginTransaction()) {
        QMessageBox::critical(this, "错误", "无法开始数据库事务");
        return;
    }

    QString sqlErrorMsg;
    int userId = db.AddUser(username, phone, passwd, role, &sqlErrorMsg);
    if (userId != -1) {
        //用户表注册成功，根据用户注册不同表
        bool success;
        if(role == "farmer"){
            //获取农户相关作物区信息
            QString cropType = ui->comboBoxCropType->currentText();
            float area = ui->lineEditArea->text().toFloat();
            QString location = ui->lineEditLocation->text();
            QString detail = ui->lineEditDetail->text();
            //检查相关作物区信息是否为空
            if(cropType.isEmpty() || area <= 0 || location.isEmpty() || detail.isEmpty()){
                QMessageBox::warning(this, "警告", "作物区信息不能为空，请重新输入！");
                return;
            }
            //注册农户作物区信息
            int farmerId = db.AddFarmerUser(userId);
            success = db.AddCropArea(farmerId, cropType, area, location, detail);

            if(!success){
                sqlErrorMsg = db.GetLastError();
                QMessageBox::critical(this, "错误", QString("信息注册失败，请稍后再试！\n错误信息：%1").arg(sqlErrorMsg));
                return;
            }

        }else{
            //检查领域信息是否为空
            QString field = ui->lineEditField->text();
            if(field.isEmpty()){
                QMessageBox::warning(this, "警告", "领域信息不能为空，请重新输入！");
                return;
            }
            //注册专家领域信息
            success = db.AddExpertUser(userId, field);
            if(!success){
                sqlErrorMsg = db.GetLastError();
                QMessageBox::critical(this, "错误", QString("信息注册失败，请稍后再试！\n错误信息：%1").arg(sqlErrorMsg));
                return;
            }
        }

        // 提交事务
        if (!db.CommitTransaction()) {
            db.RollbackTransaction();
            QMessageBox::critical(this, "错误", "提交注册信息失败");
            return;
        }

        QMessageBox::information(this, "成功", "注册成功！");
        this->close();
    } else {
        QMessageBox::critical(this, "错误", QString("注册失败，请稍后再试！\n错误信息：%1").arg(sqlErrorMsg));
        return;
    }
}

void RegisterWindow::closeEvent(QCloseEvent *event)
{
    emit closedSignal();
    QMainWindow::closeEvent(event);
}

//根据用户选择不同的注册选项
void RegisterWindow::on_comboBoxRole_activated(int index)
{
    if(index==1){
        ui->labelField->setVisible(true);
        ui->lineEditField->setVisible(true);

        ui->labelCropType->setVisible(false);
        ui->comboBoxCropType->setVisible(false);
        ui->labelArea->setVisible(false);
        ui->lineEditArea->setVisible(false);
        ui->labelLocation->setVisible(false);
        ui->lineEditLocation->setVisible(false);
        ui->labelDetail->setVisible(false);
        ui->lineEditDetail->setVisible(false);
        ui->labelAreaTip->setVisible(false);
    }else{
        ui->labelField->setVisible(false);
        ui->lineEditField->setVisible(false);

        ui->labelCropType->setVisible(true);
        ui->comboBoxCropType->setVisible(true);
        ui->labelArea->setVisible(true);
        ui->lineEditArea->setVisible(true);
        ui->labelLocation->setVisible(true);
        ui->lineEditLocation->setVisible(true);
        ui->labelDetail->setVisible(true);
        ui->lineEditDetail->setVisible(true);
        ui->labelAreaTip->setVisible(true);
    }
}
