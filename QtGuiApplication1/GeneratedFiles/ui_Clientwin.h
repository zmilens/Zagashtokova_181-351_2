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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Clientwin
{
public:
    QTableView *tableView;

    void setupUi(QDialog *Clientwin)
    {
        if (Clientwin->objectName().isEmpty())
            Clientwin->setObjectName(QString::fromUtf8("Clientwin"));
        Clientwin->resize(400, 300);
        tableView = new QTableView(Clientwin);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(Clientwin);

        QMetaObject::connectSlotsByName(Clientwin);
    } // setupUi

    void retranslateUi(QDialog *Clientwin)
    {
        Clientwin->setWindowTitle(QApplication::translate("Clientwin", "Clientwin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clientwin: public Ui_Clientwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIN_H
