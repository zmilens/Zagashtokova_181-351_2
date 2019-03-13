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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_managerwin
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *managerwin)
    {
        if (managerwin->objectName().isEmpty())
            managerwin->setObjectName(QString::fromUtf8("managerwin"));
        managerwin->resize(400, 300);
        pushButton = new QPushButton(managerwin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 220, 56, 17));

        retranslateUi(managerwin);

        QMetaObject::connectSlotsByName(managerwin);
    } // setupUi

    void retranslateUi(QDialog *managerwin)
    {
        managerwin->setWindowTitle(QApplication::translate("managerwin", "managerwin", nullptr));
        pushButton->setText(QApplication::translate("managerwin", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managerwin: public Ui_managerwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWIN_H
