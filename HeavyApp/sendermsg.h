#ifndef SENDERMSG_H
#define SENDERMSG_H

#include <QWidget>

namespace Ui {
class SenderMsg;
}

class SenderMsg : public QWidget
{
    Q_OBJECT

public:
    explicit SenderMsg(QString message, QWidget *parent = nullptr);
    ~SenderMsg();

private:
    Ui::SenderMsg *ui;
};

#endif // SENDERMSG_H
