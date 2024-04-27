/********************************************************************************
** Form generated from reading UI file 'aging_mi_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGING_MI_WIDGET_H
#define UI_AGING_MI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aging_mi_widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *start_id_lb;
    QComboBox *select_way_cb;
    QSpacerItem *horizontalSpacer;
    QPushButton *sel_workorder_pb;
    QPushButton *batch_pb;
    QPushButton *select_pb;
    QLineEdit *start_id_edt;
    QLabel *stop_id_lb;
    QLineEdit *stop_id_edt;
    QHBoxLayout *horizontalLayout;
    QLabel *msg_lb;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *export_pb;
    QTableWidget *tableWidget;

    void setupUi(QWidget *aging_mi_widget)
    {
        if (aging_mi_widget->objectName().isEmpty())
            aging_mi_widget->setObjectName(QString::fromUtf8("aging_mi_widget"));
        aging_mi_widget->resize(961, 712);
        verticalLayout_2 = new QVBoxLayout(aging_mi_widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start_id_lb = new QLabel(aging_mi_widget);
        start_id_lb->setObjectName(QString::fromUtf8("start_id_lb"));

        gridLayout->addWidget(start_id_lb, 0, 1, 1, 1);

        select_way_cb = new QComboBox(aging_mi_widget);
        select_way_cb->addItem(QString());
        select_way_cb->addItem(QString());
        select_way_cb->addItem(QString());
        select_way_cb->setObjectName(QString::fromUtf8("select_way_cb"));

        gridLayout->addWidget(select_way_cb, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        sel_workorder_pb = new QPushButton(aging_mi_widget);
        sel_workorder_pb->setObjectName(QString::fromUtf8("sel_workorder_pb"));

        gridLayout->addWidget(sel_workorder_pb, 0, 5, 1, 1);

        batch_pb = new QPushButton(aging_mi_widget);
        batch_pb->setObjectName(QString::fromUtf8("batch_pb"));

        gridLayout->addWidget(batch_pb, 0, 6, 1, 1);

        select_pb = new QPushButton(aging_mi_widget);
        select_pb->setObjectName(QString::fromUtf8("select_pb"));

        gridLayout->addWidget(select_pb, 0, 8, 1, 1);

        start_id_edt = new QLineEdit(aging_mi_widget);
        start_id_edt->setObjectName(QString::fromUtf8("start_id_edt"));

        gridLayout->addWidget(start_id_edt, 0, 2, 1, 1);

        stop_id_lb = new QLabel(aging_mi_widget);
        stop_id_lb->setObjectName(QString::fromUtf8("stop_id_lb"));

        gridLayout->addWidget(stop_id_lb, 0, 3, 1, 1);

        stop_id_edt = new QLineEdit(aging_mi_widget);
        stop_id_edt->setObjectName(QString::fromUtf8("stop_id_edt"));

        gridLayout->addWidget(stop_id_edt, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        msg_lb = new QLabel(aging_mi_widget);
        msg_lb->setObjectName(QString::fromUtf8("msg_lb"));

        horizontalLayout->addWidget(msg_lb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(aging_mi_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        export_pb = new QPushButton(aging_mi_widget);
        export_pb->setObjectName(QString::fromUtf8("export_pb"));

        horizontalLayout->addWidget(export_pb);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        tableWidget = new QTableWidget(aging_mi_widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);


        retranslateUi(aging_mi_widget);

        QMetaObject::connectSlotsByName(aging_mi_widget);
    } // setupUi

    void retranslateUi(QWidget *aging_mi_widget)
    {
        aging_mi_widget->setWindowTitle(QCoreApplication::translate("aging_mi_widget", "Form", nullptr));
        start_id_lb->setText(QCoreApplication::translate("aging_mi_widget", "\350\265\267\345\247\213\347\274\226\345\217\267", nullptr));
        select_way_cb->setItemText(0, QCoreApplication::translate("aging_mi_widget", "\347\274\226\345\217\267\346\237\245\350\257\242", nullptr));
        select_way_cb->setItemText(1, QCoreApplication::translate("aging_mi_widget", "\345\267\245\345\215\225\346\237\245\350\257\242", nullptr));
        select_way_cb->setItemText(2, QCoreApplication::translate("aging_mi_widget", "\346\211\271\346\254\241\346\237\245\350\257\242", nullptr));

        sel_workorder_pb->setText(QCoreApplication::translate("aging_mi_widget", "\346\237\245\346\211\276\345\267\245\345\215\225", nullptr));
        batch_pb->setText(QCoreApplication::translate("aging_mi_widget", "\346\237\245\346\211\276\346\211\271\346\254\241", nullptr));
        select_pb->setText(QCoreApplication::translate("aging_mi_widget", "\346\237\245\350\257\242", nullptr));
        stop_id_lb->setText(QCoreApplication::translate("aging_mi_widget", "\347\273\223\346\235\237\347\274\226\345\217\267", nullptr));
        msg_lb->setText(QString());
        pushButton->setText(QCoreApplication::translate("aging_mi_widget", "\344\277\256\346\224\271\347\256\227\346\263\225\345\217\202\346\225\260", nullptr));
        export_pb->setText(QCoreApplication::translate("aging_mi_widget", "\346\212\245\345\221\212\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aging_mi_widget: public Ui_aging_mi_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGING_MI_WIDGET_H
