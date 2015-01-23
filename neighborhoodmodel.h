#ifndef NEIGHBORHOODMODEL_H
#define NEIGHBORHOODMODEL_H

#include <QObject>
#include  <QSqlRelationalTableModel>

class NeighborhoodModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit NeighborhoodModel(QObject *parent = 0);
    ~NeighborhoodModel();
};

#endif // NEIGHBORHOODMODEL_H
