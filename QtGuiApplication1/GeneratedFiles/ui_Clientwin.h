/********************************************************************************
** Form generated from reading UI file 'Clientwin.ui'
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clientwin
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_find;
    QPushButton *pushButton_find;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Clientwin)
    {
        if (Clientwin->objectName().isEmpty())
            Clientwin->setObjectName(QString::fromUtf8("Clientwin"));
        Clientwin->resize(420, 391);
        layoutWidget = new QWidget(Clientwin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 391, 371));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_find = new QLineEdit(layoutWidget);
        lineEdit_find->setObjectName(QString::fromUtf8("lineEdit_find"));

        horizontalLayout->addWidget(lineEdit_find);

        pushButton_find = new QPushButton(layoutWidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Banner"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_find->setFont(font);

        horizontalLayout->addWidget(pushButton_find);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Banner"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(Clientwin);

        QMetaObject::connectSlotsByName(Clientwin);
    } // setupUi

    void retranslateUi(QDialog *Clientwin)
    {
        Clientwin->setWindowTitle(QApplication::translate("Clientwin", "Clientwin", nullptr));
        pushButton_find->setText(QApplication::translate("Clientwin", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_2->setText(QApplication::translate("Clientwin", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("Clientwin", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clientwin: public Ui_Clientwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIN_H
