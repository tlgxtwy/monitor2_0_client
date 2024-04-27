/********************************************************************************
** Form generated from reading UI file 'dialog_file.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_FILE_H
#define UI_DIALOG_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialog_file
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *dialog_file)
    {
        if (dialog_file->objectName().isEmpty())
            dialog_file->setObjectName(QString::fromUtf8("dialog_file"));
        dialog_file->resize(174, 68);
        gridLayout = new QGridLayout(dialog_file);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(dialog_file);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setPointSize(10);
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 2);

        pushButton_save = new QPushButton(dialog_file);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        gridLayout->addWidget(pushButton_save, 1, 0, 1, 1);

        pushButton_cancel = new QPushButton(dialog_file);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        gridLayout->addWidget(pushButton_cancel, 1, 1, 1, 1);


        retranslateUi(dialog_file);

        QMetaObject::connectSlotsByName(dialog_file);
    } // setupUi

    void retranslateUi(QDialog *dialog_file)
    {
        dialog_file->setWindowTitle(QCoreApplication::translate("dialog_file", "Dialog", nullptr));
        pushButton_save->setText(QCoreApplication::translate("dialog_file", "\344\277\235\345\255\230", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("dialog_file", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_file: public Ui_dialog_file {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_FILE_H
