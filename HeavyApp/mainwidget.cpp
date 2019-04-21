#include "mainwidget.h"
#include "sendermsg.h"
#include "receivermsg.h"
#include "convtab.h"
#include "ui_mainwidget.h"

#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QSpacerItem>
#include <QUrl>

MainWidget::MainWidget(QUrl url, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    idHlp = "Default";

    connect(&sock, &QWebSocket::connected, this, &MainWidget::connectWS);
    connect(&sock, &QWebSocket::textMessageReceived, this, &MainWidget::onMessageReceived);
    connect(&sock, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &MainWidget::onError);
    connect(&sock, &QWebSocket::disconnected, this, &MainWidget::disconnectWS);

    sock.open(url);
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));
//    ui->convListLayout->widget()->layout()->addWidget(new ConvTab(this, "Test Correspondant"));

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_sendButton_clicked()
{
    QString message = ui->textSendingArea->toPlainText();
    ui->textSendingArea->clear();

    if (message.length() > 0)
    {
        ui->msgDisplayLayout->layout()->addWidget(new SenderMsg(message));

        QJsonObject jsonMsg;
        jsonMsg.insert("message", message);
        jsonMsg.insert("idHlp", idHlp);

        sock.sendTextMessage(QJsonDocument(jsonMsg).toJson());
        qDebug() << "Message sent: " << message;
    }
}

void MainWidget::connectWS()
{
    qDebug() << "Socket connected" << endl;

    QJsonObject jsonMsg;
    jsonMsg.insert("idHlp", idHlp);
    sock.sendTextMessage(QJsonDocument(jsonMsg).toJson());
}


void MainWidget::onMessageReceived(QString message)
{
    QJsonObject jsonMsg = QJsonDocument::fromJson(message.toUtf8()).object();
    QString sender = jsonMsg["id"].toString();
    QString mess = jsonMsg["message"].toString();

    if (!clients.contains(sender))
    {
        clients.push_back(sender);
        ConvTab *un = new ConvTab(this, sender);
        ui->convListLayout->widget()->layout()->addWidget(un);
        un->setIsCurrentTab(true);
        ui->msgDisplayLayout->layout()->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));
    }

    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg(sender.mid(0, sender.indexOf("_")), mess));
    qDebug() << "Message from " << sender << ": " << mess << endl;
}

void MainWidget::onError()
{
    qDebug() << sock.errorString() << endl;
}

void MainWidget::disconnectWS()
{
    qDebug() << "Socket disconnected" << endl;
}

void MainWidget::setIdHlp(QString argName)
{
   idHlp = argName;
}

