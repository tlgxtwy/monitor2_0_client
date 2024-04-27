/********************************************************************************
** Form generated from reading UI file 'close_button.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSE_BUTTON_H
#define UI_CLOSE_BUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_close_button
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QWidget *close_button)
    {
        if (close_button->objectName().isEmpty())
            close_button->setObjectName(QString::fromUtf8("close_button"));
        close_button->resize(102, 48);
        close_button->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));
        horizontalLayout = new QHBoxLayout(close_button);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 0, 1, 0);
        label = new QLabel(close_button);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(close_button);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(toolButton);


        retranslateUi(close_button);

        QMetaObject::connectSlotsByName(close_button);
    } // setupUi

    void retranslateUi(QWidget *close_button)
    {
        close_button->setWindowTitle(QCoreApplication::translate("close_button", "Form", nullptr));
        label->setText(QString());
        toolButton->setText(QCoreApplication::translate("close_button", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class close_button: public Ui_close_button {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSE_BUTTON_H
