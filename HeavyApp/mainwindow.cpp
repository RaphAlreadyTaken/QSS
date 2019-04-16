#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->centralWidget->setLayout(new QVBoxLayout);
    ui->centralWidget->layout()->addWidget(new MainWidget());
}

MainWindow::~MainWindow()
{
    delete ui;
}
