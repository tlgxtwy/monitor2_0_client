/********************************************************************************
** Form generated from reading UI file 'flipover_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIPOVER_WIDGET_H
#define UI_FLIPOVER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flipover_widget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *allpg_lb;
    QComboBox *onepagenumm_cb;
    QSpacerItem *horizontalSpacer;
    QToolButton *first_bt;
    QToolButton *previous_bt;
    QToolButton *current_bt;
    QToolButton *next_bt;
    QToolButton *last_bt;
    QSpacerItem *horizontalSpacer_2;
    QLabel *jump_lb;
    QLineEdit *jump_ledit;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *flipover_widget)
    {
        if (flipover_widget->objectName().isEmpty())
            flipover_widget->setObjectName(QString::fromUtf8("flipover_widget"));
        flipover_widget->resize(699, 62);
        horizontalLayout = new QHBoxLayout(flipover_widget);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        allpg_lb = new QLabel(flipover_widget);
        allpg_lb->setObjectName(QString::fromUtf8("allpg_lb"));
        allpg_lb->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));
        allpg_lb->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(allpg_lb);

        onepagenumm_cb = new QComboBox(flipover_widget);
        onepagenumm_cb->setObjectName(QString::fromUtf8("onepagenumm_cb"));
        onepagenumm_cb->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(onepagenumm_cb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        first_bt = new QToolButton(flipover_widget);
        first_bt->setObjectName(QString::fromUtf8("first_bt"));
        first_bt->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(first_bt);

        previous_bt = new QToolButton(flipover_widget);
        previous_bt->setObjectName(QString::fromUtf8("previous_bt"));
        previous_bt->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(previous_bt);

        current_bt = new QToolButton(flipover_widget);
        current_bt->setObjectName(QString::fromUtf8("current_bt"));
        current_bt->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(current_bt);

        next_bt = new QToolButton(flipover_widget);
        next_bt->setObjectName(QString::fromUtf8("next_bt"));
        next_bt->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(next_bt);

        last_bt = new QToolButton(flipover_widget);
        last_bt->setObjectName(QString::fromUtf8("last_bt"));
        last_bt->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(last_bt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        jump_lb = new QLabel(flipover_widget);
        jump_lb->setObjectName(QString::fromUtf8("jump_lb"));
        jump_lb->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));
        jump_lb->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(jump_lb);

        jump_ledit = new QLineEdit(flipover_widget);
        jump_ledit->setObjectName(QString::fromUtf8("jump_ledit"));
        jump_ledit->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));

        horizontalLayout->addWidget(jump_ledit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(7, 1);
        horizontalLayout->setStretch(8, 2);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 1);
        horizontalLayout->setStretch(11, 2);

        retranslateUi(flipover_widget);

        QMetaObject::connectSlotsByName(flipover_widget);
    } // setupUi

    void retranslateUi(QWidget *flipover_widget)
    {
        flipover_widget->setWindowTitle(QCoreApplication::translate("flipover_widget", "Form", nullptr));
        allpg_lb->setText(QString());
        first_bt->setText(QCoreApplication::translate("flipover_widget", "...", nullptr));
        previous_bt->setText(QCoreApplication::translate("flipover_widget", "...", nullptr));
        current_bt->setText(QCoreApplication::translate("flipover_widget", "...", nullptr));
        next_bt->setText(QCoreApplication::translate("flipover_widget", "...", nullptr));
        last_bt->setText(QCoreApplication::translate("flipover_widget", "...", nullptr));
        jump_lb->setText(QCoreApplication::translate("flipover_widget", "\350\267\263\350\275\254\345\210\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class flipover_widget: public Ui_flipover_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIPOVER_WIDGET_H
