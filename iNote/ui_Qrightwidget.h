/********************************************************************************
** Form generated from reading UI file 'Qrightwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRIGHTWIDGET_H
#define UI_QRIGHTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qselfplaintextedit.h"

QT_BEGIN_NAMESPACE

class Ui_QRightWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSelfPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_2;
    QLabel *Rowlabel;
    QLabel *RowVlalueLabe;
    QLabel *ColLable;
    QLabel *CloValue;
    QLabel *CodecLable;
    QLabel *CodecLableValue;

    void setupUi(QWidget *QRightWidget)
    {
        if (QRightWidget->objectName().isEmpty())
            QRightWidget->setObjectName(QString::fromUtf8("QRightWidget"));
        QRightWidget->resize(1017, 816);
        verticalLayout = new QVBoxLayout(QRightWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QSelfPlainTextEdit(QRightWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(12);
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(250,250,250);"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(plainTextEdit);

        groupBox_2 = new QGroupBox(QRightWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("border:none"));
        Rowlabel = new QLabel(groupBox_2);
        Rowlabel->setObjectName(QString::fromUtf8("Rowlabel"));
        Rowlabel->setGeometry(QRect(640, 0, 30, 10));
        RowVlalueLabe = new QLabel(groupBox_2);
        RowVlalueLabe->setObjectName(QString::fromUtf8("RowVlalueLabe"));
        RowVlalueLabe->setGeometry(QRect(663, 0, 60, 10));
        ColLable = new QLabel(groupBox_2);
        ColLable->setObjectName(QString::fromUtf8("ColLable"));
        ColLable->setGeometry(QRect(750, 0, 30, 10));
        CloValue = new QLabel(groupBox_2);
        CloValue->setObjectName(QString::fromUtf8("CloValue"));
        CloValue->setGeometry(QRect(773, 0, 60, 10));
        CodecLable = new QLabel(groupBox_2);
        CodecLable->setObjectName(QString::fromUtf8("CodecLable"));
        CodecLable->setGeometry(QRect(830, 0, 35, 10));
        CodecLableValue = new QLabel(groupBox_2);
        CodecLableValue->setObjectName(QString::fromUtf8("CodecLableValue"));
        CodecLableValue->setGeometry(QRect(870, 0, 61, 10));

        verticalLayout->addWidget(groupBox_2);

        verticalLayout->setStretch(0, 55);
        verticalLayout->setStretch(1, 1);

        retranslateUi(QRightWidget);

        QMetaObject::connectSlotsByName(QRightWidget);
    } // setupUi

    void retranslateUi(QWidget *QRightWidget)
    {
        QRightWidget->setWindowTitle(QCoreApplication::translate("QRightWidget", "Form", nullptr));
        groupBox_2->setTitle(QString());
        Rowlabel->setText(QCoreApplication::translate("QRightWidget", "Row\357\274\232", nullptr));
        RowVlalueLabe->setText(QString());
        ColLable->setText(QCoreApplication::translate("QRightWidget", "Col\357\274\232", nullptr));
        CloValue->setText(QString());
        CodecLable->setText(QCoreApplication::translate("QRightWidget", "Codec\357\274\232", nullptr));
        CodecLableValue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QRightWidget: public Ui_QRightWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRIGHTWIDGET_H
