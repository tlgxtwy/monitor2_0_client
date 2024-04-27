/********************************************************************************
** Form generated from reading UI file 'realdata_time_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALDATA_TIME_WIDGET_H
#define UI_REALDATA_TIME_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_realdata_time_widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_station;
    QSpacerItem *horizontalSpacer;
    QPushButton *select_bt;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *realdata_time_widget)
    {
        if (realdata_time_widget->objectName().isEmpty())
            realdata_time_widget->setObjectName(QString::fromUtf8("realdata_time_widget"));
        realdata_time_widget->resize(1085, 833);
        gridLayout = new QGridLayout(realdata_time_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        add_station = new QPushButton(realdata_time_widget);
        add_station->setObjectName(QString::fromUtf8("add_station"));

        horizontalLayout->addWidget(add_station);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        select_bt = new QPushButton(realdata_time_widget);
        select_bt->setObjectName(QString::fromUtf8("select_bt"));

        horizontalLayout->addWidget(select_bt);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        treeWidget = new QTreeWidget(realdata_time_widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout->addWidget(treeWidget, 1, 0, 1, 1);


        retranslateUi(realdata_time_widget);

        QMetaObject::connectSlotsByName(realdata_time_widget);
    } // setupUi

    void retranslateUi(QWidget *realdata_time_widget)
    {
        realdata_time_widget->setWindowTitle(QCoreApplication::translate("realdata_time_widget", "Form", nullptr));
        add_station->setText(QCoreApplication::translate("realdata_time_widget", "\346\267\273\345\212\240\347\224\265\347\253\231", nullptr));
        select_bt->setText(QCoreApplication::translate("realdata_time_widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class realdata_time_widget: public Ui_realdata_time_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALDATA_TIME_WIDGET_H
