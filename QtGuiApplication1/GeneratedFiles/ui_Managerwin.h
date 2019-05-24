/********************************************************************************
** Form generated from reading UI file 'Managerwin.ui'
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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Managerwin
{
public:
    QFrame *line;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QFrame *line_4;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QFrame *line_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *lineEdit_topic;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_author;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_article;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_magazine;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_5;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_find;
    QPushButton *pushButton_find;
    QPushButton *pushButton_2;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Managerwin)
    {
        if (Managerwin->objectName().isEmpty())
            Managerwin->setObjectName(QString::fromUtf8("Managerwin"));
        Managerwin->resize(445, 390);
        line = new QFrame(Managerwin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(11, 11, 403, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(Managerwin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 18, 405, 340));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(0, QFormLayout::FieldRole, line_4);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::LabelRole, line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_3->addWidget(tableView);

        line_6 = new QFrame(layoutWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Banner"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_4->addWidget(label);

        lineEdit_topic = new QLineEdit(layoutWidget);
        lineEdit_topic->setObjectName(QString::fromUtf8("lineEdit_topic"));

        verticalLayout_4->addWidget(lineEdit_topic);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        lineEdit_author = new QLineEdit(layoutWidget);
        lineEdit_author->setObjectName(QString::fromUtf8("lineEdit_author"));

        verticalLayout_3->addWidget(lineEdit_author);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        lineEdit_article = new QLineEdit(layoutWidget);
        lineEdit_article->setObjectName(QString::fromUtf8("lineEdit_article"));

        verticalLayout->addWidget(lineEdit_article);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        lineEdit_magazine = new QLineEdit(layoutWidget);
        lineEdit_magazine->setObjectName(QString::fromUtf8("lineEdit_magazine"));

        verticalLayout_2->addWidget(lineEdit_magazine);


        verticalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_add = new QPushButton(layoutWidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Banner"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        pushButton_add->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_add);

        pushButton_delete = new QPushButton(layoutWidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_delete);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_5);

        line_5 = new QFrame(layoutWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_5);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_3);

        line_8 = new QFrame(layoutWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(2, QFormLayout::FieldRole, line_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_find = new QLineEdit(layoutWidget);
        lineEdit_find->setObjectName(QString::fromUtf8("lineEdit_find"));

        horizontalLayout->addWidget(lineEdit_find);

        pushButton_find = new QPushButton(layoutWidget);
        pushButton_find->setObjectName(QString::fromUtf8("pushButton_find"));
        pushButton_find->setFont(font);

        horizontalLayout->addWidget(pushButton_find);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sitka Banner"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_2->setFont(font2);

        horizontalLayout->addWidget(pushButton_2);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(4, QFormLayout::FieldRole, line_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_6);


        retranslateUi(Managerwin);
        QObject::connect(pushButton, SIGNAL(clicked()), tableView, SLOT(resizeColumnsToContents()));
        QObject::connect(pushButton, SIGNAL(clicked()), tableView, SLOT(resizeRowsToContents()));

        QMetaObject::connectSlotsByName(Managerwin);
    } // setupUi

    void retranslateUi(QDialog *Managerwin)
    {
        Managerwin->setWindowTitle(QApplication::translate("Managerwin", "Managerwin", nullptr));
        label->setText(QApplication::translate("Managerwin", "\320\242\320\265\320\274\320\260:", nullptr));
        label_2->setText(QApplication::translate("Managerwin", "\320\220\320\262\321\202\320\276\321\200:", nullptr));
        label_3->setText(QApplication::translate("Managerwin", "\320\241\321\202\320\260\321\202\321\214\321\217:", nullptr));
        label_4->setText(QApplication::translate("Managerwin", "\320\226\321\203\321\200\320\275\320\260\320\273:", nullptr));
        pushButton_add->setText(QApplication::translate("Managerwin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QApplication::translate("Managerwin", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_find->setText(QApplication::translate("Managerwin", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushButton_2->setText(QApplication::translate("Managerwin", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("Managerwin", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Managerwin: public Ui_Managerwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWIN_H
