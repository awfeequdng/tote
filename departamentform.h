#ifndef DEPARTAMENTFORM_H
#define DEPARTAMENTFORM_H

#include <QDialog>
#include <QLineEdit>
#include <QDateTime>
#include <QDebug>
#include <QPushButton>
#include "departamentmodel.h"

#include "globals.h"

namespace Ui {
class DepartamentForm;
}

class DepartamentForm : public QDialog
{
    Q_OBJECT

public:
    explicit DepartamentForm(QWidget *parent, const short int mode);
    ~DepartamentForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DepartamentForm *ui;

    SDepartament departament;
    DepartamentModel *model;



};

#endif // DEPARTAMENTFORM_H
