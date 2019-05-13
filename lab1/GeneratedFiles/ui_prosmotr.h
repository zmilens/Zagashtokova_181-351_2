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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_prosmotr
{
public:
    QTableView *tableView;
    QPushButton *prosm;

    void setupUi(QDialog *prosmotr)
    {
        if (prosmotr->objectName().isEmpty())
            prosmotr->setObjectName(QString::fromUtf8("prosmotr"));
        prosmotr->resize(400, 300);
        tableView = new QTableView(prosmotr);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 50, 351, 231));
        prosm = new QPushButton(prosmotr);
        prosm->setObjectName(QString::fromUtf8("prosm"));
        prosm->setGeometry(QRect(95, 6, 201, 31));

        retranslateUi(prosmotr);

        QMetaObject::connectSlotsByName(prosmotr);
    } // setupUi

    void retranslateUi(QDialog *prosmotr)
    {
        prosmotr->setWindowTitle(QApplication::translate("prosmotr", "prosmotr", nullptr));
        prosm->setText(QApplication::translate("prosmotr", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prosmotr: public Ui_prosmotr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROSMOTR_H
