/********************************************************************************
** Form generated from reading UI file 'farmerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FARMERWINDOW_H
#define UI_FARMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FarmerWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FarmerWindow)
    {
        if (FarmerWindow->objectName().isEmpty())
            FarmerWindow->setObjectName("FarmerWindow");
        FarmerWindow->resize(800, 600);
        centralwidget = new QWidget(FarmerWindow);
        centralwidget->setObjectName("centralwidget");
        FarmerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FarmerWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        FarmerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FarmerWindow);
        statusbar->setObjectName("statusbar");
        FarmerWindow->setStatusBar(statusbar);

        retranslateUi(FarmerWindow);

        QMetaObject::connectSlotsByName(FarmerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FarmerWindow)
    {
        FarmerWindow->setWindowTitle(QCoreApplication::translate("FarmerWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FarmerWindow: public Ui_FarmerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FARMERWINDOW_H
