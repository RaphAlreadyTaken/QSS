#include "receivermsg.h"
#include "ui_receivermsg.h"

ReceiverMsg::ReceiverMsg(QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiverMsg)
{
    ui->setupUi(this);
    ui->sentText->setAlignment(Qt::AlignLeft);
    ui->nameText->setAlignment(Qt::AlignLeft);
    ui->nameText->setStyleSheet("font-weight: bold");
    ui->frame->setStyleSheet(".QFrame { background-color : lightgrey} ");

    ui->sentText->setText(message);
}

ReceiverMsg::~ReceiverMsg()
{
    delete ui;
}
