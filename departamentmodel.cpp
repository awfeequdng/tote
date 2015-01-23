#include "departamentmodel.h"

DepartamentModel::DepartamentModel(QObject *parent) :
    QSqlRelationalTableModel(parent)
{
    setTable("bayo.departament");
    setEditStrategy(OnManualSubmit);
    setSort(0, Qt::AscendingOrder);

    setHeaderData(fieldIndex("departamentid"), Qt::Horizontal, tr("ID"));
    setHeaderData(fieldIndex("departamentname"), Qt::Horizontal, tr("Departamento"));
    setHeaderData(fieldIndex("departamentid"), Qt::Horizontal, tr("Creado"));
    setHeaderData(fieldIndex("departamentid"), Qt::Horizontal, tr("Modificado"));


}

DepartamentModel::~DepartamentModel()
{

}

