/********************************************************************************
** Form generated from reading UI file 'history_batch_set_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_BATCH_SET_DIALOG_H
#define UI_HISTORY_BATCH_SET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <open_lib/cdateedit/cdateedit.h>

QT_BEGIN_NAMESPACE

class Ui_history_batch_set_dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *start_lb;
    CDateEdit *start_dedt;
    QLabel *stop_lb;
    CDateEdit *stop_dedt;
    QSpacerItem *horizontalSpacer;
    QPushButton *select_pb;
    QLabel *cur_batch_lb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *batch_tablewidget;
    QTableWidget *mis_tablewidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok_pb;
    QPushButton *cache_pb;

    void setupUi(QDialog *history_batch_set_dialog)
    {
        if (history_batch_set_dialog->objectName().isEmpty())
            history_batch_set_dialog->setObjectName(QString::fromUtf8("history_batch_set_dialog"));
        history_batch_set_dialog->resize(516, 621);
        verticalLayout = new QVBoxLayout(history_batch_set_dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(history_batch_set_dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        start_lb = new QLabel(groupBox);
        start_lb->setObjectName(QString::fromUtf8("start_lb"));

        horizontalLayout->addWidget(start_lb);

        start_dedt = new CDateEdit(groupBox);
        start_dedt->setObjectName(QString::fromUtf8("start_dedt"));
        start_dedt->setStyleSheet(QString::fromUtf8("QDateEdit\n"
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

        horizontalLayout->addWidget(start_dedt);

        stop_lb = new QLabel(groupBox);
        stop_lb->setObjectName(QString::fromUtf8("stop_lb"));

        horizontalLayout->addWidget(stop_lb);

        stop_dedt = new CDateEdit(groupBox);
        stop_dedt->setObjectName(QString::fromUtf8("stop_dedt"));
        stop_dedt->setStyleSheet(QString::fromUtf8("QDateEdit\n"
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

        horizontalLayout->addWidget(stop_dedt);

        horizontalSpacer = new QSpacerItem(256, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        select_pb = new QPushButton(groupBox);
        select_pb->setObjectName(QString::fromUtf8("select_pb"));

        horizontalLayout->addWidget(select_pb);

        cur_batch_lb = new QLabel(groupBox);
        cur_batch_lb->setObjectName(QString::fromUtf8("cur_batch_lb"));

        horizontalLayout->addWidget(cur_batch_lb);


        verticalLayout->addWidget(groupBox);

        widget = new QWidget(history_batch_set_dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        batch_tablewidget = new QTableWidget(widget);
        batch_tablewidget->setObjectName(QString::fromUtf8("batch_tablewidget"));

        horizontalLayout_2->addWidget(batch_tablewidget);

        mis_tablewidget = new QTableWidget(widget);
        mis_tablewidget->setObjectName(QString::fromUtf8("mis_tablewidget"));

        horizontalLayout_2->addWidget(mis_tablewidget);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(history_batch_set_dialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(305, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ok_pb = new QPushButton(widget_2);
        ok_pb->setObjectName(QString::fromUtf8("ok_pb"));

        horizontalLayout_3->addWidget(ok_pb);

        cache_pb = new QPushButton(widget_2);
        cache_pb->setObjectName(QString::fromUtf8("cache_pb"));

        horizontalLayout_3->addWidget(cache_pb);


        verticalLayout->addWidget(widget_2);


        retranslateUi(history_batch_set_dialog);

        QMetaObject::connectSlotsByName(history_batch_set_dialog);
    } // setupUi

    void retranslateUi(QDialog *history_batch_set_dialog)
    {
        history_batch_set_dialog->setWindowTitle(QCoreApplication::translate("history_batch_set_dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("history_batch_set_dialog", "\346\237\245\350\257\242\346\227\266\351\227\264\346\256\265", nullptr));
        start_lb->setText(QCoreApplication::translate("history_batch_set_dialog", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        stop_lb->setText(QCoreApplication::translate("history_batch_set_dialog", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        select_pb->setText(QCoreApplication::translate("history_batch_set_dialog", "\345\274\200\345\247\213\346\237\245\350\257\242", nullptr));
        cur_batch_lb->setText(QString());
        ok_pb->setText(QCoreApplication::translate("history_batch_set_dialog", "\347\241\256\345\256\232", nullptr));
        cache_pb->setText(QCoreApplication::translate("history_batch_set_dialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history_batch_set_dialog: public Ui_history_batch_set_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_BATCH_SET_DIALOG_H
