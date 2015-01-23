#include "geography.h"
#include "ui_geography.h"

Geography::Geography(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Geography)
{
    ui->setupUi(this);

    _countryMod = new CountryModel(this);
    _countryMod->removeColumn(_countryMod->fieldIndex("countryupdated"));
    _countryMod->removeColumn(_countryMod->fieldIndex("countrycreated"));
    _countryMod->removeColumn(_countryMod->fieldIndex("countryflag"));

    _countryMod->select();


    ui->tvCountry->setModel(_countryMod);
    ui->tvCountry->setSelectionBehavior(QAbstractItemView::SelectRows);

}


Geography::~Geography()
{
    delete ui;
}
