/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QScrollArea *convListArea;
    QWidget *convListLayout;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *textSendingArea;
    QPushButton *sendButton;
    QScrollArea *msgDisplayingArea;
    QWidget *msgDisplayLayout;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1276, 770);
        gridLayout_2 = new QGridLayout(MainWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        convListArea = new QScrollArea(MainWidget);
        convListArea->setObjectName(QString::fromUtf8("convListArea"));
        convListArea->setMaximumSize(QSize(250, 16777215));
        convListArea->setWidgetResizable(true);
        convListLayout = new QWidget();
        convListLayout->setObjectName(QString::fromUtf8("convListLayout"));
        convListLayout->setGeometry(QRect(0, 0, 248, 750));
        verticalLayout_5 = new QVBoxLayout(convListLayout);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        convListArea->setWidget(convListLayout);

        gridLayout_2->addWidget(convListArea, 0, 0, 2, 1);

        textSendingArea = new QPlainTextEdit(MainWidget);
        textSendingArea->setObjectName(QString::fromUtf8("textSendingArea"));
        textSendingArea->setMaximumSize(QSize(16777215, 100));

        gridLayout_2->addWidget(textSendingArea, 1, 1, 1, 1);

        sendButton = new QPushButton(MainWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        gridLayout_2->addWidget(sendButton, 1, 2, 1, 1);

        msgDisplayingArea = new QScrollArea(MainWidget);
        msgDisplayingArea->setObjectName(QString::fromUtf8("msgDisplayingArea"));
        msgDisplayingArea->setWidgetResizable(true);
        msgDisplayLayout = new QWidget();
        msgDisplayLayout->setObjectName(QString::fromUtf8("msgDisplayLayout"));
        msgDisplayLayout->setGeometry(QRect(0, 0, 1000, 644));
        verticalLayout_3 = new QVBoxLayout(msgDisplayLayout);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        msgDisplayingArea->setWidget(msgDisplayLayout);

        gridLayout_2->addWidget(msgDisplayingArea, 0, 1, 1, 2);


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
