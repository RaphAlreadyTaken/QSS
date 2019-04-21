#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwidget.h"

#include <QLayout>
#include <QUrl>

/**
 * @brief Constructeur
 * @param url : Url du websocket
 * @param parent : Elément parent
 */
MainWindow::MainWindow(QUrl url, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _url = url;

    connect(ui->validateButton, &QPushButton::clicked, this, &MainWindow::onFormValidated);

//    this->ui->centralWidget->setLayout(new QVBoxLayout);
//    QWidget * widg = new MainWidget(url);
//    ui->centralWidget->layout()->addWidget(widg);
}

/**
 * @brief Destructeur
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Gestion de la validation du formulaire de saisie d'ID
 */
void MainWindow::onFormValidated()
{
    MainWidget * widg = new MainWidget(_url);
    if(ui->nameLineEdit->text() != "")
    {
        widg->setIdHlp(ui->nameLineEdit->text());
    }
    else
    {
        widg->setIdHlp(ui->nameLineEdit->placeholderText());
    }

    ui->tempSpacer->changeSize(0,0,QSizePolicy::Ignored);
    ui->tempSpacer2->changeSize(0,0,QSizePolicy::Ignored);
    ui->formFrame->setHidden(true);
    this->ui->centralWidget->setLayout(new QVBoxLayout);
    ui->centralWidget->layout()->addWidget(widg);
}
