#include "receivermsg.h"
#include "ui_receivermsg.h"

/**
 * @brief Constructeur
 * @param sender : ID de l'émetteur du message
 * @param message : Message reçu
 * @param parent : Elément parent
 */
ReceiverMsg::ReceiverMsg(QString sender, QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReceiverMsg)
{
    ui->setupUi(this);
    ui->sentText->setAlignment(Qt::AlignLeft);
    ui->nameText->setAlignment(Qt::AlignLeft);
    ui->nameText->setStyleSheet("font-weight: bold");
    ui->nameText->setText(sender);
    ui->frame->setStyleSheet(".QFrame { background-color : lightgrey} ");

    ui->sentText->setText(message);
}

/**
 * @brief Destructeur
 */
ReceiverMsg::~ReceiverMsg()
{
    delete ui;
}
