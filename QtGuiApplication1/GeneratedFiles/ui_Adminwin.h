/********************************************************************************
** Form generated from reading UI file 'Adminwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIN_H
#define UI_ADMINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Adminwin
{
public:
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_6;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line_3;
    QTableView *tableView;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit_login;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_5;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_find;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Adminwin)
    {
        if (Adminwin->objectName().isEmpty())
            Adminwin->setObjectName(QString::fromUtf8("Adminwin"));
        Adminwin->resize(414, 316);
        gridLayout_7 = new QGridLayout(Adminwin);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        line = new QFrame(Adminwin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        line_3 = new QFrame(Adminwin);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        tableView = new QTableView(Adminwin);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_3->addWidget(tableView);

        line_4 = new QFrame(Adminwin);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(Adminwin);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Banner"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        lineEdit_login = new QLineEdit(Adminwin);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        verticalLayout->addWidget(lineEdit_login);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(Adminwin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        lineEdit_password = new QLineEdit(Adminwin);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        verticalLayout_2->addWidget(lineEdit_password);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(Adminwin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        lineEdit_4 = new QLineEdit(Adminwin);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_add = new QPushButton(Adminwin);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Banner"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        pushButton_add->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_add);

        pushButton_delete = new QPushButton(Adminwin);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_delete);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        line_5 = new QFrame(Adminwin);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_5);


        verticalLayout_6->addLayout(horizontalLayout_3);

        line_2 = new QFrame(Adminwin);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(Adminwin);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_find = new QPushButton(Adminwin);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setFont(font);

        horizontalLayout->addWidget(pushButton_find);


        verticalLayout_6->addLayout(horizontalLayout);

        line_6 = new QFrame(Adminwin);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(Adminwin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_4);


        gridLayout_7->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(Adminwin);

        QMetaObject::connectSlotsByName(Adminwin);
    } // setupUi

    void retranslateUi(QDialog *Adminwin)
    {
        Adminwin->setWindowTitle(QApplication::translate("Adminwin", "Adminwin", nullptr));
        label->setText(QApplication::translate("Adminwin", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_2->setText(QApplication::translate("Adminwin", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        label_3->setText(QApplication::translate("Adminwin", "\320\224\320\276\321\201\321\202\321\203\320\277:", nullptr));
        pushButton_add->setText(QApplication::translate("Adminwin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QApplication::translate("Adminwin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_find->setText(QApplication::translate("Adminwin", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton->setText(QApplication::translate("Adminwin", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adminwin: public Ui_Adminwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIN_H
