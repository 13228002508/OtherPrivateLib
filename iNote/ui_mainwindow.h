/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionfristTitle;
    QAction *actionSecondTitle;
    QAction *actionThirdTitle;
    QAction *actionfourthTitle;
    QAction *actionContent;
    QAction *actionBold;
    QAction *actionitalic;
    QAction *actionCode;
    QAction *actionCode_2;
    QAction *actionHttpLinl;
    QAction *actionShowSiderbar;
    QAction *actionfileOutLine;
    QAction *actionfileList;
    QAction *actionantTionOpenFilePath;
    QAction *actSave;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuRedo;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(892, 639);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Res/log.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionfristTitle = new QAction(MainWindow);
        actionfristTitle->setObjectName(QString::fromUtf8("actionfristTitle"));
        actionSecondTitle = new QAction(MainWindow);
        actionSecondTitle->setObjectName(QString::fromUtf8("actionSecondTitle"));
        actionThirdTitle = new QAction(MainWindow);
        actionThirdTitle->setObjectName(QString::fromUtf8("actionThirdTitle"));
        actionfourthTitle = new QAction(MainWindow);
        actionfourthTitle->setObjectName(QString::fromUtf8("actionfourthTitle"));
        actionContent = new QAction(MainWindow);
        actionContent->setObjectName(QString::fromUtf8("actionContent"));
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionitalic = new QAction(MainWindow);
        actionitalic->setObjectName(QString::fromUtf8("actionitalic"));
        actionCode = new QAction(MainWindow);
        actionCode->setObjectName(QString::fromUtf8("actionCode"));
        actionCode_2 = new QAction(MainWindow);
        actionCode_2->setObjectName(QString::fromUtf8("actionCode_2"));
        actionHttpLinl = new QAction(MainWindow);
        actionHttpLinl->setObjectName(QString::fromUtf8("actionHttpLinl"));
        actionShowSiderbar = new QAction(MainWindow);
        actionShowSiderbar->setObjectName(QString::fromUtf8("actionShowSiderbar"));
        actionfileOutLine = new QAction(MainWindow);
        actionfileOutLine->setObjectName(QString::fromUtf8("actionfileOutLine"));
        actionfileList = new QAction(MainWindow);
        actionfileList->setObjectName(QString::fromUtf8("actionfileList"));
        actionantTionOpenFilePath = new QAction(MainWindow);
        actionantTionOpenFilePath->setObjectName(QString::fromUtf8("actionantTionOpenFilePath"));
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 892, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuRedo = new QMenu(menuBar);
        menuRedo->setObjectName(QString::fromUtf8("menuRedo"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuRedo->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(actionNew);
        menu->addSeparator();
        menu->addAction(actionOpen);
        menu->addAction(actionantTionOpenFilePath);
        menuRedo->addAction(actSave);
        menu_2->addAction(actionfristTitle);
        menu_2->addAction(actionSecondTitle);
        menu_2->addAction(actionThirdTitle);
        menu_2->addAction(actionfourthTitle);
        menu_2->addSeparator();
        menu_2->addAction(actionContent);
        menu_3->addAction(actionBold);
        menu_3->addAction(actionitalic);
        menu_3->addAction(actionCode);
        menu_3->addAction(actionCode_2);
        menu_3->addAction(actionHttpLinl);
        menu_4->addAction(actionShowSiderbar);
        menu_4->addAction(actionfileOutLine);
        menu_4->addAction(actionfileList);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "iNote", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        actionfristTitle->setText(QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(shortcut)
        actionfristTitle->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSecondTitle->setText(QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(shortcut)
        actionSecondTitle->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionThirdTitle->setText(QCoreApplication::translate("MainWindow", "\344\270\211\347\272\247\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(shortcut)
        actionThirdTitle->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionfourthTitle->setText(QCoreApplication::translate("MainWindow", "\345\233\233\347\272\247\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(shortcut)
        actionfourthTitle->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionContent->setText(QCoreApplication::translate("MainWindow", "\346\256\265\350\220\275", nullptr));
#if QT_CONFIG(shortcut)
        actionContent->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBold->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227", nullptr));
#if QT_CONFIG(shortcut)
        actionBold->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionitalic->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        actionitalic->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCode->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(shortcut)
        actionCode->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCode_2->setText(QCoreApplication::translate("MainWindow", "\344\273\243\347\240\201", nullptr));
        actionHttpLinl->setText(QCoreApplication::translate("MainWindow", "\350\266\205\351\223\276\346\216\245", nullptr));
        actionShowSiderbar->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272/\351\232\220\350\227\217\344\276\247\350\276\271\346\240\217", nullptr));
        actionfileOutLine->setText(QCoreApplication::translate("MainWindow", "\345\244\247\347\272\262", nullptr));
        actionfileList->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\241\243\345\210\227\350\241\250", nullptr));
        actionantTionOpenFilePath->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        actSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#if QT_CONFIG(tooltip)
        actSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuRedo->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\256\265\350\220\275", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\344\270\273\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
