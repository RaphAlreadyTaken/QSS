#include "mainwidget.h"
#include "sendermsg.h"
#include "receivermsg.h"
#include "convtab.h"

#include "ui_mainwidget.h"
#include <QSpacerItem>
#include <QDebug>
#include <QUrl>

MainWidget::MainWidget(QUrl url, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    connect(&sock, &QWebSocket::connected, this, &MainWidget::connectWS);
    connect(&sock, &QWebSocket::textMessageReceived, this, &MainWidget::onMessageReceived);
    connect(&sock, QOverload<QAbstractSocket::SocketError>::of(&QWebSocket::error), this, &MainWidget::onError);
//    connect(&sock, &QWebSocket::disconnected, this, &MainWidget::disconnectWS);

    sock.open(url);
    qDebug() << sock.isValid() << endl;

    ui->setupUi(this);

    ui->msgDisplayLayout->layout()->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    ConvTab *un = new ConvTab(this, "Correspondant 1");
    ui->convListLayout->layout()->addWidget(un);
    un->setIsCurrentTab(true);

    ui->convListLayout->layout()->addWidget(new ConvTab(this, "Correspondant 2", true));
    ui->convListLayout->layout()->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_sendButton_clicked()
{
    QString message = ui->textSendingArea->toPlainText();

    if (message.length() > 0)
    {
        ui->msgDisplayLayout->layout()->addWidget(new SenderMsg(message));
        sock.sendTextMessage(message);
        qDebug() << "Message sent: " << message;
    }
}

void MainWidget::connectWS()
{
    qDebug() << "Socket connected" << endl;
    QString msg;
}

void MainWidget::disconnectWS()
{
    qDebug() << "Socket disconnected" << endl;
}

void MainWidget::onMessageReceived(QString message)
{
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg(message));
    qDebug() << "Message received: " << message << endl;
}

void MainWidget::onError()
{
    qDebug() << sock.errorString() << endl;
}
