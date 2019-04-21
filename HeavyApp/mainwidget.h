#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QWebSocket>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QUrl url, QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void connectWS();
    void disconnectWS();
    void on_sendButton_clicked();
    void onMessageReceived(QString message);
    void onError();

private:
    Ui::MainWidget *ui;
    QWebSocket sock;
    QString idHlp;
    QVector<QString> clients;
};

#endif // MAINWIDGET_H
