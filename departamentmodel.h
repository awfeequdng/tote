#ifndef DEPARTAMENTMODEL_H
#define DEPARTAMENTMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include <QDateTime>
#include <QString>
#include <QDebug>
#include <QSqlError>

struct SDepartament{
    int id;
    int countryId;
    QString name;
    QDateTime created;
    QDateTime updated;
};

class DepartamentModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit DepartamentModel(QObject *parent =0);
    ~DepartamentModel();
    bool insert(SDepartament);
};

#endif // DEPARTAMENTMODEL_H
