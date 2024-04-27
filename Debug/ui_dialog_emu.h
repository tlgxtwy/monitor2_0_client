/********************************************************************************
** Form generated from reading UI file 'dialog_emu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EMU_H
#define UI_DIALOG_EMU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_emu
{
public:
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_emu_cid;
    QLineEdit *lineEdit_emuCID;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *status_edt;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_EMU_Info_get;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QRadioButton *radioButton_Reflux_ON;
    QRadioButton *radioButton_Reflux_OFF;
    QPushButton *pushButton_Reflux_set;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_EMU_signal;
    QLineEdit *lineEdit_EMU_code;
    QLineEdit *lineEdit_EMU_Mode;
    QLabel *label_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_EMU_Info;

    void setupUi(QDialog *dialog_emu)
    {
        if (dialog_emu->objectName().isEmpty())
            dialog_emu->setObjectName(QString::fromUtf8("dialog_emu"));
        dialog_emu->resize(658, 356);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dialog_emu->sizePolicy().hasHeightForWidth());
        dialog_emu->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(dialog_emu);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(15, 15, 15, 15);
        widget = new QWidget(dialog_emu);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_emu_cid = new QLabel(widget);
        label_emu_cid->setObjectName(QString::fromUtf8("label_emu_cid"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_emu_cid->sizePolicy().hasHeightForWidth());
        label_emu_cid->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        label_emu_cid->setFont(font);

        horizontalLayout->addWidget(label_emu_cid);

        lineEdit_emuCID = new QLineEdit(widget);
        lineEdit_emuCID->setObjectName(QString::fromUtf8("lineEdit_emuCID"));
        sizePolicy.setHeightForWidth(lineEdit_emuCID->sizePolicy().hasHeightForWidth());
        lineEdit_emuCID->setSizePolicy(sizePolicy);
        lineEdit_emuCID->setFont(font);

        horizontalLayout->addWidget(lineEdit_emuCID);

        horizontalSpacer_2 = new QSpacerItem(340, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        widget_3 = new QWidget(dialog_emu);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(label_2);

        status_edt = new QLineEdit(widget_5);
        status_edt->setObjectName(QString::fromUtf8("status_edt"));

        horizontalLayout_3->addWidget(status_edt);

        horizontalSpacer = new QSpacerItem(368, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_EMU_Info_get = new QPushButton(widget_5);
        pushButton_EMU_Info_get->setObjectName(QString::fromUtf8("pushButton_EMU_Info_get"));
        pushButton_EMU_Info_get->setFont(font1);

        horizontalLayout_3->addWidget(pushButton_EMU_Info_get);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 10);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);

        gridLayout_3->addWidget(widget_5, 0, 0, 1, 1);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, -1, -1);
        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        sizePolicy2.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(widget_7);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, 50);
        widget_2 = new QWidget(widget_7);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        radioButton_Reflux_ON = new QRadioButton(widget_2);
        radioButton_Reflux_ON->setObjectName(QString::fromUtf8("radioButton_Reflux_ON"));
        radioButton_Reflux_ON->setFont(font);

        horizontalLayout_2->addWidget(radioButton_Reflux_ON);

        radioButton_Reflux_OFF = new QRadioButton(widget_2);
        radioButton_Reflux_OFF->setObjectName(QString::fromUtf8("radioButton_Reflux_OFF"));
        radioButton_Reflux_OFF->setFont(font);

        horizontalLayout_2->addWidget(radioButton_Reflux_OFF);

        pushButton_Reflux_set = new QPushButton(widget_2);
        pushButton_Reflux_set->setObjectName(QString::fromUtf8("pushButton_Reflux_set"));
        pushButton_Reflux_set->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_Reflux_set);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(widget_7);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_EMU_signal = new QLineEdit(widget_4);
        lineEdit_EMU_signal->setObjectName(QString::fromUtf8("lineEdit_EMU_signal"));
        sizePolicy1.setHeightForWidth(lineEdit_EMU_signal->sizePolicy().hasHeightForWidth());
        lineEdit_EMU_signal->setSizePolicy(sizePolicy1);
        lineEdit_EMU_signal->setFont(font1);
        lineEdit_EMU_signal->setStyleSheet(QString::fromUtf8("background:transparent;border-width:0;border-style:outset"));

        gridLayout_2->addWidget(lineEdit_EMU_signal, 1, 1, 1, 1);

        lineEdit_EMU_code = new QLineEdit(widget_4);
        lineEdit_EMU_code->setObjectName(QString::fromUtf8("lineEdit_EMU_code"));
        sizePolicy1.setHeightForWidth(lineEdit_EMU_code->sizePolicy().hasHeightForWidth());
        lineEdit_EMU_code->setSizePolicy(sizePolicy1);
        lineEdit_EMU_code->setFont(font1);
        lineEdit_EMU_code->setStyleSheet(QString::fromUtf8("background:transparent;border-width:0;border-style:outset"));

        gridLayout_2->addWidget(lineEdit_EMU_code, 2, 1, 1, 1);

        lineEdit_EMU_Mode = new QLineEdit(widget_4);
        lineEdit_EMU_Mode->setObjectName(QString::fromUtf8("lineEdit_EMU_Mode"));
        sizePolicy1.setHeightForWidth(lineEdit_EMU_Mode->sizePolicy().hasHeightForWidth());
        lineEdit_EMU_Mode->setSizePolicy(sizePolicy1);
        lineEdit_EMU_Mode->setFont(font1);
        lineEdit_EMU_Mode->setStyleSheet(QString::fromUtf8("background:transparent;border-width:0;border-style:outset"));

        gridLayout_2->addWidget(lineEdit_EMU_Mode, 0, 1, 1, 1);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_4);


        horizontalLayout_4->addWidget(widget_7);

        groupBox = new QGroupBox(widget_6);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 0);
        textEdit_EMU_Info = new QTextEdit(groupBox);
        textEdit_EMU_Info->setObjectName(QString::fromUtf8("textEdit_EMU_Info"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        textEdit_EMU_Info->setFont(font2);

        gridLayout->addWidget(textEdit_EMU_Info, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox);


        gridLayout_3->addWidget(widget_6, 1, 0, 1, 1);


        gridLayout_4->addWidget(widget_3, 1, 0, 1, 1);


        retranslateUi(dialog_emu);

        QMetaObject::connectSlotsByName(dialog_emu);
    } // setupUi

    void retranslateUi(QDialog *dialog_emu)
    {
        dialog_emu->setWindowTitle(QCoreApplication::translate("dialog_emu", "Dialog", nullptr));
        label_emu_cid->setText(QCoreApplication::translate("dialog_emu", "EMU CID", nullptr));
        label_2->setText(QCoreApplication::translate("dialog_emu", "\347\275\221\345\205\263\347\212\266\346\200\201\357\274\232", nullptr));
        pushButton_EMU_Info_get->setText(QCoreApplication::translate("dialog_emu", "\350\216\267\345\217\226", nullptr));
        label->setText(QCoreApplication::translate("dialog_emu", "\351\230\262\351\200\206\346\265\201\347\212\266\346\200\201\357\274\232", nullptr));
        radioButton_Reflux_ON->setText(QCoreApplication::translate("dialog_emu", "ON", nullptr));
        radioButton_Reflux_OFF->setText(QCoreApplication::translate("dialog_emu", "OFF", nullptr));
        pushButton_Reflux_set->setText(QCoreApplication::translate("dialog_emu", "\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("dialog_emu", "\347\275\221\345\205\263\344\277\241\345\217\267\345\274\272\345\272\246\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("dialog_emu", "\347\275\221\345\205\263\345\212\237\350\203\275\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("dialog_emu", "\347\275\221\345\205\263\350\277\220\350\241\214\346\250\241\345\274\217\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("dialog_emu", "\347\275\221\345\205\263\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_emu: public Ui_dialog_emu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EMU_H
