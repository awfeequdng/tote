#include "geography.h"
#include "ui_geography.h"


Geography::Geography(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Geography)
{
    ui->setupUi(this);

    setWindowTitle(tr("Geografia"));


    _countryMod = new CountryModel(this);
    _geographyMod = new GeographyModel(this);

    // remove column unnecessary from country table
    _countryMod->removeColumn(_countryMod->fieldIndex("countryupdated"));
    _countryMod->removeColumn(_countryMod->fieldIndex("countrycreated"));
    _countryMod->removeColumn(_countryMod->fieldIndex("countryflag"));

    // Remove column unnecessary from geography table
    _geographyMod->removeColumn(_geographyMod->fieldIndex(tr("departamentid")));
    _geographyMod->removeColumn(_geographyMod->fieldIndex(tr("cityid")));
    _geographyMod->removeColumn(_geographyMod->fieldIndex(tr("neighborhoodid")));
    _geographyMod->sort(_geographyMod->fieldIndex("cityid"), Qt::AscendingOrder);



    _countryMod->select();
    _geographyMod->select();


    ui->tvCountry->setModel(_countryMod);
    ui->tvCountry->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tvGeography->setModel(_geographyMod);
    ui->tvGeography->setSelectionBehavior(QAbstractItemView::SelectRows);

}


Geography::~Geography()
{
    delete ui;
}
