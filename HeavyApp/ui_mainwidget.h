/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QScrollArea *convListLayout;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *msgDisplayingArea;
    QWidget *msgDisplayLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *sendButton;
    QPlainTextEdit *textSendingArea;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1276, 770);
        gridLayout_2 = new QGridLayout(MainWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(MainWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(265, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        convListLayout = new QScrollArea(frame);
        convListLayout->setObjectName(QString::fromUtf8("convListLayout"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(convListLayout->sizePolicy().hasHeightForWidth());
        convListLayout->setSizePolicy(sizePolicy);
        convListLayout->setFrameShape(QFrame::NoFrame);
        convListLayout->setWidgetResizable(true);
        convListLayout->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 241, 728));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        convListLayout->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(convListLayout);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout_2->addWidget(frame, 0, 0, 2, 1);

        msgDisplayingArea = new QScrollArea(MainWidget);
        msgDisplayingArea->setObjectName(QString::fromUtf8("msgDisplayingArea"));
        msgDisplayingArea->setWidgetResizable(true);
        msgDisplayLayout = new QWidget();
        msgDisplayLayout->setObjectName(QString::fromUtf8("msgDisplayLayout"));
        msgDisplayLayout->setGeometry(QRect(0, 0, 985, 644));
        verticalLayout_3 = new QVBoxLayout(msgDisplayLayout);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        msgDisplayingArea->setWidget(msgDisplayLayout);

        gridLayout_2->addWidget(msgDisplayingArea, 0, 1, 1, 3);

        sendButton = new QPushButton(MainWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(sendButton, 1, 3, 1, 1);

        textSendingArea = new QPlainTextEdit(MainWidget);
        textSendingArea->setObjectName(QString::fromUtf8("textSendingArea"));
        textSendingArea->setMaximumSize(QSize(16777215, 100));

        gridLayout_2->addWidget(textSendingArea, 1, 1, 1, 2);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "Form", nullptr));
        sendButton->setText(QApplication::translate("MainWidget", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
