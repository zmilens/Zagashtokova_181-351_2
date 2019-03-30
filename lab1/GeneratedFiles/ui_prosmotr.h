/********************************************************************************
** Form generated from reading UI file 'prosmotr.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROSMOTR_H
#define UI_PROSMOTR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_prosmotr
{
public:

    void setupUi(QDialog *prosmotr)
    {
        if (prosmotr->objectName().isEmpty())
            prosmotr->setObjectName(QString::fromUtf8("prosmotr"));
        prosmotr->resize(400, 300);

        retranslateUi(prosmotr);

        QMetaObject::connectSlotsByName(prosmotr);
    } // setupUi

    void retranslateUi(QDialog *prosmotr)
    {
        prosmotr->setWindowTitle(QApplication::translate("prosmotr", "prosmotr", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prosmotr: public Ui_prosmotr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROSMOTR_H
