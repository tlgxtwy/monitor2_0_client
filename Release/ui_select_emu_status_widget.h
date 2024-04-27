/********************************************************************************
** Form generated from reading UI file 'select_emu_status_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_EMU_STATUS_WIDGET_H
#define UI_SELECT_EMU_STATUS_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cdateedit.h>
#include <flipover_widget.h>

QT_BEGIN_NAMESPACE

class Ui_select_emu_status_widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *emu_cid_lb;
    QLineEdit *emu_cid_edt;
    QLabel *date_lb;
    CDateEdit *date_edt;
    QSpacerItem *horizontalSpacer;
    QPushButton *select_pb;
    QTableWidget *tableWidget;
    flipover_widget *flipover_wd;

    void setupUi(QWidget *select_emu_status_widget)
    {
        if (select_emu_status_widget->objectName().isEmpty())
            select_emu_status_widget->setObjectName(QString::fromUtf8("select_emu_status_widget"));
        select_emu_status_widget->resize(971, 829);
        verticalLayout = new QVBoxLayout(select_emu_status_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        emu_cid_lb = new QLabel(select_emu_status_widget);
        emu_cid_lb->setObjectName(QString::fromUtf8("emu_cid_lb"));

        horizontalLayout->addWidget(emu_cid_lb);

        emu_cid_edt = new QLineEdit(select_emu_status_widget);
        emu_cid_edt->setObjectName(QString::fromUtf8("emu_cid_edt"));

        horizontalLayout->addWidget(emu_cid_edt);

        date_lb = new QLabel(select_emu_status_widget);
        date_lb->setObjectName(QString::fromUtf8("date_lb"));

        horizontalLayout->addWidget(date_lb);

        date_edt = new CDateEdit(select_emu_status_widget);
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

        select_pb = new QPushButton(select_emu_status_widget);
        select_pb->setObjectName(QString::fromUtf8("select_pb"));

        horizontalLayout->addWidget(select_pb);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 3);
        horizontalLayout->setStretch(4, 20);
        horizontalLayout->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(select_emu_status_widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        flipover_wd = new flipover_widget(select_emu_status_widget);
        flipover_wd->setObjectName(QString::fromUtf8("flipover_wd"));

        verticalLayout->addWidget(flipover_wd);


        retranslateUi(select_emu_status_widget);

        QMetaObject::connectSlotsByName(select_emu_status_widget);
    } // setupUi

    void retranslateUi(QWidget *select_emu_status_widget)
    {
        select_emu_status_widget->setWindowTitle(QCoreApplication::translate("select_emu_status_widget", "Form", nullptr));
        emu_cid_lb->setText(QCoreApplication::translate("select_emu_status_widget", "\347\275\221\345\205\263\347\274\226\345\217\267", nullptr));
        date_lb->setText(QCoreApplication::translate("select_emu_status_widget", "\346\227\245\346\234\237", nullptr));
        select_pb->setText(QCoreApplication::translate("select_emu_status_widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_emu_status_widget: public Ui_select_emu_status_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_EMU_STATUS_WIDGET_H
