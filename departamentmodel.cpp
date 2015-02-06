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

bool DepartamentModel::insert(SDepartament d)
{
    qDebug() << d.countryId << d.id << d.name << d.created << d.updated;

    int row = rowCount();
    insertRows(row,1);

//    setData(fieldIndex("countryid"),d.countryId);
//    setData(fieldIndex("departamentid"), d.id);
//    setData(fieldIndex("departamentname"), d.name);
//    setData(fieldIndex("departamentcreated"), d.created);
//    setData(fieldIndex("departamentupdated"), d.updated);

    setData(index(row, 1),d.countryId);
    setData(index(row, 2), d.id);
    setData(index(row, 3), d.name);
    setData(index(row, 4), d.created);
    setData(index(row, 5), d.updated);


    database().transaction();

    if (submitAll())
        database().commit();
    else {
        database().rollback();
        qDebug() << "Error" << lastError();
    }
/*
    model->database().transaction();
    if (model->submitAll()){
        model->database().commit()
    } else {
        model->database().rollback();
        qDebug() << "Error" << model->lastError();
    }
*/



    return true;
}
