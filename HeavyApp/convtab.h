#ifndef CONVTAB_H
#define CONVTAB_H

#include <QWidget>

namespace Ui {
class ConvTab;
}

class ConvTab : public QWidget
{
    Q_OBJECT

public:
    explicit ConvTab(QWidget *parent = nullptr, QString name = "Nom correspondant", bool newMsg = false);
    void setIsCurrentTab(bool current);
    ~ConvTab();

private:
    Ui::ConvTab *ui;
};

#endif // CONVTAB_H
