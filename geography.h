#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#include <QDialog>
#include <QItemDelegate>
#include <QDebug>
// teste
#include <QSortFilterProxyModel>

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

private slots:
    void on_leCountryNameF_textEdited(const QString &arg1);

    void on_leCountryIdF_textEdited(const QString &arg1);

private:
    Ui::Geography *ui;

    CountryModel *_countryMod;
    GeographyModel *_geographyMod;
    QSortFilterProxyModel *_countryProxy;
    QSortFilterProxyModel *_geographyProxy;
};

#endif // GEOGRAPHY_H
