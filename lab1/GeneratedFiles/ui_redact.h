/********************************************************************************
** Form generated from reading UI file 'redact.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDACT_H
#define UI_REDACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_redact
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineTopic;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineAuthor;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineArticle;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineMag;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushAdd;
    QPushButton *pushDel;

    void setupUi(QDialog *redact)
    {
        if (redact->objectName().isEmpty())
            redact->setObjectName(QString::fromUtf8("redact"));
        redact->resize(400, 300);
        layoutWidget = new QWidget(redact);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 31, 361, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Small"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineTopic = new QLineEdit(layoutWidget);
        lineTopic->setObjectName(QString::fromUtf8("lineTopic"));

        horizontalLayout_2->addWidget(lineTopic);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineAuthor = new QLineEdit(layoutWidget);
        lineAuthor->setObjectName(QString::fromUtf8("lineAuthor"));

        horizontalLayout->addWidget(lineAuthor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        lineArticle = new QLineEdit(layoutWidget);
        lineArticle->setObjectName(QString::fromUtf8("lineArticle"));

        horizontalLayout_4->addWidget(lineArticle);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        lineMag = new QLineEdit(layoutWidget);
        lineMag->setObjectName(QString::fromUtf8("lineMag"));

        horizontalLayout_5->addWidget(lineMag);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushAdd = new QPushButton(layoutWidget);
        pushAdd->setObjectName(QString::fromUtf8("pushAdd"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sitka Small"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        pushAdd->setFont(font1);

        horizontalLayout_6->addWidget(pushAdd);

        pushDel = new QPushButton(layoutWidget);
        pushDel->setObjectName(QString::fromUtf8("pushDel"));
        pushDel->setFont(font1);

        horizontalLayout_6->addWidget(pushDel);


        verticalLayout_2->addLayout(horizontalLayout_6);


        retranslateUi(redact);

        QMetaObject::connectSlotsByName(redact);
    } // setupUi

    void retranslateUi(QDialog *redact)
    {
        redact->setWindowTitle(QApplication::translate("redact", "redact", nullptr));
        label_2->setText(QApplication::translate("redact", "\320\242\320\265\320\274\320\260:", nullptr));
        label->setText(QApplication::translate("redact", "\320\220\320\262\321\202\320\276\321\200:", nullptr));
        label_3->setText(QApplication::translate("redact", "\320\241\321\202\320\260\321\202\321\214\321\217:", nullptr));
        label_4->setText(QApplication::translate("redact", "\320\226\321\203\321\200\320\275\320\260\320\273:", nullptr));
        pushAdd->setText(QApplication::translate("redact", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushDel->setText(QApplication::translate("redact", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class redact: public Ui_redact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDACT_H
