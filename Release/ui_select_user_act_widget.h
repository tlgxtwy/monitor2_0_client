/********************************************************************************
** Form generated from reading UI file 'select_user_act_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_USER_ACT_WIDGET_H
#define UI_SELECT_USER_ACT_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <cdateedit.h>
#include <flipover_widget.h>

QT_BEGIN_NAMESPACE

class Ui_select_user_act_widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *user_lb;
    QLineEdit *user_edt;
    QLabel *act_lb;
    QComboBox *act_cb;
    QLabel *date_lb;
    CDateEdit *date_edt;
    QSpacerItem *horizontalSpacer;
    QPushButton *select_pb;
    QTableWidget *tableWidget;
    flipover_widget *flipover_wd;

    void setupUi(QDialog *select_user_act_widget)
    {
        if (select_user_act_widget->objectName().isEmpty())
            select_user_act_widget->setObjectName(QString::fromUtf8("select_user_act_widget"));
        select_user_act_widget->resize(919, 802);
        verticalLayout = new QVBoxLayout(select_user_act_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user_lb = new QLabel(select_user_act_widget);
        user_lb->setObjectName(QString::fromUtf8("user_lb"));

        horizontalLayout->addWidget(user_lb);

        user_edt = new QLineEdit(select_user_act_widget);
        user_edt->setObjectName(QString::fromUtf8("user_edt"));

        horizontalLayout->addWidget(user_edt);

        act_lb = new QLabel(select_user_act_widget);
        act_lb->setObjectName(QString::fromUtf8("act_lb"));

        horizontalLayout->addWidget(act_lb);

        act_cb = new QComboBox(select_user_act_widget);
        act_cb->addItem(QString());
        act_cb->addItem(QString());
        act_cb->addItem(QString());
        act_cb->addItem(QString());
        act_cb->setObjectName(QString::fromUtf8("act_cb"));

        horizontalLayout->addWidget(act_cb);

        date_lb = new QLabel(select_user_act_widget);
        date_lb->setObjectName(QString::fromUtf8("date_lb"));

        horizontalLayout->addWidget(date_lb);

        date_edt = new CDateEdit(select_user_act_widget);
        date_edt->setObjectName(QString::fromUtf8("date_edt"));
        date_edt->setStyleSheet(QString::fromUtf8("QDateEdit\n"
"{\n"
"    border: 1px solid #dbdbdb;\n"
"    color: #666666;\n"
"    font: 30px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QDateEdit:on { /* shift the text when the popup opens */\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 40px;\n"
"\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid; /* just a single line */\n"
"    border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icon/icon/calendar.ico);\n"
"}\n"
"\n"
"QDateEdit::down-arrow:on { /* shift the arrow when popup is open */\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        horizontalLayout->addWidget(date_edt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        select_pb = new QPushButton(select_user_act_widget);
        select_pb->setObjectName(QString::fromUtf8("select_pb"));

        horizontalLayout->addWidget(select_pb);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 3);
        horizontalLayout->setStretch(6, 20);
        horizontalLayout->setStretch(7, 1);

        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(select_user_act_widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        flipover_wd = new flipover_widget(select_user_act_widget);
        flipover_wd->setObjectName(QString::fromUtf8("flipover_wd"));

        verticalLayout->addWidget(flipover_wd);


        retranslateUi(select_user_act_widget);

        QMetaObject::connectSlotsByName(select_user_act_widget);
    } // setupUi

    void retranslateUi(QDialog *select_user_act_widget)
    {
        select_user_act_widget->setWindowTitle(QCoreApplication::translate("select_user_act_widget", "Dialog", nullptr));
        user_lb->setText(QCoreApplication::translate("select_user_act_widget", "\347\224\250\346\210\267", nullptr));
        act_lb->setText(QCoreApplication::translate("select_user_act_widget", "\345\212\250\344\275\234", nullptr));
        act_cb->setItemText(0, QCoreApplication::translate("select_user_act_widget", "\345\205\250\351\203\250", nullptr));
        act_cb->setItemText(1, QCoreApplication::translate("select_user_act_widget", "\345\210\240\351\231\244", nullptr));
        act_cb->setItemText(2, QCoreApplication::translate("select_user_act_widget", "\346\267\273\345\212\240", nullptr));
        act_cb->setItemText(3, QCoreApplication::translate("select_user_act_widget", "\350\277\234\347\250\213\346\216\247\345\210\266", nullptr));

        date_lb->setText(QCoreApplication::translate("select_user_act_widget", "\346\227\245\346\234\237", nullptr));
        select_pb->setText(QCoreApplication::translate("select_user_act_widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_user_act_widget: public Ui_select_user_act_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_USER_ACT_WIDGET_H
