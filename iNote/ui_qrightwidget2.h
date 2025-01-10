/********************************************************************************
** Form generated from reading UI file 'qrightwidget2.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRIGHTWIDGET2_H
#define UI_QRIGHTWIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRightWidget2
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *m_tabWidget;

    void setupUi(QWidget *QRightWidget2)
    {
        if (QRightWidget2->objectName().isEmpty())
            QRightWidget2->setObjectName(QString::fromUtf8("QRightWidget2"));
        QRightWidget2->resize(575, 436);
        horizontalLayout = new QHBoxLayout(QRightWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_tabWidget = new QTabWidget(QRightWidget2);
        m_tabWidget->setObjectName(QString::fromUtf8("m_tabWidget"));
        m_tabWidget->setStyleSheet(QString::fromUtf8("background:rgb(240, 240, 240)\n"
"\n"
""));

        horizontalLayout->addWidget(m_tabWidget);


        retranslateUi(QRightWidget2);

        m_tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QRightWidget2);
    } // setupUi

    void retranslateUi(QWidget *QRightWidget2)
    {
        QRightWidget2->setWindowTitle(QCoreApplication::translate("QRightWidget2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRightWidget2: public Ui_QRightWidget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRIGHTWIDGET2_H
