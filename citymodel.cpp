#include "citymodel.h"

CityModel::CityModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setTable("bayo.city");
    setEditStrategy(OnManualSubmit);
    setSort(0, Qt::AscendingOrder);

    setHeaderData(fieldIndex("cityid"), Qt::Horizontal, tr("ID"));
    setHeaderData(fieldIndex("cityname"), Qt::Horizontal, tr("Ciudad"));
    setHeaderData(fieldIndex("citycreated"), Qt::Horizontal, tr("Creado"));
    setHeaderData(fieldIndex("cityupdated"), Qt::Horizontal, tr("Modificado"));
}

CityModel::~CityModel()
{

}

