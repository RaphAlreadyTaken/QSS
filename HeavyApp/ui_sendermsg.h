/********************************************************************************
** Form generated from reading UI file 'sendermsg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDERMSG_H
#define UI_SENDERMSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SenderMsg
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *nameText;
    QLabel *sentText;

    void setupUi(QWidget *SenderMsg)
    {
        if (SenderMsg->objectName().isEmpty())
            SenderMsg->setObjectName(QString::fromUtf8("SenderMsg"));
        SenderMsg->resize(530, 131);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SenderMsg->sizePolicy().hasHeightForWidth());
        SenderMsg->setSizePolicy(sizePolicy);
        SenderMsg->setMaximumSize(QSize(16777215, 131));
        gridLayout_2 = new QGridLayout(SenderMsg);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(SenderMsg);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(323, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        nameText = new QLabel(frame);
        nameText->setObjectName(QString::fromUtf8("nameText"));

        gridLayout->addWidget(nameText, 2, 3, 1, 1);

        sentText = new QLabel(frame);
        sentText->setObjectName(QString::fromUtf8("sentText"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sentText->sizePolicy().hasHeightForWidth());
        sentText->setSizePolicy(sizePolicy2);
        sentText->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(sentText, 3, 2, 1, 2);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(SenderMsg);

        QMetaObject::connectSlotsByName(SenderMsg);
    } // setupUi

    void retranslateUi(QWidget *SenderMsg)
    {
        SenderMsg->setWindowTitle(QApplication::translate("SenderMsg", "Form", nullptr));
        nameText->setText(QApplication::translate("SenderMsg", "Vous", nullptr));
        sentText->setText(QApplication::translate("SenderMsg", "Ceci est un message envoy\303\251.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SenderMsg: public Ui_SenderMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDERMSG_H
