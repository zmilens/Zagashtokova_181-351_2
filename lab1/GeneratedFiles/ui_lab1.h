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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lab1Class
{
public:
    QAction *actionAbout;
    QAction *actionclose;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_autorize;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuhelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lab1Class)
    {
        if (lab1Class->objectName().isEmpty())
            lab1Class->setObjectName(QString::fromUtf8("lab1Class"));
        lab1Class->resize(457, 316);
        actionAbout = new QAction(lab1Class);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionclose = new QAction(lab1Class);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        centralWidget = new QWidget(lab1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 40, 301, 181));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_login = new QLabel(layoutWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Display"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_login->setFont(font);

        horizontalLayout_2->addWidget(label_login);

        lineEdit_login = new QLineEdit(layoutWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout_2->addWidget(lineEdit_login);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_password = new QLabel(layoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setFont(font);

        horizontalLayout->addWidget(label_password);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_autorize = new QPushButton(layoutWidget);
        pushButton_autorize->setObjectName(QString::fromUtf8("pushButton_autorize"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Banner"));
        font1.setPointSize(19);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_autorize->setFont(font1);

        verticalLayout_2->addWidget(pushButton_autorize);

        lab1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(lab1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 457, 18));
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

        QMetaObject::connectSlotsByName(lab1Class);
    } // setupUi

    void retranslateUi(QMainWindow *lab1Class)
    {
        lab1Class->setWindowTitle(QApplication::translate("lab1Class", "lab1", nullptr));
        actionAbout->setText(QApplication::translate("lab1Class", "About", nullptr));
        actionclose->setText(QApplication::translate("lab1Class", "close", nullptr));
        label_login->setText(QApplication::translate("lab1Class", "Login:", nullptr));
        label_password->setText(QApplication::translate("lab1Class", "Password:", nullptr));
        pushButton_autorize->setText(QApplication::translate("lab1Class", "LOG IN", nullptr));
        menufile->setTitle(QApplication::translate("lab1Class", "file", nullptr));
        menuhelp->setTitle(QApplication::translate("lab1Class", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lab1Class: public Ui_lab1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1_H
