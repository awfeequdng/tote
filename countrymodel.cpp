#include "countrymodel.h"

CountryModel::CountryModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setTable("bayo.country");

    setEditStrategy(OnManualSubmit);
    setSort(0, Qt::AscendingOrder);

    setHeaderData(fieldIndex("countryid"), Qt::Horizontal, "ID");
    setHeaderData(fieldIndex("countryname"), Qt::Horizontal, "Pais");
    setHeaderData(fieldIndex("countryiso2"), Qt::Horizontal, "ISO 2");
    setHeaderData(fieldIndex("countryiso3"), Qt::Horizontal, "ISO 3");
    setHeaderData(fieldIndex("countryflag"), Qt::Horizontal, "Bandera");
}

CountryModel::~CountryModel()
{

}

