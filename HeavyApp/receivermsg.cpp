#include "receivermsg.h"
#include "ui_receivermsg.h"

ReceiverMsg::ReceiverMsg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiverMsg)
{
    ui->setupUi(this);
    ui->sentText->setAlignment(Qt::AlignLeft);
    ui->nameText->setAlignment(Qt::AlignLeft);
    ui->nameText->setStyleSheet("font-weight: bold");
    ui->frame->setStyleSheet(".QFrame { background-color : lightgrey} ");
}

ReceiverMsg::~ReceiverMsg()
{
    delete ui;
}
