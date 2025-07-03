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
    QLabel *labelCropType;
    QLineEdit *lineEditCropType;
    QLabel *labelArea;
    QLineEdit *lineEditArea;
    QLabel *labelAreaTip;
    QLabel *labelLocation;
    QLineEdit *lineEditLocation;
    QLabel *labelDetail;
    QLineEdit *lineEditDetail;
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

        labelCropType = new QLabel(registerFrame);
        labelCropType->setObjectName("labelCropType");
        labelCropType->setVisible(true);

        registerLayout->addWidget(labelCropType);

        lineEditCropType = new QLineEdit(registerFrame);
        lineEditCropType->setObjectName("lineEditCropType");
        lineEditCropType->setVisible(true);

        registerLayout->addWidget(lineEditCropType);

        labelArea = new QLabel(registerFrame);
        labelArea->setObjectName("labelArea");
        labelArea->setVisible(true);

        registerLayout->addWidget(labelArea);

        lineEditArea = new QLineEdit(registerFrame);
        lineEditArea->setObjectName("lineEditArea");
        lineEditArea->setVisible(true);

        registerLayout->addWidget(lineEditArea);

        labelAreaTip = new QLabel(registerFrame);
        labelAreaTip->setObjectName("labelAreaTip");
        labelAreaTip->setVisible(true);

        registerLayout->addWidget(labelAreaTip);

        labelLocation = new QLabel(registerFrame);
        labelLocation->setObjectName("labelLocation");
        labelLocation->setVisible(true);

        registerLayout->addWidget(labelLocation);

        lineEditLocation = new QLineEdit(registerFrame);
        lineEditLocation->setObjectName("lineEditLocation");
        lineEditLocation->setVisible(true);

        registerLayout->addWidget(lineEditLocation);

        labelDetail = new QLabel(registerFrame);
        labelDetail->setObjectName("labelDetail");
        labelDetail->setVisible(true);

        registerLayout->addWidget(labelDetail);

        lineEditDetail = new QLineEdit(registerFrame);
        lineEditDetail->setObjectName("lineEditDetail");
        lineEditDetail->setVisible(true);

        registerLayout->addWidget(lineEditDetail);

        labelField = new QLabel(registerFrame);
        labelField->setObjectName("labelField");
        labelField->setVisible(false);

        registerLayout->addWidget(labelField);

        lineEditField = new QLineEdit(registerFrame);
        lineEditField->setObjectName("lineEditField");
        lineEditField->setVisible(false);

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
        labelRole->setStyleSheet(QString());
        labelRole->setText(QCoreApplication::translate("RegisterWindow", "\350\247\222\350\211\262", nullptr));
        comboBoxRole->setItemText(0, QCoreApplication::translate("RegisterWindow", "\345\206\234\346\210\267", nullptr));
        comboBoxRole->setItemText(1, QCoreApplication::translate("RegisterWindow", "\344\270\223\345\256\266", nullptr));

        labelCropType->setText(QCoreApplication::translate("RegisterWindow", "\344\275\234\347\211\251\347\261\273\345\236\213", nullptr));
        labelArea->setText(QCoreApplication::translate("RegisterWindow", "\351\235\242\347\247\257\357\274\210\344\272\251\357\274\211", nullptr));
        labelAreaTip->setText(QCoreApplication::translate("RegisterWindow", "TextLabel", nullptr));
        labelLocation->setText(QCoreApplication::translate("RegisterWindow", "\345\234\260\347\202\271", nullptr));
        labelDetail->setText(QCoreApplication::translate("RegisterWindow", "\350\257\246\346\203\205", nullptr));
        labelField->setText(QCoreApplication::translate("RegisterWindow", "\346\223\205\351\225\277\351\242\206\345\237\237", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("RegisterWindow", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
