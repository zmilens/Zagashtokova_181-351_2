/********************************************************************************
** Form generated from reading UI file 'clientwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIN_H
#define UI_CLIENTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientwin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *clientwin)
    {
        if (clientwin->objectName().isEmpty())
            clientwin->setObjectName(QString::fromUtf8("clientwin"));
        clientwin->resize(400, 300);
        layoutWidget = new QWidget(clientwin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(64, 50, 271, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Display"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Small"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);


        retranslateUi(clientwin);

        QMetaObject::connectSlotsByName(clientwin);
    } // setupUi

    void retranslateUi(QDialog *clientwin)
    {
        clientwin->setWindowTitle(QApplication::translate("clientwin", "clienrwin", nullptr));
        label->setText(QApplication::translate("clientwin", "Client access", nullptr));
        pushButton->setText(QApplication::translate("clientwin", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientwin: public Ui_clientwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIN_H
