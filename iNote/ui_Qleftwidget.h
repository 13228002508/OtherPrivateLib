/********************************************************************************
** Form generated from reading UI file 'Qleftwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLEFTWIDGET_H
#define UI_QLEFTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qselflistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_QLeftWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *m_tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QSelfListWidget *m_listWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *m_treeWidget;

    void setupUi(QWidget *QLeftWidget)
    {
        if (QLeftWidget->objectName().isEmpty())
            QLeftWidget->setObjectName(QString::fromUtf8("QLeftWidget"));
        QLeftWidget->resize(378, 440);
        verticalLayout = new QVBoxLayout(QLeftWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_tabWidget = new QTabWidget(QLeftWidget);
        m_tabWidget->setObjectName(QString::fromUtf8("m_tabWidget"));
        m_tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_listWidget = new QSelfListWidget(tab);
        m_listWidget->setObjectName(QString::fromUtf8("m_listWidget"));
        m_listWidget->setEnabled(true);
        m_listWidget->setTabletTracking(false);
        m_listWidget->setFrameShape(QFrame::NoFrame);
        m_listWidget->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(m_listWidget);

        m_tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        m_treeWidget->setHeaderItem(__qtreewidgetitem);
        m_treeWidget->setObjectName(QString::fromUtf8("m_treeWidget"));

        verticalLayout_2->addWidget(m_treeWidget);

        m_tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(m_tabWidget);


        retranslateUi(QLeftWidget);

        m_tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QLeftWidget);
    } // setupUi

    void retranslateUi(QWidget *QLeftWidget)
    {
        QLeftWidget->setWindowTitle(QCoreApplication::translate("QLeftWidget", "Form", nullptr));
        m_tabWidget->setTabText(m_tabWidget->indexOf(tab), QCoreApplication::translate("QLeftWidget", "\346\226\207\344\273\266", nullptr));
        m_tabWidget->setTabText(m_tabWidget->indexOf(tab_2), QCoreApplication::translate("QLeftWidget", "\345\244\247\347\272\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QLeftWidget: public Ui_QLeftWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLEFTWIDGET_H
