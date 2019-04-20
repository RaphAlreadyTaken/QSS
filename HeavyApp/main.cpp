#include "mainwindow.h"
#include <QApplication>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QUrl url("ws://localhost:3101/chat");
    MainWindow w(url);
    w.setWindowTitle("ChatUp");
    w.show();

    return a.exec();
}
