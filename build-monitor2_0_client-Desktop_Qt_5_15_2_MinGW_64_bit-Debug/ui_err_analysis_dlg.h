/********************************************************************************
** Form generated from reading UI file 'err_analysis_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERR_ANALYSIS_DLG_H
#define UI_ERR_ANALYSIS_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_err_analysis_dlg
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *mim1_edt;
    QLineEdit *mis_edt;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *mim2_edt;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *err_analysis_dlg)
    {
        if (err_analysis_dlg->objectName().isEmpty())
            err_analysis_dlg->setObjectName(QString::fromUtf8("err_analysis_dlg"));
        err_analysis_dlg->resize(713, 506);
        verticalLayout = new QVBoxLayout(err_analysis_dlg);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(err_analysis_dlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("	font-size:30px;\n"
"	height:30px;"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        mim1_edt = new QLineEdit(groupBox);
        mim1_edt->setObjectName(QString::fromUtf8("mim1_edt"));

        gridLayout->addWidget(mim1_edt, 0, 1, 1, 1);

        mis_edt = new QLineEdit(groupBox);
        mis_edt->setObjectName(QString::fromUtf8("mis_edt"));

        gridLayout->addWidget(mis_edt, 2, 1, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        mim2_edt = new QLineEdit(groupBox);
        mim2_edt->setObjectName(QString::fromUtf8("mim2_edt"));

        gridLayout->addWidget(mim2_edt, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(3, 1);

        verticalLayout->addWidget(groupBox);

        textBrowser = new QTextBrowser(err_analysis_dlg);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(err_analysis_dlg);

        QMetaObject::connectSlotsByName(err_analysis_dlg);
    } // setupUi

    void retranslateUi(QDialog *err_analysis_dlg)
    {
        err_analysis_dlg->setWindowTitle(QCoreApplication::translate("err_analysis_dlg", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("err_analysis_dlg", "\346\225\205\351\232\234\346\237\245\350\257\242", nullptr));
        pushButton->setText(QCoreApplication::translate("err_analysis_dlg", "\346\237\245\350\257\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("err_analysis_dlg", "\345\215\225\350\267\257\345\276\256\351\200\206", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("err_analysis_dlg", "\345\217\214\350\267\257\345\276\256\351\200\206", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("err_analysis_dlg", "\345\233\233\350\267\257\345\276\256\351\200\206", nullptr));

        label_2->setText(QCoreApplication::translate("err_analysis_dlg", "\345\211\257\350\276\271\346\225\205\351\232\234\344\273\243\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("err_analysis_dlg", "\345\216\237\350\276\271\346\225\205\351\232\2341\344\273\243\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("err_analysis_dlg", "\345\216\237\350\276\271\346\225\205\351\232\2342\344\273\243\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class err_analysis_dlg: public Ui_err_analysis_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERR_ANALYSIS_DLG_H
