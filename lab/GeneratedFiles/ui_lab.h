/********************************************************************************
** Form generated from reading UI file 'lab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB_H
#define UI_LAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_labClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_login;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *labClass)
    {
        if (labClass->objectName().isEmpty())
            labClass->setObjectName(QString::fromUtf8("labClass"));
        labClass->resize(600, 400);
        labClass->setStyleSheet(QString::fromUtf8("rgb(255, 255, 255)"));
        centralWidget = new QWidget(labClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 80, 331, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_login = new QLabel(layoutWidget);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_login->setFont(font);

        horizontalLayout->addWidget(label_login);

        lineEdit_login = new QLineEdit(layoutWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout->addWidget(lineEdit_login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_password = new QLabel(layoutWidget);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setFont(font);

        horizontalLayout_2->addWidget(label_password);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pushButton->setFont(font1);

        verticalLayout_2->addWidget(pushButton);

        labClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(labClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        labClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(labClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        labClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(labClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        labClass->setStatusBar(statusBar);

        retranslateUi(labClass);

        QMetaObject::connectSlotsByName(labClass);
    } // setupUi

    void retranslateUi(QMainWindow *labClass)
    {
        labClass->setWindowTitle(QApplication::translate("labClass", "lab", nullptr));
        label_login->setText(QApplication::translate("labClass", "Login:", nullptr));
        label_password->setText(QApplication::translate("labClass", "Password:", nullptr));
        pushButton->setText(QApplication::translate("labClass", "LOG IN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class labClass: public Ui_labClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB_H
