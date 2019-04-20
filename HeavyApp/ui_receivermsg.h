/********************************************************************************
** Form generated from reading UI file 'receivermsg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVERMSG_H
#define UI_RECEIVERMSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiverMsg
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *nameText;
    QLabel *sentText;

    void setupUi(QWidget *ReceiverMsg)
    {
        if (ReceiverMsg->objectName().isEmpty())
            ReceiverMsg->setObjectName(QString::fromUtf8("ReceiverMsg"));
        ReceiverMsg->resize(511, 116);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReceiverMsg->sizePolicy().hasHeightForWidth());
        ReceiverMsg->setSizePolicy(sizePolicy);
        ReceiverMsg->setMaximumSize(QSize(16777215, 131));
        gridLayout = new QGridLayout(ReceiverMsg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(ReceiverMsg);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(479, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        nameText = new QLabel(frame);
        nameText->setObjectName(QString::fromUtf8("nameText"));

        gridLayout_2->addWidget(nameText, 0, 0, 1, 1);

        sentText = new QLabel(frame);
        sentText->setObjectName(QString::fromUtf8("sentText"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sentText->sizePolicy().hasHeightForWidth());
        sentText->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(sentText, 1, 0, 1, 2);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ReceiverMsg);

        QMetaObject::connectSlotsByName(ReceiverMsg);
    } // setupUi

    void retranslateUi(QWidget *ReceiverMsg)
    {
        ReceiverMsg->setWindowTitle(QApplication::translate("ReceiverMsg", "Form", nullptr));
        nameText->setText(QApplication::translate("ReceiverMsg", "Expediteur", nullptr));
        sentText->setText(QApplication::translate("ReceiverMsg", "Ceci est un message re\303\247u.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceiverMsg: public Ui_ReceiverMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVERMSG_H
