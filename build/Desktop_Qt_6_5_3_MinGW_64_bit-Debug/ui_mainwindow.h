/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *centralLayout;
    QSpacerItem *verticalSpacerTop;
    QFrame *loginFrame;
    QVBoxLayout *loginLayout;
    QLabel *labelTitle;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPhone;
    QLineEdit *lineEditPhone;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelRole;
    QComboBox *comboBoxRole;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonRegister;
    QPushButton *pushButtonSwitchMode;
    QSpacerItem *verticalSpacerBottom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralLayout = new QVBoxLayout(centralwidget);
        centralLayout->setObjectName("centralLayout");
        verticalSpacerTop = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        centralLayout->addItem(verticalSpacerTop);

        loginFrame = new QFrame(centralwidget);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setMinimumSize(QSize(360, 340));
        loginFrame->setStyleSheet(QString::fromUtf8("\n"
"        QFrame#loginFrame {\n"
"            background: #fff;\n"
"            border-radius: 16px;\n"
"            border: 1px solid #e0e0e0;\n"
"        }\n"
"       "));
        loginFrame->setFrameShape(QFrame::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Raised);
        loginLayout = new QVBoxLayout(loginFrame);
        loginLayout->setObjectName("loginLayout");
        labelTitle = new QLabel(loginFrame);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 80));
        labelTitle->setMaximumSize(QSize(16777215, 80));
        labelTitle->setStyleSheet(QString::fromUtf8("\n"
"           font-size: 26px;\n"
"           font-weight: bold;\n"
"           color: #2e7d32;\n"
"           margin-bottom: 18px;\n"
"          "));
        labelTitle->setAlignment(Qt::AlignCenter);

        loginLayout->addWidget(labelTitle);

        labelName = new QLabel(loginFrame);
        labelName->setObjectName("labelName");
        labelName->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        loginLayout->addWidget(labelName);

        lineEditName = new QLineEdit(loginFrame);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));

        loginLayout->addWidget(lineEditName);

        labelPhone = new QLabel(loginFrame);
        labelPhone->setObjectName("labelPhone");
        labelPhone->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        loginLayout->addWidget(labelPhone);

        lineEditPhone = new QLineEdit(loginFrame);
        lineEditPhone->setObjectName("lineEditPhone");
        lineEditPhone->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));

        loginLayout->addWidget(lineEditPhone);

        labelPassword = new QLabel(loginFrame);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        loginLayout->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(loginFrame);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        loginLayout->addWidget(lineEditPassword);

        labelRole = new QLabel(loginFrame);
        labelRole->setObjectName("labelRole");
        labelRole->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        loginLayout->addWidget(labelRole);

        comboBoxRole = new QComboBox(loginFrame);
        comboBoxRole->addItem(QString());
        comboBoxRole->addItem(QString());
        comboBoxRole->addItem(QString());
        comboBoxRole->setObjectName("comboBoxRole");
        comboBoxRole->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           font-size: 15px;\n"
"           padding-left: 8px;\n"
"          "));

        loginLayout->addWidget(comboBoxRole);

        pushButtonLogin = new QPushButton(loginFrame);
        pushButtonLogin->setObjectName("pushButtonLogin");
        pushButtonLogin->setStyleSheet(QString::fromUtf8("\n"
"           background-color: #388e3c;\n"
"           color: #fff;\n"
"           border-radius: 6px;\n"
"           font-size: 16px;\n"
"           font-weight: bold;\n"
"           margin-top: 12px;\n"
"          "));

        loginLayout->addWidget(pushButtonLogin);

        pushButtonRegister = new QPushButton(loginFrame);
        pushButtonRegister->setObjectName("pushButtonRegister");
        pushButtonRegister->setStyleSheet(QString::fromUtf8("\n"
"           background-color: #1976d2;\n"
"           color: #fff;\n"
"           border-radius: 6px;\n"
"           font-size: 16px;\n"
"           font-weight: bold;\n"
"           margin-top: 8px;\n"
"          "));

        loginLayout->addWidget(pushButtonRegister);

        pushButtonSwitchMode = new QPushButton(loginFrame);
        pushButtonSwitchMode->setObjectName("pushButtonSwitchMode");
        pushButtonSwitchMode->setStyleSheet(QString::fromUtf8("\n"
"           background: transparent;\n"
"           color: #1976d2;\n"
"           border: none;\n"
"           font-size: 14px;\n"
"           margin-top: 4px;\n"
"           text-decoration: underline;\n"
"          "));

        loginLayout->addWidget(pushButtonSwitchMode);


        centralLayout->addWidget(loginFrame);

        verticalSpacerBottom = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        centralLayout->addItem(verticalSpacerBottom);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\347\231\273\345\275\225", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\345\271\263\345\217\260", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        labelPhone->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        labelRole->setText(QCoreApplication::translate("MainWindow", "\350\247\222\350\211\262", nullptr));
        comboBoxRole->setItemText(0, QCoreApplication::translate("MainWindow", "\345\206\234\346\210\267", nullptr));
        comboBoxRole->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\223\345\256\266", nullptr));
        comboBoxRole->setItemText(2, QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230", nullptr));

        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        pushButtonSwitchMode->setText(QCoreApplication::translate("MainWindow", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
