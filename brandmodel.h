#ifndef BRANDMODEL_H
#define BRANDMODEL_H
#include "utils.h"

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QMessageBox>

class BrandModel : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit BrandModel(QObject *parent = 0);
    bool excInsert(const QString brandName);
    bool excUpdate(const int row, const QString brandName);
    bool excdelete();
    bool excSelect();


signals:

public slots:
    void filterByName(const QString filterText);


};

#endif // BRANDMODEL_H
