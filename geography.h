#ifndef GEOGRAPHY_H
#define GEOGRAPHY_H

#include <QDialog>
#include <QItemDelegate>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QDataWidgetMapper>

#include "countrymodel.h"
#include "geographymodel.h"
#include "citymodel.h"

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

    void on_tvGeography_clicked(const QModelIndex &index);

private:
    Ui::Geography *ui;

    CountryModel *_countryMod;
    GeographyModel *_geographyMod;
    QSortFilterProxyModel *_countryProxy;
    QSortFilterProxyModel *_geographyProxy;
    QDataWidgetMapper *_cityMapper;
    CityModel *_cityModel;

    void createConnections();
};

#endif // GEOGRAPHY_H
