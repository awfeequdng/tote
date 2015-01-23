#include "neighborhoodmodel.h"

NeighborhoodModel::NeighborhoodModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setTable("bayo.neighborhood");
    setEditStrategy(OnManualSubmit);
    setSort(0, Qt::AscendingOrder);

    setHeaderData(fieldIndex("neighborhoodid"), Qt::Horizontal, tr("ID"));
    setHeaderData(fieldIndex("neighborhoodname"), Qt::Horizontal, tr("Barrio"));
    setHeaderData(fieldIndex("neighborhoodcreated"), Qt::Horizontal, tr("Creado"));
    setHeaderData(fieldIndex("neighborhoodupdated"), Qt::Horizontal, tr("Modificado"));
}

NeighborhoodModel::~NeighborhoodModel()
{

}

