#include "sendermsg.h"
#include "ui_sendermsg.h"

SenderMsg::SenderMsg(QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SenderMsg)
{
    ui->setupUi(this);
    ui->sentText->setAlignment(Qt::AlignRight);
    ui->nameText->setAlignment(Qt::AlignRight);
    ui->nameText->setStyleSheet("font-weight: bold");
    ui->frame->setStyleSheet(".QFrame { background-color : lightblue} ");

    ui->sentText->setText(message);

}

SenderMsg::~SenderMsg()
{
    delete ui;
}
