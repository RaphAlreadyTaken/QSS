#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

#include <QLayout>
#include <QUrl>

MainWindow::MainWindow(QUrl url, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->centralWidget->setLayout(new QVBoxLayout);
    QWidget * widg = new MainWidget(url);
    ui->centralWidget->layout()->addWidget(widg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
