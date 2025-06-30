/********************************************************************************
** Form generated from reading UI file 'changeinfowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFOWINDOW_H
#define UI_CHANGEINFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfoWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QGroupBox *basicInfoGroup;
    QFormLayout *basicInfoLayout;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *confirmPasswordLabel;
    QLineEdit *confirmPasswordEdit;
    QStackedWidget *roleSpecificStack;
    QWidget *farmerPage;
    QVBoxLayout *farmerLayout;
    QLabel *cropAreaTitle;
    QScrollArea *cropAreaScroll;
    QWidget *cropAreaList;
    QVBoxLayout *cropAreaLayout;
    QWidget *widget;
    QHBoxLayout *hboxLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *cropTypeLabel;
    QLabel *label1;
    QLabel *cropAreaLabel;
    QLabel *label2;
    QLabel *cropLocationLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *modifyCropButton;
    QLabel *noCropLabel;
    QPushButton *addCropButton;
    QWidget *expertPage;
    QVBoxLayout *expertLayout;
    QGroupBox *expertiseGroup;
    QHBoxLayout *expertiseLayout;
    QLineEdit *expertiseEdit;
    QPushButton *addCropButtonExpert;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChangeInfoWindow)
    {
        if (ChangeInfoWindow->objectName().isEmpty())
            ChangeInfoWindow->setObjectName("ChangeInfoWindow");
        ChangeInfoWindow->resize(800, 600);
        centralwidget = new QWidget(ChangeInfoWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(15);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(20, 20, 20, 20);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(titleLabel);

        basicInfoGroup = new QGroupBox(centralwidget);
        basicInfoGroup->setObjectName("basicInfoGroup");
        basicInfoLayout = new QFormLayout(basicInfoGroup);
        basicInfoLayout->setObjectName("basicInfoLayout");
        basicInfoLayout->setVerticalSpacing(15);
        basicInfoLayout->setHorizontalSpacing(20);
        nameLabel = new QLabel(basicInfoGroup);
        nameLabel->setObjectName("nameLabel");

        basicInfoLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameEdit = new QLineEdit(basicInfoGroup);
        nameEdit->setObjectName("nameEdit");

        basicInfoLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        phoneLabel = new QLabel(basicInfoGroup);
        phoneLabel->setObjectName("phoneLabel");

        basicInfoLayout->setWidget(1, QFormLayout::LabelRole, phoneLabel);

        phoneEdit = new QLineEdit(basicInfoGroup);
        phoneEdit->setObjectName("phoneEdit");

        basicInfoLayout->setWidget(1, QFormLayout::FieldRole, phoneEdit);

        passwordLabel = new QLabel(basicInfoGroup);
        passwordLabel->setObjectName("passwordLabel");

        basicInfoLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        passwordEdit = new QLineEdit(basicInfoGroup);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        basicInfoLayout->setWidget(2, QFormLayout::FieldRole, passwordEdit);

        confirmPasswordLabel = new QLabel(basicInfoGroup);
        confirmPasswordLabel->setObjectName("confirmPasswordLabel");

        basicInfoLayout->setWidget(3, QFormLayout::LabelRole, confirmPasswordLabel);

        confirmPasswordEdit = new QLineEdit(basicInfoGroup);
        confirmPasswordEdit->setObjectName("confirmPasswordEdit");
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);

        basicInfoLayout->setWidget(3, QFormLayout::FieldRole, confirmPasswordEdit);


        mainLayout->addWidget(basicInfoGroup);

        roleSpecificStack = new QStackedWidget(centralwidget);
        roleSpecificStack->setObjectName("roleSpecificStack");
        farmerPage = new QWidget();
        farmerPage->setObjectName("farmerPage");
        farmerLayout = new QVBoxLayout(farmerPage);
        farmerLayout->setSpacing(15);
        farmerLayout->setObjectName("farmerLayout");
        cropAreaTitle = new QLabel(farmerPage);
        cropAreaTitle->setObjectName("cropAreaTitle");

        farmerLayout->addWidget(cropAreaTitle);

        cropAreaScroll = new QScrollArea(farmerPage);
        cropAreaScroll->setObjectName("cropAreaScroll");
        cropAreaScroll->setWidgetResizable(true);
        cropAreaList = new QWidget();
        cropAreaList->setObjectName("cropAreaList");
        cropAreaLayout = new QVBoxLayout(cropAreaList);
        cropAreaLayout->setSpacing(10);
        cropAreaLayout->setObjectName("cropAreaLayout");
        cropAreaLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(cropAreaList);
        widget->setObjectName("widget");
        hboxLayout = new QHBoxLayout(widget);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cropTypeLabel = new QLabel(widget);
        cropTypeLabel->setObjectName("cropTypeLabel");

        formLayout->setWidget(0, QFormLayout::FieldRole, cropTypeLabel);

        label1 = new QLabel(widget);
        label1->setObjectName("label1");

        formLayout->setWidget(1, QFormLayout::LabelRole, label1);

        cropAreaLabel = new QLabel(widget);
        cropAreaLabel->setObjectName("cropAreaLabel");

        formLayout->setWidget(1, QFormLayout::FieldRole, cropAreaLabel);

        label2 = new QLabel(widget);
        label2->setObjectName("label2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label2);

        cropLocationLabel = new QLabel(widget);
        cropLocationLabel->setObjectName("cropLocationLabel");

        formLayout->setWidget(2, QFormLayout::FieldRole, cropLocationLabel);


        hboxLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        modifyCropButton = new QPushButton(widget);
        modifyCropButton->setObjectName("modifyCropButton");

        hboxLayout->addWidget(modifyCropButton);


        cropAreaLayout->addWidget(widget);

        noCropLabel = new QLabel(cropAreaList);
        noCropLabel->setObjectName("noCropLabel");
        noCropLabel->setAlignment(Qt::AlignCenter);
        noCropLabel->setVisible(false);

        cropAreaLayout->addWidget(noCropLabel);

        cropAreaScroll->setWidget(cropAreaList);

        farmerLayout->addWidget(cropAreaScroll);

        addCropButton = new QPushButton(farmerPage);
        addCropButton->setObjectName("addCropButton");

        farmerLayout->addWidget(addCropButton);

        roleSpecificStack->addWidget(farmerPage);
        expertPage = new QWidget();
        expertPage->setObjectName("expertPage");
        expertLayout = new QVBoxLayout(expertPage);
        expertLayout->setSpacing(15);
        expertLayout->setObjectName("expertLayout");
        expertiseGroup = new QGroupBox(expertPage);
        expertiseGroup->setObjectName("expertiseGroup");
        expertiseLayout = new QHBoxLayout(expertiseGroup);
        expertiseLayout->setObjectName("expertiseLayout");
        expertiseEdit = new QLineEdit(expertiseGroup);
        expertiseEdit->setObjectName("expertiseEdit");

        expertiseLayout->addWidget(expertiseEdit);


        expertLayout->addWidget(expertiseGroup);

        addCropButtonExpert = new QPushButton(expertPage);
        addCropButtonExpert->setObjectName("addCropButtonExpert");
        addCropButtonExpert->setVisible(false);

        expertLayout->addWidget(addCropButtonExpert);

        roleSpecificStack->addWidget(expertPage);

        mainLayout->addWidget(roleSpecificStack);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(20);
        buttonLayout->setObjectName("buttonLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        buttonLayout->addWidget(saveButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName("cancelButton");

        buttonLayout->addWidget(cancelButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_3);


        mainLayout->addLayout(buttonLayout);

        ChangeInfoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChangeInfoWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        ChangeInfoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChangeInfoWindow);
        statusbar->setObjectName("statusbar");
        ChangeInfoWindow->setStatusBar(statusbar);

        retranslateUi(ChangeInfoWindow);

        QMetaObject::connectSlotsByName(ChangeInfoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChangeInfoWindow)
    {
        ChangeInfoWindow->setWindowTitle(QCoreApplication::translate("ChangeInfoWindow", "\344\270\252\344\272\272\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        ChangeInfoWindow->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "background-color: #f5f7fa;", nullptr));
        titleLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\344\270\252\344\272\272\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        titleLabel->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"         font-size: 24px;\n"
"         font-weight: bold;\n"
"         color: #2c3e50;\n"
"         padding: 10px 0;\n"
"       ", nullptr));
        basicInfoGroup->setTitle(QCoreApplication::translate("ChangeInfoWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        basicInfoGroup->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"         QGroupBox {\n"
"           background-color: white;\n"
"           border-radius: 12px;\n"
"           padding: 20px;\n"
"           border: 1px solid #e0e6ed;\n"
"           margin-top: 10px;\n"
"         }\n"
"         QGroupBox::title {\n"
"           subcontrol-origin: margin;\n"
"           left: 10px;\n"
"           padding: 0 5px;\n"
"           font-weight: bold;\n"
"           font-size: 16px;\n"
"           color: #3498db;\n"
"         }\n"
"       ", nullptr));
        nameLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        nameLabel->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        nameEdit->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"            border: 1px solid #e0e6ed;\n"
"            border-radius: 6px;\n"
"            padding: 8px 12px;\n"
"            font-size: 14px;\n"
"          ", nullptr));
        phoneLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\347\224\265\350\257\235\357\274\232", nullptr));
        phoneLabel->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        phoneEdit->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"            border: 1px solid #e0e6ed;\n"
"            border-radius: 6px;\n"
"            padding: 8px 12px;\n"
"            font-size: 14px;\n"
"          ", nullptr));
        passwordLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        passwordLabel->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        passwordEdit->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"            border: 1px solid #e0e6ed;\n"
"            border-radius: 6px;\n"
"            padding: 8px 12px;\n"
"            font-size: 14px;\n"
"          ", nullptr));
        confirmPasswordLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        confirmPasswordLabel->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        confirmPasswordEdit->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"            border: 1px solid #e0e6ed;\n"
"            border-radius: 6px;\n"
"            padding: 8px 12px;\n"
"            font-size: 14px;\n"
"          ", nullptr));
        roleSpecificStack->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"         QGroupBox {\n"
"           background-color: white;\n"
"           border-radius: 12px;\n"
"           padding: 20px;\n"
"           border: 1px solid #e0e6ed;\n"
"         }\n"
"         QGroupBox::title {\n"
"           subcontrol-origin: margin;\n"
"           left: 10px;\n"
"           padding: 0 5px;\n"
"           font-weight: bold;\n"
"           font-size: 16px;\n"
"           color: #3498db;\n"
"         }\n"
"       ", nullptr));
        cropAreaTitle->setText(QCoreApplication::translate("ChangeInfoWindow", "\346\210\221\347\232\204\344\275\234\347\211\251\345\214\272", nullptr));
        cropAreaTitle->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"             font-size: 18px;\n"
"             font-weight: bold;\n"
"             color: #2c3e50;\n"
"             padding-bottom: 10px;\n"
"             border-bottom: 1px solid #e0e6ed;\n"
"           ", nullptr));
        cropAreaScroll->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"             background: transparent;\n"
"             border: none;\n"
"           ", nullptr));
        widget->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"                 background: #ffffff;\n"
"                 border-radius: 8px;\n"
"                 padding: 15px;\n"
"                 border: 1px solid #e0e6ed;\n"
"               ", nullptr));
        label->setText(QCoreApplication::translate("ChangeInfoWindow", "\344\275\234\347\211\251\347\261\273\345\236\213\357\274\232", nullptr));
        label->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        cropTypeLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\345\260\217\351\272\246", nullptr));
        label1->setText(QCoreApplication::translate("ChangeInfoWindow", "\351\235\242\347\247\257\357\274\232", nullptr));
        label1->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        cropAreaLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "50\344\272\251", nullptr));
        label2->setText(QCoreApplication::translate("ChangeInfoWindow", "\344\275\215\347\275\256\357\274\232", nullptr));
        label2->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "font-weight: bold; color: #2c3e50;", nullptr));
        cropLocationLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\344\270\234\345\214\272\345\206\234\345\234\272A\345\234\260\345\235\227", nullptr));
        modifyCropButton->setText(QCoreApplication::translate("ChangeInfoWindow", "\344\277\256\346\224\271", nullptr));
        modifyCropButton->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"                    QPushButton {\n"
"                      background-color: #3498db;\n"
"                      color: white;\n"
"                      border-radius: 6px;\n"
"                      padding: 8px 16px;\n"
"                      font-size: 13px;\n"
"                      font-weight: bold;\n"
"                      border: none;\n"
"                    }\n"
"                    QPushButton:hover {\n"
"                      background-color: #2980b9;\n"
"                    }\n"
"                  ", nullptr));
        noCropLabel->setText(QCoreApplication::translate("ChangeInfoWindow", "\346\232\202\346\227\240\344\275\234\347\211\251\345\214\272\344\277\241\346\201\257", nullptr));
        noCropLabel->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "color: #95a5a6; font-size: 14px; padding: 30px;", nullptr));
        addCropButton->setText(QCoreApplication::translate("ChangeInfoWindow", "\346\267\273\345\212\240\344\275\234\347\211\251\345\214\272", nullptr));
        addCropButton->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"             QPushButton {\n"
"               background-color: #27ae60;\n"
"               color: white;\n"
"               border-radius: 6px;\n"
"               padding: 10px 20px;\n"
"               font-size: 14px;\n"
"               font-weight: bold;\n"
"               border: none;\n"
"             }\n"
"             QPushButton:hover {\n"
"               background-color: #219653;\n"
"             }\n"
"           ", nullptr));
        expertiseGroup->setTitle(QCoreApplication::translate("ChangeInfoWindow", "\346\223\205\351\225\277\351\242\206\345\237\237", nullptr));
        expertiseGroup->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"             background-color: white;\n"
"             border-radius: 12px;\n"
"             padding: 20px;\n"
"             border: 1px solid #e0e6ed;\n"
"           ", nullptr));
        expertiseEdit->setPlaceholderText(QCoreApplication::translate("ChangeInfoWindow", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\344\270\223\344\270\232\351\242\206\345\237\237\357\274\214\345\246\202\357\274\232\347\227\205\350\231\253\345\256\263\351\230\262\346\262\273\343\200\201\347\201\214\346\272\211\346\212\200\346\234\257\347\255\211", nullptr));
        expertiseEdit->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"                border: 1px solid #e0e6ed;\n"
"                border-radius: 6px;\n"
"                padding: 8px 12px;\n"
"                font-size: 14px;\n"
"              ", nullptr));
        addCropButtonExpert->setText(QCoreApplication::translate("ChangeInfoWindow", "\346\267\273\345\212\240\344\275\234\347\211\251\345\214\272", nullptr));
        addCropButtonExpert->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"             QPushButton {\n"
"               background-color: #27ae60;\n"
"               color: white;\n"
"               border-radius: 6px;\n"
"               padding: 10px 20px;\n"
"               font-size: 14px;\n"
"               font-weight: bold;\n"
"               border: none;\n"
"             }\n"
"             QPushButton:hover {\n"
"               background-color: #219653;\n"
"             }\n"
"           ", nullptr));
        saveButton->setText(QCoreApplication::translate("ChangeInfoWindow", "\344\277\235\345\255\230\346\233\264\346\224\271", nullptr));
        saveButton->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"           QPushButton {\n"
"             background-color: #3498db;\n"
"             color: white;\n"
"             border-radius: 6px;\n"
"             padding: 12px 30px;\n"
"             font-size: 16px;\n"
"             font-weight: bold;\n"
"             border: none;\n"
"           }\n"
"           QPushButton:hover {\n"
"             background-color: #2980b9;\n"
"           }\n"
"         ", nullptr));
        cancelButton->setText(QCoreApplication::translate("ChangeInfoWindow", "\345\217\226\346\266\210", nullptr));
        cancelButton->setStyleSheet(QCoreApplication::translate("ChangeInfoWindow", "\n"
"           QPushButton {\n"
"             background-color: #e0e6ed;\n"
"             color: #2c3e50;\n"
"             border-radius: 6px;\n"
"             padding: 12px 30px;\n"
"             font-size: 16px;\n"
"             font-weight: bold;\n"
"             border: none;\n"
"           }\n"
"           QPushButton:hover {\n"
"             background-color: #d0d6e0;\n"
"           }\n"
"         ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfoWindow: public Ui_ChangeInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFOWINDOW_H
