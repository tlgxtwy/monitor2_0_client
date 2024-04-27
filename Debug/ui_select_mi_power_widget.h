/********************************************************************************
** Form generated from reading UI file 'select_mi_power_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_MI_POWER_WIDGET_H
#define UI_SELECT_MI_POWER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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

class Ui_select_mi_power_widget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *mi_lb;
    QLineEdit *mim_err_edt;
    QSpacerItem *horizontalSpacer_2;
    QLabel *mim_err_lb;
    CDateEdit *date_edt;
    QLineEdit *mi_edt;
    QSpacerItem *horizontalSpacer;
    QLabel *mis_err_lb;
    QLineEdit *mis_err_edt;
    QLabel *date_lb;
    QPushButton *select_pb;
    QTableWidget *tableWidget;
    flipover_widget *flipover_wd;

    void setupUi(QWidget *select_mi_power_widget)
    {
        if (select_mi_power_widget->objectName().isEmpty())
            select_mi_power_widget->setObjectName(QString::fromUtf8("select_mi_power_widget"));
        select_mi_power_widget->resize(1097, 847);
        verticalLayout = new QVBoxLayout(select_mi_power_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mi_lb = new QLabel(select_mi_power_widget);
        mi_lb->setObjectName(QString::fromUtf8("mi_lb"));

        gridLayout->addWidget(mi_lb, 0, 0, 1, 1);

        mim_err_edt = new QLineEdit(select_mi_power_widget);
        mim_err_edt->setObjectName(QString::fromUtf8("mim_err_edt"));

        gridLayout->addWidget(mim_err_edt, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        mim_err_lb = new QLabel(select_mi_power_widget);
        mim_err_lb->setObjectName(QString::fromUtf8("mim_err_lb"));

        gridLayout->addWidget(mim_err_lb, 0, 3, 1, 1);

        date_edt = new CDateEdit(select_mi_power_widget);
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

        gridLayout->addWidget(date_edt, 0, 8, 1, 1);

        mi_edt = new QLineEdit(select_mi_power_widget);
        mi_edt->setObjectName(QString::fromUtf8("mi_edt"));

        gridLayout->addWidget(mi_edt, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 9, 1, 1);

        mis_err_lb = new QLabel(select_mi_power_widget);
        mis_err_lb->setObjectName(QString::fromUtf8("mis_err_lb"));

        gridLayout->addWidget(mis_err_lb, 0, 5, 1, 1);

        mis_err_edt = new QLineEdit(select_mi_power_widget);
        mis_err_edt->setObjectName(QString::fromUtf8("mis_err_edt"));

        gridLayout->addWidget(mis_err_edt, 0, 6, 1, 1);

        date_lb = new QLabel(select_mi_power_widget);
        date_lb->setObjectName(QString::fromUtf8("date_lb"));

        gridLayout->addWidget(date_lb, 0, 7, 1, 1);

        select_pb = new QPushButton(select_mi_power_widget);
        select_pb->setObjectName(QString::fromUtf8("select_pb"));

        gridLayout->addWidget(select_pb, 0, 10, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tableWidget = new QTableWidget(select_mi_power_widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        flipover_wd = new flipover_widget(select_mi_power_widget);
        flipover_wd->setObjectName(QString::fromUtf8("flipover_wd"));

        verticalLayout->addWidget(flipover_wd);


        retranslateUi(select_mi_power_widget);

        QMetaObject::connectSlotsByName(select_mi_power_widget);
    } // setupUi

    void retranslateUi(QWidget *select_mi_power_widget)
    {
        select_mi_power_widget->setWindowTitle(QCoreApplication::translate("select_mi_power_widget", "Form", nullptr));
        mi_lb->setText(QCoreApplication::translate("select_mi_power_widget", "\345\276\256\351\200\206\347\274\226\345\217\267", nullptr));
        mim_err_lb->setText(QCoreApplication::translate("select_mi_power_widget", "\345\216\237\350\276\271\346\225\205\351\232\234", nullptr));
        mi_edt->setText(QString());
        mis_err_lb->setText(QCoreApplication::translate("select_mi_power_widget", "\345\211\257\350\276\271\346\225\205\351\232\234", nullptr));
        date_lb->setText(QCoreApplication::translate("select_mi_power_widget", "\346\227\245\346\234\237", nullptr));
        select_pb->setText(QCoreApplication::translate("select_mi_power_widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_mi_power_widget: public Ui_select_mi_power_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_MI_POWER_WIDGET_H
