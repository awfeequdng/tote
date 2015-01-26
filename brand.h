#ifndef BRAND_H
#define BRAND_H

#include "brandmodel.h"
#include "utils.h"
#include "dbconn.h"

#include <QDialog>
#include <QDataWidgetMapper>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QRegExpValidator>

namespace Ui {
class Brand;
}

class Brand : public QDialog
{
    Q_OBJECT

public:
    explicit Brand(QWidget *parent = 0);
    ~Brand();

signals:
        bool isValidField();


private slots:
    void on_btnNew_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();
    void on_btnConfirm_clicked();

    void verificar();
    void ver();


private:
    Ui::Brand *ui;
    BrandModel *_brandModel;
    QDataWidgetMapper *_mapper;
    int _mode;

    void createConnections();
    void insertBrand();
    bool isValidForm();



};

#endif // BRAND_H
