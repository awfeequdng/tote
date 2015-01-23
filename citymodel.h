#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>
#include <QDebug>

class CityModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit CityModel(QObject *parent = 0);
    ~CityModel();

signals:

public slots:
};

#endif // CITYMODEL_H
