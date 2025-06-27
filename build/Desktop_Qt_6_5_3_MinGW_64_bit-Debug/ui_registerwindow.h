/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *centralLayout;
    QSpacerItem *verticalSpacerTop;
    QFrame *registerFrame;
    QVBoxLayout *registerLayout;
    QLabel *labelTitle;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPhone;
    QLineEdit *lineEditPhone;
    QLabel *labelPhoneTip;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelRole;
    QComboBox *comboBoxRole;
    QLabel *labelField;
    QLineEdit *lineEditField;
    QPushButton *pushButtonRegister;
    QSpacerItem *verticalSpacerBottom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(800, 600);
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName("centralwidget");
        centralLayout = new QVBoxLayout(centralwidget);
        centralLayout->setObjectName("centralLayout");
        verticalSpacerTop = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding);

        centralLayout->addItem(verticalSpacerTop);

        registerFrame = new QFrame(centralwidget);
        registerFrame->setObjectName("registerFrame");
        registerFrame->setMinimumSize(QSize(360, 380));
        registerFrame->setStyleSheet(QString::fromUtf8("\n"
"        QFrame#registerFrame {\n"
"            background: #fff;\n"
"            border-radius: 16px;\n"
"            border: 1px solid #e0e0e0;\n"
"        }\n"
"       "));
        registerFrame->setFrameShape(QFrame::StyledPanel);
        registerFrame->setFrameShadow(QFrame::Raised);
        registerLayout = new QVBoxLayout(registerFrame);
        registerLayout->setObjectName("registerLayout");
        labelTitle = new QLabel(registerFrame);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 80));
        labelTitle->setMaximumSize(QSize(16777215, 80));
        labelTitle->setStyleSheet(QString::fromUtf8("\n"
"           font-size: 26px;\n"
"           font-weight: bold;\n"
"           color: #1976d2;\n"
"           margin-bottom: 18px;\n"
"          "));
        labelTitle->setAlignment(Qt::AlignCenter);

        registerLayout->addWidget(labelTitle);

        labelName = new QLabel(registerFrame);
        labelName->setObjectName("labelName");
        labelName->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        registerLayout->addWidget(labelName);

        lineEditName = new QLineEdit(registerFrame);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));

        registerLayout->addWidget(lineEditName);

        labelPhone = new QLabel(registerFrame);
        labelPhone->setObjectName("labelPhone");
        labelPhone->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        registerLayout->addWidget(labelPhone);

        lineEditPhone = new QLineEdit(registerFrame);
        lineEditPhone->setObjectName("lineEditPhone");
        lineEditPhone->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));

        registerLayout->addWidget(lineEditPhone);

        labelPhoneTip = new QLabel(registerFrame);
        labelPhoneTip->setObjectName("labelPhoneTip");

        registerLayout->addWidget(labelPhoneTip);

        labelPassword = new QLabel(registerFrame);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        registerLayout->addWidget(labelPassword);

        lineEditPassword = new QLineEdit(registerFrame);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        registerLayout->addWidget(lineEditPassword);

        labelRole = new QLabel(registerFrame);
        labelRole->setObjectName("labelRole");
        labelRole->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        registerLayout->addWidget(labelRole);

        comboBoxRole = new QComboBox(registerFrame);
        comboBoxRole->addItem(QString());
        comboBoxRole->addItem(QString());
        comboBoxRole->setObjectName("comboBoxRole");
        comboBoxRole->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           font-size: 15px;\n"
"           padding-left: 8px;\n"
"          "));

        registerLayout->addWidget(comboBoxRole);

        labelField = new QLabel(registerFrame);
        labelField->setObjectName("labelField");
        labelField->setVisible(false);
        labelField->setStyleSheet(QString::fromUtf8("font-size: 15px; color: #555;"));

        registerLayout->addWidget(labelField);

        lineEditField = new QLineEdit(registerFrame);
        lineEditField->setObjectName("lineEditField");
        lineEditField->setVisible(false);
        lineEditField->setStyleSheet(QString::fromUtf8("\n"
"           border: 1px solid #bdbdbd;\n"
"           border-radius: 6px;\n"
"           padding-left: 8px;\n"
"           font-size: 15px;\n"
"          "));

        registerLayout->addWidget(lineEditField);

        pushButtonRegister = new QPushButton(registerFrame);
        pushButtonRegister->setObjectName("pushButtonRegister");
        pushButtonRegister->setStyleSheet(QString::fromUtf8("\n"
"           background-color: #1976d2;\n"
"           color: #fff;\n"
"           border-radius: 6px;\n"
"           font-size: 16px;\n"
"           font-weight: bold;\n"
"           margin-top: 12px;\n"
"          "));

        registerLayout->addWidget(pushButtonRegister);


        centralLayout->addWidget(registerFrame);

        verticalSpacerBottom = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        centralLayout->addItem(verticalSpacerBottom);

        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName("statusbar");
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "\346\231\272\346\205\247\345\206\234\344\270\232\346\263\250\345\206\214", nullptr));
        labelTitle->setText(QCoreApplication::translate("RegisterWindow", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        labelName->setText(QCoreApplication::translate("RegisterWindow", "\345\247\223\345\220\215", nullptr));
        labelPhone->setText(QCoreApplication::translate("RegisterWindow", "\346\211\213\346\234\272\345\217\267", nullptr));
        labelPhoneTip->setText(QCoreApplication::translate("RegisterWindow", "TextLabel", nullptr));
        labelPassword->setText(QCoreApplication::translate("RegisterWindow", "\345\257\206\347\240\201", nullptr));
        labelRole->setText(QCoreApplication::translate("RegisterWindow", "\350\247\222\350\211\262", nullptr));
        comboBoxRole->setItemText(0, QCoreApplication::translate("RegisterWindow", "\345\206\234\346\210\267", nullptr));
        comboBoxRole->setItemText(1, QCoreApplication::translate("RegisterWindow", "\344\270\223\345\256\266", nullptr));

        labelField->setText(QCoreApplication::translate("RegisterWindow", "\351\242\206\345\237\237\357\274\210\344\273\205\344\270\223\345\256\266\345\241\253\345\206\231\357\274\211", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("RegisterWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
