/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include <my_stacked_widget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *sys_setting;
    QAction *account_switches;
    QAction *action;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    my_stacked_widget *st_widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        sys_setting = new QAction(MainWindow);
        sys_setting->setObjectName(QString::fromUtf8("sys_setting"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/sysset.png"), QSize(), QIcon::Normal, QIcon::Off);
        sys_setting->setIcon(icon);
        account_switches = new QAction(MainWindow);
        account_switches->setObjectName(QString::fromUtf8("account_switches"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/err_analysis.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setStyleSheet(QString::fromUtf8("QTreeView{\n"
"	font-size:21px;\n"
"}\n"
"QTreeView::item{\n"
"    height:45px\n"
"}\n"
"QHeaderView::section{font:18px;height:28px;}"));
        splitter->addWidget(treeView);
        st_widget = new my_stacked_widget(splitter);
        st_widget->setObjectName(QString::fromUtf8("st_widget"));
        splitter->addWidget(st_widget);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(account_switches);
        toolBar->addAction(action);
        toolBar->addAction(sys_setting);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sys_setting->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        sys_setting->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250\344\272\216\351\205\215\347\275\256\347\263\273\347\273\237\351\234\200\350\246\201\347\232\204\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        account_switches->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\350\264\246\345\217\267", nullptr));
#if QT_CONFIG(tooltip)
        account_switches->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250\344\272\216\345\210\207\346\215\242\345\275\223\345\211\215\350\264\246\346\210\267", nullptr));
#endif // QT_CONFIG(tooltip)
        action->setText(QCoreApplication::translate("MainWindow", "\351\224\231\350\257\257\344\273\243\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        action->setToolTip(QCoreApplication::translate("MainWindow", "\347\224\250\344\272\216\351\224\231\350\257\257\344\273\243\347\240\201\350\247\243\346\236\220", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
