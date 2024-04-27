/********************************************************************************
** Form generated from reading UI file 'mi_detail_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MI_DETAIL_WIDGET_H
#define UI_MI_DETAIL_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <cdateedit.h>
#include <draw_widget.h>
#include <select_mi_power_widget.h>

QT_BEGIN_NAMESPACE

class Ui_mi_detail_widget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *graph_tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    CDateEdit *stopdate_edt;
    QSpacerItem *horizontalSpacer_2;
    CDateEdit *startdate_edt;
    QLabel *label_3;
    QPushButton *select1_pb;
    QSplitter *splitter_4;
    draw_widget *total_draw_widget;
    QSplitter *splitter_3;
    QSplitter *splitter;
    draw_widget *pv1_draw_widget;
    draw_widget *pv3_draw_widget;
    QSplitter *splitter_2;
    draw_widget *pv2_draw_widget;
    draw_widget *pv4_draw_widget;
    QWidget *power_tab;
    QGridLayout *gridLayout_2;
    select_mi_power_widget *power_item_wd;

    void setupUi(QWidget *mi_detail_widget)
    {
        if (mi_detail_widget->objectName().isEmpty())
            mi_detail_widget->setObjectName(QString::fromUtf8("mi_detail_widget"));
        mi_detail_widget->resize(1029, 945);
        verticalLayout = new QVBoxLayout(mi_detail_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(mi_detail_widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget = new QTabWidget(mi_detail_widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        graph_tab = new QWidget();
        graph_tab->setObjectName(QString::fromUtf8("graph_tab"));
        verticalLayout_2 = new QVBoxLayout(graph_tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(graph_tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        stopdate_edt = new CDateEdit(graph_tab);
        stopdate_edt->setObjectName(QString::fromUtf8("stopdate_edt"));
        stopdate_edt->setStyleSheet(QString::fromUtf8("QDateEdit\n"
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

        gridLayout_4->addWidget(stopdate_edt, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        startdate_edt = new CDateEdit(graph_tab);
        startdate_edt->setObjectName(QString::fromUtf8("startdate_edt"));
        startdate_edt->setStyleSheet(QString::fromUtf8("QDateEdit\n"
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

        gridLayout_4->addWidget(startdate_edt, 0, 1, 1, 1);

        label_3 = new QLabel(graph_tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 2, 1, 1);

        select1_pb = new QPushButton(graph_tab);
        select1_pb->setObjectName(QString::fromUtf8("select1_pb"));

        gridLayout_4->addWidget(select1_pb, 0, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        splitter_4 = new QSplitter(graph_tab);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        total_draw_widget = new draw_widget(splitter_4);
        total_draw_widget->setObjectName(QString::fromUtf8("total_draw_widget"));
        splitter_4->addWidget(total_draw_widget);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pv1_draw_widget = new draw_widget(splitter);
        pv1_draw_widget->setObjectName(QString::fromUtf8("pv1_draw_widget"));
        splitter->addWidget(pv1_draw_widget);
        pv3_draw_widget = new draw_widget(splitter);
        pv3_draw_widget->setObjectName(QString::fromUtf8("pv3_draw_widget"));
        splitter->addWidget(pv3_draw_widget);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        pv2_draw_widget = new draw_widget(splitter_2);
        pv2_draw_widget->setObjectName(QString::fromUtf8("pv2_draw_widget"));
        splitter_2->addWidget(pv2_draw_widget);
        pv4_draw_widget = new draw_widget(splitter_2);
        pv4_draw_widget->setObjectName(QString::fromUtf8("pv4_draw_widget"));
        splitter_2->addWidget(pv4_draw_widget);
        splitter_3->addWidget(splitter_2);
        splitter_4->addWidget(splitter_3);

        verticalLayout_2->addWidget(splitter_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 15);
        tabWidget->addTab(graph_tab, QString());
        power_tab = new QWidget();
        power_tab->setObjectName(QString::fromUtf8("power_tab"));
        gridLayout_2 = new QGridLayout(power_tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        power_item_wd = new select_mi_power_widget(power_tab);
        power_item_wd->setObjectName(QString::fromUtf8("power_item_wd"));

        gridLayout_2->addWidget(power_item_wd, 0, 0, 1, 1);

        tabWidget->addTab(power_tab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(mi_detail_widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mi_detail_widget);
    } // setupUi

    void retranslateUi(QWidget *mi_detail_widget)
    {
        mi_detail_widget->setWindowTitle(QCoreApplication::translate("mi_detail_widget", "Form", nullptr));
        label->setText(QCoreApplication::translate("mi_detail_widget", "\345\276\256\351\200\206\347\274\226\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("mi_detail_widget", "\345\274\200\345\247\213\346\227\245\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("mi_detail_widget", "\347\273\223\346\235\237\346\227\245\346\234\237", nullptr));
        select1_pb->setText(QCoreApplication::translate("mi_detail_widget", "\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(graph_tab), QCoreApplication::translate("mi_detail_widget", "\345\233\276\345\275\242\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(power_tab), QCoreApplication::translate("mi_detail_widget", "\345\217\221\347\224\265\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mi_detail_widget: public Ui_mi_detail_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MI_DETAIL_WIDGET_H
