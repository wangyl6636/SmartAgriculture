#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasemanager.h"

#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QPalette>
#include <QMessageBox>

static bool islegal=false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rWindow=nullptr;
    aWindow=nullptr;
    fWindow=nullptr;
    eWindow=nullptr;

    // 手机号正则验证
    QRegularExpression phoneReg("^1\\d{10}$");
    QRegularExpressionValidator *phoneValidator = new QRegularExpressionValidator(phoneReg, this);
    ui->lineEditPhone->setValidator(phoneValidator);
    connect(ui->lineEditPhone, &QLineEdit::textChanged, this, [this](const QString &text){
        if (text.isEmpty()) {
            ui->lineEditPhone->setStyleSheet("border: 1px solid #bdbdbd; border-radius: 6px; padding-left: 8px; font-size: 15px;");
            islegal=false;
        } else if (ui->lineEditPhone->hasAcceptableInput()) {
            ui->lineEditPhone->setStyleSheet("border: 1px solid #4caf50; border-radius: 6px; padding-left: 8px; font-size: 15px; background: #e8f5e9;");
            islegal=true;
        } else {
            ui->lineEditPhone->setStyleSheet("border: 1px solid #e53935; border-radius: 6px; padding-left: 8px; font-size: 15px; background: #ffebee;");
            islegal=false;
        }
    });

    //多方转入注册界面
    connect(ui->pushButtonSwitchMode, &QPushButton::clicked, this, &MainWindow::on_pushButtonRegister_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//注册按钮点击事件
// 当用户点击注册按钮时，隐藏主窗口并显示注册窗口
void MainWindow::on_pushButtonRegister_clicked()
{
    qDebug() << "Switching to Register Window";
    this->hide();
    if(rWindow==nullptr){
        rWindow=new RegisterWindow();
        qDebug() << "Creating new RegisterWindow instance";
        connect(rWindow, &RegisterWindow::closedSignal, this, &MainWindow::ReShow);
    }
    rWindow->show();
}

//保证注册界面的临时窗口被关闭后，主窗口重新显示
// 这里使用了信号槽机制，当RegisterWindow关闭时，触发MainWindow的ReShow槽函数
// 这样可以确保主窗口在注册窗口关闭后重新显示，而不是直接删除主窗口实例
// 这种方式可以避免直接删除主窗口实例，保持应用程序的稳定性和一致性
void MainWindow::ReShow(){
    this->show();
    delete rWindow;
    rWindow=nullptr;
}

//登录
void MainWindow::on_pushButtonLogin_clicked()
{
    if(!islegal) {
        QMessageBox::critical(this, "错误", "手机号格式不正确，请重新输入！");
        return;
    }

    // 获取用户输入信息
    QString name = ui->lineEditName->text();
    if (name.isEmpty()) {  
        QMessageBox::warning(this, "警告", "用户名不能为空，请输入用户名！");
        return;
    }

    QString phone = ui->lineEditPhone->text();
    QString password = ui->lineEditPassword->text();
    QString role = ui->comboBoxRole->currentText();

    //转换角色为英文，以便数据库
    if(role == "管理员") {
        role = "admin";
    } else if(role == "农户") {
        role = "farmer";
    }else if(role == "专家") {
        role = "expert";
    } 

    // 检查用户登录
    DataBaseManager &db = DataBaseManager::instance();
    QString userRole;

    //判断数据库是否连接
    if (!db.TestConnection()) {
        QMessageBox::warning(this, "警告", "数据库连接不稳定，请检查网络后重试！");
        return;
    }

    if (db.CheckUserLogin(name, phone, password, userRole)) {
        if (userRole == role) {
            // 登录成功，跳转到对应的界面
            if (role == "admin") {
                // 跳转到管理员界面
                aWindow = new AdminWindow();
                aWindow->show();
            } else if (role == "farmer") {
                // 跳转到农户界面
                int userId = db.GetUserIdByPhone(phone);
                int farmerId = db.GetFarmerId(userId);

                qDebug()<<"当前农户用户id："<<userId;
                qDebug()<<"当前农户id："<<farmerId;

                fWindow = new FarmerWindow(farmerId);
                fWindow->show();
            } else if (role == "expert") {
                // 跳转到专家界面
                eWindow = new ExpertWindow();
                eWindow->show();
            }
            this->hide(); // 隐藏登录窗口
        } else {
            QMessageBox::warning(this, "警告", "登录失败，请检查手机号、密码和角色是否匹配！");
        }
    } else {
        QMessageBox::critical(this, "错误", "登录失败，请检查手机号和密码是否正确！");
    }
}
