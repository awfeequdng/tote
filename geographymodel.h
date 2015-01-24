#ifndef GEOGRAPHYMODEL_H
#define GEOGRAPHYMODEL_H

#include <QObject>
#include <QSqlRelationalTableModel>

class GeographyModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit GeographyModel(QObject *parent = 0);
    ~GeographyModel();
};

#endif // GEOGRAPHYMODEL_H
