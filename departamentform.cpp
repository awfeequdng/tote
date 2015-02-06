#include "departamentform.h"
#include "ui_departamentform.h"

DepartamentForm::DepartamentForm(QWidget *parent, const short int mode) :
    QDialog(parent),
    ui(new Ui::DepartamentForm)
{
    ui->setupUi(this);

    model = new DepartamentModel(this);

    switch (mode) {
        case  GLOBALS::INS :
            qDebug() << "Insertar";

            break;
        case  GLOBALS::UPD :
            qDebug() << "modificar";
            break;
    }

}

DepartamentForm::~DepartamentForm()
{
    delete ui;
}

void DepartamentForm::on_pushButton_clicked()
{
    departament.countryId = ui->leCountryId->text().toInt();
    departament.id = ui->leDepartamentId->text().toInt();
    departament.name = ui->leDepartamentNanme->text();
    departament.created = ui->dtDepartamentCreated->dateTime();
    departament.updated = ui->dtDepartamentUpdated->dateTime();

    model->insert(departament);




}
