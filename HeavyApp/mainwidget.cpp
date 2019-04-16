#include "mainwidget.h"
#include "sendermsg.h"
#include "receivermsg.h"
#include "convtab.h"

#include "ui_mainwidget.h"
#include <QSpacerItem>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);    
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg());
    ui->msgDisplayLayout->layout()->addWidget(new SenderMsg());
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg());
    ui->msgDisplayLayout->layout()->addWidget(new SenderMsg());
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg());
    ui->msgDisplayLayout->layout()->addWidget(new SenderMsg());
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg());
    ui->msgDisplayLayout->layout()->addWidget(new SenderMsg());
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg());
    ui->msgDisplayLayout->layout()->addWidget(new SenderMsg());
    ui->msgDisplayLayout->layout()->addWidget(new ReceiverMsg());
    ui->msgDisplayLayout->layout()->addWidget(new SenderMsg());

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
