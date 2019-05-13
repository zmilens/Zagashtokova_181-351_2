/********************************************************************************
** Form generated from reading UI file 'labn.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABN_H
#define UI_LABN_H

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

class Ui_labnClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_autorize;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *labnClass)
    {
        if (labnClass->objectName().isEmpty())
            labnClass->setObjectName(QString::fromUtf8("labnClass"));
        labnClass->resize(350, 280);
        centralWidget = new QWidget(labnClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 311, 211));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Banner"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit_login = new QLineEdit(layoutWidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout->addWidget(lineEdit_login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_2->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout_3->addLayout(verticalLayout_2);

        pushButton_autorize = new QPushButton(layoutWidget);
        pushButton_autorize->setObjectName(QString::fromUtf8("pushButton_autorize"));
        pushButton_autorize->setFont(font);

        horizontalLayout_3->addWidget(pushButton_autorize);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        labnClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(labnClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 350, 18));
        labnClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(labnClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        labnClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(labnClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        labnClass->setStatusBar(statusBar);

        retranslateUi(labnClass);

        QMetaObject::connectSlotsByName(labnClass);
    } // setupUi

    void retranslateUi(QMainWindow *labnClass)
    {
        labnClass->setWindowTitle(QApplication::translate("labnClass", "labn", nullptr));
        label->setText(QApplication::translate("labnClass", "Login:", nullptr));
        label_2->setText(QApplication::translate("labnClass", "Password:", nullptr));
        pushButton_autorize->setText(QApplication::translate("labnClass", "LOG IN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class labnClass: public Ui_labnClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABN_H
