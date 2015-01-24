#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#include <QDialog>
#include <QItemDelegate>

#include "countrymodel.h"
#include "geographymodel.h"

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

    CountryModel *_countryMod;
    GeographyModel *_geographyMod;
};

#endif // GEOGRAPHY_H
