/********************************************************************************
** Form generated from reading UI file 'user_login_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_LOGIN_DLG_H
#define UI_USER_LOGIN_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_user_login_dlg
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *password_edt;
    QLabel *password;
    QComboBox *account_cb;
    QLabel *account;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *login_pb;
    QPushButton *exit_pb;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *user_login_dlg)
    {
        if (user_login_dlg->objectName().isEmpty())
            user_login_dlg->setObjectName(QString::fromUtf8("user_login_dlg"));
        user_login_dlg->resize(612, 429);
        gridLayout_2 = new QGridLayout(user_login_dlg);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        password_edt = new QLineEdit(user_login_dlg);
        password_edt->setObjectName(QString::fromUtf8("password_edt"));

        gridLayout->addWidget(password_edt, 2, 1, 1, 1);

        password = new QLabel(user_login_dlg);
        password->setObjectName(QString::fromUtf8("password"));

        gridLayout->addWidget(password, 2, 0, 1, 1);

        account_cb = new QComboBox(user_login_dlg);
        account_cb->setObjectName(QString::fromUtf8("account_cb"));

        gridLayout->addWidget(account_cb, 1, 1, 1, 1);

        account = new QLabel(user_login_dlg);
        account->setObjectName(QString::fromUtf8("account"));

        gridLayout->addWidget(account, 1, 0, 1, 1);

        label = new QLabel(user_login_dlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(user_login_dlg);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        login_pb = new QPushButton(user_login_dlg);
        login_pb->setObjectName(QString::fromUtf8("login_pb"));

        horizontalLayout->addWidget(login_pb);

        exit_pb = new QPushButton(user_login_dlg);
        exit_pb->setObjectName(QString::fromUtf8("exit_pb"));

        horizontalLayout->addWidget(exit_pb);


        gridLayout_2->addLayout(horizontalLayout, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 145, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 1, 1, 1);


        retranslateUi(user_login_dlg);

        QMetaObject::connectSlotsByName(user_login_dlg);
    } // setupUi

    void retranslateUi(QDialog *user_login_dlg)
    {
        user_login_dlg->setWindowTitle(QCoreApplication::translate("user_login_dlg", "Dialog", nullptr));
        password->setText(QCoreApplication::translate("user_login_dlg", "\345\257\206\347\240\201:", nullptr));
        account->setText(QCoreApplication::translate("user_login_dlg", "\350\264\246\346\210\267:", nullptr));
        label->setText(QCoreApplication::translate("user_login_dlg", "\346\234\215\345\212\241\345\231\250", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("user_login_dlg", "\350\200\201\345\214\226\346\210\277", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("user_login_dlg", "\346\265\213\350\257\225", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("user_login_dlg", "\346\234\254\346\234\272", nullptr));

        login_pb->setText(QCoreApplication::translate("user_login_dlg", "\347\231\273\345\275\225", nullptr));
        exit_pb->setText(QCoreApplication::translate("user_login_dlg", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_login_dlg: public Ui_user_login_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_LOGIN_DLG_H
