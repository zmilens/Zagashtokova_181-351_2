/********************************************************************************
** Form generated from reading UI file 'managerwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWIN_H
#define UI_MANAGERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managerwin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushprosmotr;
    QPushButton *pushredact;
    QPushButton *pushfind;

    void setupUi(QDialog *managerwin)
    {
        if (managerwin->objectName().isEmpty())
            managerwin->setObjectName(QString::fromUtf8("managerwin"));
        managerwin->resize(400, 300);
        layoutWidget = new QWidget(managerwin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 60, 351, 201));
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushprosmotr = new QPushButton(layoutWidget);
        pushprosmotr->setObjectName(QString::fromUtf8("pushprosmotr"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Small"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        pushprosmotr->setFont(font1);

        horizontalLayout->addWidget(pushprosmotr);

        pushredact = new QPushButton(layoutWidget);
        pushredact->setObjectName(QString::fromUtf8("pushredact"));
        pushredact->setFont(font1);

        horizontalLayout->addWidget(pushredact);

        pushfind = new QPushButton(layoutWidget);
        pushfind->setObjectName(QString::fromUtf8("pushfind"));
        pushfind->setFont(font1);

        horizontalLayout->addWidget(pushfind);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(managerwin);

        QMetaObject::connectSlotsByName(managerwin);
    } // setupUi

    void retranslateUi(QDialog *managerwin)
    {
        managerwin->setWindowTitle(QApplication::translate("managerwin", "managerwin", nullptr));
        label->setText(QApplication::translate("managerwin", "Manager access", nullptr));
        pushprosmotr->setText(QApplication::translate("managerwin", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        pushredact->setText(QApplication::translate("managerwin", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushfind->setText(QApplication::translate("managerwin", "\320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerwin: public Ui_managerwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWIN_H
