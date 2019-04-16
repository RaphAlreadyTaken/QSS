#include "convtab.h"
#include "ui_convtab.h"

ConvTab::ConvTab(QWidget *parent, QString name, bool newMsg) :
    QWidget(parent),
    ui(new Ui::ConvTab)
{
    ui->setupUi(this);
    ui->correspondantName->setText(name);
    ui->newMsgLabel->setVisible(newMsg);
}

void ConvTab::setIsCurrentTab(bool current)
{
    if(current)
    {
        ui->frame->setStyleSheet(".QFrame { background-color : lightgrey} ");
    }
    else
    {
        ui->frame->setStyleSheet("");
    }
}

ConvTab::~ConvTab()
{
    delete ui;
}
