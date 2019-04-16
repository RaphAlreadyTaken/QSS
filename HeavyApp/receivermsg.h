#ifndef RECEIVERMSG_H
#define RECEIVERMSG_H

#include <QWidget>

namespace Ui {
class ReceiverMsg;
}

class ReceiverMsg : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiverMsg(QWidget *parent = nullptr);
    ~ReceiverMsg();

private:
    Ui::ReceiverMsg *ui;
};

#endif // RECEIVERMSG_H
