#ifndef DEPARTAMENTMODEL_H
#define DEPARTAMENTMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class DepartamentModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit DepartamentModel(QObject *parent =0);
    ~DepartamentModel();
};

#endif // DEPARTAMENTMODEL_H
