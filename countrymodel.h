#ifndef COUNTRYMODEL_H
#define COUNTRYMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
#include <QSqlError>


class CountryModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit CountryModel(QObject *parent = 0);
    ~CountryModel();
    bool excSelect();

};

#endif // COUNTRYMODEL_H
