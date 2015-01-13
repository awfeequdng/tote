#ifndef TOTE_H
#define TOTE_H

#include <QMainWindow>


namespace Ui {
class tote;
}

class tote : public QMainWindow
{
    Q_OBJECT

public:
    explicit tote(QWidget *parent = 0);
    ~tote();

private:
    Ui::tote *ui;

private slots:
    void on_actionListBrands_triggered();
    void on_actionListItems_triggered();
    void on_actionNewBuy_triggered();
};

#endif // TOTE_H
