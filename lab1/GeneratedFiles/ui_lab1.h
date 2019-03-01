/********************************************************************************
** Form generated from reading UI file 'lab1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1_H
#define UI_LAB1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab1Class
{
public:
    QAction *actionAbout;
    QAction *actionclose;
    QWidget *centralWidget;
    QPushButton *pushButton_autorize;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QLabel *label_login;
    QLabel *label_password;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuhelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab1Class)
    {
        if (lab1Class->objectName().isEmpty())
            lab1Class->setObjectName(QString::fromUtf8("lab1Class"));
        lab1Class->resize(601, 400);
        actionAbout = new QAction(lab1Class);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionclose = new QAction(lab1Class);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        centralWidget = new QWidget(lab1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_autorize = new QPushButton(centralWidget);
        pushButton_autorize->setObjectName(QString::fromUtf8("pushButton_autorize"));
        pushButton_autorize->setGeometry(QRect(190, 220, 91, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        pushButton_autorize->setFont(font);
        lineEdit_login = new QLineEdit(centralWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setGeometry(QRect(240, 80, 113, 20));
        lineEdit_password = new QLineEdit(centralWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(240, 130, 113, 20));
        label_login = new QLabel(centralWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(100, 80, 35, 20));
        label_password = new QLabel(centralWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(100, 130, 71, 21));
        lab1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lab1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 18));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuhelp = new QMenu(menuBar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        lab1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lab1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        lab1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(lab1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        lab1Class->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuhelp->menuAction());
        menufile->addAction(actionclose);
        menuhelp->addAction(actionAbout);

        retranslateUi(lab1Class);
        QObject::connect(actionclose, SIGNAL(triggered()), lab1Class, SLOT(close()));

        QMetaObject::connectSlotsByName(lab1Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab1Class)
    {
        lab1Class->setWindowTitle(QApplication::translate("lab1Class", "lab1", nullptr));
        actionAbout->setText(QApplication::translate("lab1Class", "About", nullptr));
        actionclose->setText(QApplication::translate("lab1Class", "close", nullptr));
        pushButton_autorize->setText(QApplication::translate("lab1Class", "LOGIN", nullptr));
        label_login->setText(QApplication::translate("lab1Class", "LOGIN:", nullptr));
        label_password->setText(QApplication::translate("lab1Class", "PASSWORD:", nullptr));
        menufile->setTitle(QApplication::translate("lab1Class", "file", nullptr));
        menuhelp->setTitle(QApplication::translate("lab1Class", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab1Class: public Ui_lab1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1_H
