/********************************************************************************
** Form generated from reading UI file 'workorder_list_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKORDER_LIST_DLG_H
#define UI_WORKORDER_LIST_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
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

class Ui_workorder_list_dlg
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QLabel *workorder_lb;
    QLineEdit *workorder_edt;
    QLabel *mi_nums_lb;
    QSpacerItem *horizontalSpacer;
    QPushButton *read_pb;
    QPushButton *write_pb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *mi_list_lb;
    QLineEdit *start_mi_edt;
    QLabel *label_3;
    QLineEdit *stop_mi_edt;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *a_table_wd;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *a_mi_lb;
    QLineEdit *a_mi_edt;
    QPushButton *a_plus_pb;
    QPushButton *a_minus_edt;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *l_table_wd;
    QWidget *widget_3;
    QFormLayout *formLayout_2;
    QLabel *l_mi_lb;
    QLineEdit *l_mi_edt;
    QPushButton *l_plus_pb;
    QPushButton *l_minus_edt;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok_pb;
    QPushButton *cache_pb;

    void setupUi(QDialog *workorder_list_dlg)
    {
        if (workorder_list_dlg->objectName().isEmpty())
            workorder_list_dlg->setObjectName(QString::fromUtf8("workorder_list_dlg"));
        workorder_list_dlg->resize(681, 679);
        verticalLayout_3 = new QVBoxLayout(workorder_list_dlg);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_6 = new QWidget(workorder_list_dlg);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget_6);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_4->addWidget(comboBox);

        workorder_lb = new QLabel(widget_6);
        workorder_lb->setObjectName(QString::fromUtf8("workorder_lb"));

        horizontalLayout_4->addWidget(workorder_lb);

        workorder_edt = new QLineEdit(widget_6);
        workorder_edt->setObjectName(QString::fromUtf8("workorder_edt"));

        horizontalLayout_4->addWidget(workorder_edt);

        mi_nums_lb = new QLabel(widget_6);
        mi_nums_lb->setObjectName(QString::fromUtf8("mi_nums_lb"));

        horizontalLayout_4->addWidget(mi_nums_lb);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        read_pb = new QPushButton(widget_6);
        read_pb->setObjectName(QString::fromUtf8("read_pb"));

        horizontalLayout_4->addWidget(read_pb);

        write_pb = new QPushButton(widget_6);
        write_pb->setObjectName(QString::fromUtf8("write_pb"));

        horizontalLayout_4->addWidget(write_pb);


        verticalLayout_3->addWidget(widget_6);

        widget = new QWidget(workorder_list_dlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mi_list_lb = new QLabel(widget);
        mi_list_lb->setObjectName(QString::fromUtf8("mi_list_lb"));

        horizontalLayout->addWidget(mi_list_lb);

        start_mi_edt = new QLineEdit(widget);
        start_mi_edt->setObjectName(QString::fromUtf8("start_mi_edt"));

        horizontalLayout->addWidget(start_mi_edt);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        stop_mi_edt = new QLineEdit(widget);
        stop_mi_edt->setObjectName(QString::fromUtf8("stop_mi_edt"));

        horizontalLayout->addWidget(stop_mi_edt);


        verticalLayout_3->addWidget(widget);

        widget_5 = new QWidget(workorder_list_dlg);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        a_table_wd = new QTableWidget(groupBox);
        a_table_wd->setObjectName(QString::fromUtf8("a_table_wd"));

        verticalLayout_2->addWidget(a_table_wd);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        formLayout = new QFormLayout(widget_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(2);
        formLayout->setVerticalSpacing(2);
        formLayout->setContentsMargins(0, 0, 0, 0);
        a_mi_lb = new QLabel(widget_2);
        a_mi_lb->setObjectName(QString::fromUtf8("a_mi_lb"));

        formLayout->setWidget(0, QFormLayout::LabelRole, a_mi_lb);

        a_mi_edt = new QLineEdit(widget_2);
        a_mi_edt->setObjectName(QString::fromUtf8("a_mi_edt"));

        formLayout->setWidget(0, QFormLayout::FieldRole, a_mi_edt);

        a_plus_pb = new QPushButton(widget_2);
        a_plus_pb->setObjectName(QString::fromUtf8("a_plus_pb"));

        formLayout->setWidget(1, QFormLayout::LabelRole, a_plus_pb);

        a_minus_edt = new QPushButton(widget_2);
        a_minus_edt->setObjectName(QString::fromUtf8("a_minus_edt"));

        formLayout->setWidget(1, QFormLayout::FieldRole, a_minus_edt);


        verticalLayout_2->addWidget(widget_2);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        l_table_wd = new QTableWidget(groupBox_2);
        l_table_wd->setObjectName(QString::fromUtf8("l_table_wd"));

        verticalLayout->addWidget(l_table_wd);

        widget_3 = new QWidget(groupBox_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        formLayout_2 = new QFormLayout(widget_3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(2);
        formLayout_2->setVerticalSpacing(2);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        l_mi_lb = new QLabel(widget_3);
        l_mi_lb->setObjectName(QString::fromUtf8("l_mi_lb"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, l_mi_lb);

        l_mi_edt = new QLineEdit(widget_3);
        l_mi_edt->setObjectName(QString::fromUtf8("l_mi_edt"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, l_mi_edt);

        l_plus_pb = new QPushButton(widget_3);
        l_plus_pb->setObjectName(QString::fromUtf8("l_plus_pb"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, l_plus_pb);

        l_minus_edt = new QPushButton(widget_3);
        l_minus_edt->setObjectName(QString::fromUtf8("l_minus_edt"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, l_minus_edt);


        verticalLayout->addWidget(widget_3);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_3->addWidget(widget_5);

        widget_4 = new QWidget(workorder_list_dlg);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(464, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ok_pb = new QPushButton(widget_4);
        ok_pb->setObjectName(QString::fromUtf8("ok_pb"));

        horizontalLayout_2->addWidget(ok_pb);

        cache_pb = new QPushButton(widget_4);
        cache_pb->setObjectName(QString::fromUtf8("cache_pb"));

        horizontalLayout_2->addWidget(cache_pb);


        verticalLayout_3->addWidget(widget_4);


        retranslateUi(workorder_list_dlg);

        QMetaObject::connectSlotsByName(workorder_list_dlg);
    } // setupUi

    void retranslateUi(QDialog *workorder_list_dlg)
    {
        workorder_list_dlg->setWindowTitle(QCoreApplication::translate("workorder_list_dlg", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("workorder_list_dlg", "ERP\347\263\273\347\273\237", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("workorder_list_dlg", "\344\272\221\347\253\257\347\263\273\347\273\237", nullptr));

        workorder_lb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\267\245\345\215\225\345\217\267\357\274\232", nullptr));
        mi_nums_lb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\276\256\351\200\206\346\200\273\346\225\260\357\274\232", nullptr));
        read_pb->setText(QCoreApplication::translate("workorder_list_dlg", "\344\273\216\347\263\273\347\273\237\350\257\273\345\217\226", nullptr));
        write_pb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\275\225\345\205\245\344\272\221\347\253\257\347\263\273\347\273\237", nullptr));
        mi_list_lb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\276\256\351\200\206\350\277\236\347\273\255\345\272\217\345\210\227\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("workorder_list_dlg", "~", nullptr));
        groupBox->setTitle(QCoreApplication::translate("workorder_list_dlg", "\350\277\236\347\273\255\347\274\226\345\217\267\345\244\226\347\232\204\351\242\235\345\244\226\345\276\256\351\200\206\347\274\226\345\217\267", nullptr));
        a_mi_lb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\276\256\351\200\206\347\274\226\345\217\267", nullptr));
        a_plus_pb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\242\236\345\212\240", nullptr));
        a_minus_edt->setText(QCoreApplication::translate("workorder_list_dlg", "\345\210\240\351\231\244", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("workorder_list_dlg", "\350\277\236\347\273\255\347\274\226\345\217\267\345\206\205\347\274\272\345\244\261\345\276\256\351\200\206\347\274\226\345\217\267", nullptr));
        l_mi_lb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\276\256\351\200\206\347\274\226\345\217\267", nullptr));
        l_plus_pb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\242\236\345\212\240", nullptr));
        l_minus_edt->setText(QCoreApplication::translate("workorder_list_dlg", "\345\210\240\351\231\244", nullptr));
        ok_pb->setText(QCoreApplication::translate("workorder_list_dlg", "\347\241\256\345\256\232", nullptr));
        cache_pb->setText(QCoreApplication::translate("workorder_list_dlg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class workorder_list_dlg: public Ui_workorder_list_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKORDER_LIST_DLG_H
