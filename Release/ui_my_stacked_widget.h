/********************************************************************************
** Form generated from reading UI file 'my_stacked_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_STACKED_WIDGET_H
#define UI_MY_STACKED_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_stacked_widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *my_stacked_widget)
    {
        if (my_stacked_widget->objectName().isEmpty())
            my_stacked_widget->setObjectName(QString::fromUtf8("my_stacked_widget"));
        my_stacked_widget->resize(681, 507);
        gridLayout = new QGridLayout(my_stacked_widget);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(my_stacked_widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer = new QSpacerItem(677, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 20);

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(my_stacked_widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 30);

        retranslateUi(my_stacked_widget);

        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(my_stacked_widget);
    } // setupUi

    void retranslateUi(QWidget *my_stacked_widget)
    {
        my_stacked_widget->setWindowTitle(QCoreApplication::translate("my_stacked_widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class my_stacked_widget: public Ui_my_stacked_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_STACKED_WIDGET_H
