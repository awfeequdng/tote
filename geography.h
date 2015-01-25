#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#include <QDialog>

namespace Ui {
class Geography;
}

class Geography : public QDialog
{
    Q_OBJECT

public:
    explicit Geography(QWidget *parent = 0);
    ~Geography();

private:
    Ui::Geography *ui;
};

#endif // GEOGRAPHY_H
