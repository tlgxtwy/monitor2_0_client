/********************************************************************************
** Form generated from reading UI file 'draw_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAW_WIDGET_H
#define UI_DRAW_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <open_lib/QCustomPlot/qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_draw_widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *name_lb;
    QSpacerItem *horizontalSpacer_4;
    QWidget *bt_group;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *power_rb;
    QRadioButton *volt_rb;
    QRadioButton *temp_rb;
    QRadioButton *gvolt_rb;
    QRadioButton *gfre_rb;
    QRadioButton *eff_rb;
    QSpacerItem *horizontalSpacer_2;
    QCustomPlot *plot_;

    void setupUi(QWidget *draw_widget)
    {
        if (draw_widget->objectName().isEmpty())
            draw_widget->setObjectName(QString::fromUtf8("draw_widget"));
        draw_widget->resize(1088, 937);
        verticalLayout = new QVBoxLayout(draw_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        name_lb = new QLabel(draw_widget);
        name_lb->setObjectName(QString::fromUtf8("name_lb"));
        name_lb->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(name_lb);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        bt_group = new QWidget(draw_widget);
        bt_group->setObjectName(QString::fromUtf8("bt_group"));
        horizontalLayout = new QHBoxLayout(bt_group);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        power_rb = new QRadioButton(bt_group);
        power_rb->setObjectName(QString::fromUtf8("power_rb"));
        power_rb->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        power_rb->setAutoExclusive(false);

        horizontalLayout->addWidget(power_rb);

        volt_rb = new QRadioButton(bt_group);
        volt_rb->setObjectName(QString::fromUtf8("volt_rb"));
        volt_rb->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);"));
        volt_rb->setAutoExclusive(false);

        horizontalLayout->addWidget(volt_rb);

        temp_rb = new QRadioButton(bt_group);
        temp_rb->setObjectName(QString::fromUtf8("temp_rb"));
        temp_rb->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 0);"));
        temp_rb->setAutoExclusive(false);

        horizontalLayout->addWidget(temp_rb);

        gvolt_rb = new QRadioButton(bt_group);
        gvolt_rb->setObjectName(QString::fromUtf8("gvolt_rb"));
        gvolt_rb->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        gvolt_rb->setAutoExclusive(false);

        horizontalLayout->addWidget(gvolt_rb);

        gfre_rb = new QRadioButton(bt_group);
        gfre_rb->setObjectName(QString::fromUtf8("gfre_rb"));
        gfre_rb->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 255);"));
        gfre_rb->setAutoExclusive(false);

        horizontalLayout->addWidget(gfre_rb);

        eff_rb = new QRadioButton(bt_group);
        eff_rb->setObjectName(QString::fromUtf8("eff_rb"));
        eff_rb->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 127);"));

        horizontalLayout->addWidget(eff_rb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(bt_group);

        plot_ = new QCustomPlot(draw_widget);
        plot_->setObjectName(QString::fromUtf8("plot_"));

        verticalLayout->addWidget(plot_);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 15);

        retranslateUi(draw_widget);

        QMetaObject::connectSlotsByName(draw_widget);
    } // setupUi

    void retranslateUi(QWidget *draw_widget)
    {
        draw_widget->setWindowTitle(QCoreApplication::translate("draw_widget", "Form", nullptr));
        name_lb->setText(QString());
        power_rb->setText(QCoreApplication::translate("draw_widget", "\345\217\221\347\224\265\345\212\237\347\216\207(W)", nullptr));
        volt_rb->setText(QCoreApplication::translate("draw_widget", "\347\224\265\345\216\213(V)", nullptr));
        temp_rb->setText(QCoreApplication::translate("draw_widget", "\346\270\251\345\272\246(\342\204\203)", nullptr));
        gvolt_rb->setText(QCoreApplication::translate("draw_widget", "\345\271\266\347\275\221\347\224\265\345\216\213(V)", nullptr));
        gfre_rb->setText(QCoreApplication::translate("draw_widget", "\345\271\266\347\275\221\351\242\221\347\216\207(Hz)", nullptr));
        eff_rb->setText(QCoreApplication::translate("draw_widget", "\346\225\210\347\216\207(%)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class draw_widget: public Ui_draw_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAW_WIDGET_H
