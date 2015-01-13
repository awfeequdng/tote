#include "brandmodel.h"

BrandModel::BrandModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setTable("brand");
    setEditStrategy(OnManualSubmit);
    setSort(0, Qt::AscendingOrder);
    removeColumn(fieldIndex("brandimage"));

    setHeaderData(fieldIndex("brandid"), Qt::Horizontal, "ID");
    setHeaderData(fieldIndex("brandname"), Qt::Horizontal, "Marca");
    setHeaderData(fieldIndex("brandcreated"), Qt::Horizontal, "Creado");
    setHeaderData(fieldIndex("brandupdated"), Qt::Horizontal, "Modificado");

}

bool BrandModel::excInsert(const QString brandName)
{
    int row = rowCount();
    insertRows(row, 1);
    setData(index(row, fieldIndex("brandname")), brandName);
    setData(index(row, fieldIndex("brandcreated")), Utils::now());
    setData(index(row, fieldIndex("brandupdated")), Utils::now());

    submitAll();

    if(lastError().type() != QSqlError::NoError)  {
        QMessageBox::warning(0, tr("Error"), lastError().text());

        return false;
    }


    return true;
}

bool BrandModel::excUpdate(const int row, const QString brandName)
{
    setData(index(row, fieldIndex("brandname")), brandName);
    setData(index(row, fieldIndex("brandupdated")), Utils::now());

    submitAll();
    if(lastError().type() != QSqlError::NoError) {
        QMessageBox::warning(0, tr("Error"), lastError().text());

        return false;
    }

    return true;
}

void BrandModel::filterByName(const QString filterText)
{
    if (filterText != "")
        setFilter(QString("brandname LIKE '%" + filterText + "%'"));
    else
        setFilter(QString(""));
    filter();
}
