#include "geographymodel.h"

GeographyModel::GeographyModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setTable("bayo.v_geography");
    setEditStrategy(OnManualSubmit);
    setSort(0, Qt::AscendingOrder);

    setHeaderData(fieldIndex("countryid"), Qt::Horizontal, tr("PaisID"));
    setHeaderData(fieldIndex("countryname"), Qt::Horizontal, tr("Pais"));
    setHeaderData(fieldIndex("departamentid"), Qt::Horizontal, tr("Depart.ID"));
    setHeaderData(fieldIndex("departamentname"), Qt::Horizontal, tr("Departamento"));
    setHeaderData(fieldIndex("cityname"), Qt::Horizontal, tr("Ciudad"));
    setHeaderData(fieldIndex("neighborhoodname"), Qt::Horizontal, tr("Barrio"));
}

GeographyModel::~GeographyModel()
{

}

