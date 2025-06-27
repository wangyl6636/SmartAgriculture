/********************************************************************************
** Form generated from reading UI file 'expertwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERTWINDOW_H
#define UI_EXPERTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpertWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ExpertWindow)
    {
        if (ExpertWindow->objectName().isEmpty())
            ExpertWindow->setObjectName("ExpertWindow");
        ExpertWindow->resize(800, 600);
        centralwidget = new QWidget(ExpertWindow);
        centralwidget->setObjectName("centralwidget");
        ExpertWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ExpertWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        ExpertWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ExpertWindow);
        statusbar->setObjectName("statusbar");
        ExpertWindow->setStatusBar(statusbar);

        retranslateUi(ExpertWindow);

        QMetaObject::connectSlotsByName(ExpertWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ExpertWindow)
    {
        ExpertWindow->setWindowTitle(QCoreApplication::translate("ExpertWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpertWindow: public Ui_ExpertWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERTWINDOW_H
