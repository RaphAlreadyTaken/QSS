/********************************************************************************
** Form generated from reading UI file 'convtab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVTAB_H
#define UI_CONVTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConvTab
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *correspondantName;
    QLabel *newMsgLabel;

    void setupUi(QWidget *ConvTab)
    {
        if (ConvTab->objectName().isEmpty())
            ConvTab->setObjectName(QString::fromUtf8("ConvTab"));
        ConvTab->resize(200, 60);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConvTab->sizePolicy().hasHeightForWidth());
        ConvTab->setSizePolicy(sizePolicy);
        ConvTab->setMinimumSize(QSize(200, 60));
        ConvTab->setMaximumSize(QSize(200, 60));
        horizontalLayout = new QHBoxLayout(ConvTab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(ConvTab);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        correspondantName = new QLabel(frame);
        correspondantName->setObjectName(QString::fromUtf8("correspondantName"));

        horizontalLayout_2->addWidget(correspondantName);

        newMsgLabel = new QLabel(frame);
        newMsgLabel->setObjectName(QString::fromUtf8("newMsgLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(newMsgLabel->sizePolicy().hasHeightForWidth());
        newMsgLabel->setSizePolicy(sizePolicy2);
        newMsgLabel->setMaximumSize(QSize(16, 16));
        newMsgLabel->setPixmap(QPixmap(QString::fromUtf8(":/img/red_dot.png")));
        newMsgLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(newMsgLabel);


        horizontalLayout->addWidget(frame);


        retranslateUi(ConvTab);

        QMetaObject::connectSlotsByName(ConvTab);
    } // setupUi

    void retranslateUi(QWidget *ConvTab)
    {
        ConvTab->setWindowTitle(QApplication::translate("ConvTab", "Form", nullptr));
        correspondantName->setText(QApplication::translate("ConvTab", "TextLabel", nullptr));
        newMsgLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConvTab: public Ui_ConvTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVTAB_H
