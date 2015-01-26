#include "geography.h"
#include "ui_geography.h"


Geography::Geography(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Geography)
{
    ui->setupUi(this);

    setWindowTitle(tr("Geografia"));

//  Create objects
    _countryMod = new CountryModel(this);
    _geographyMod = new GeographyModel(this);
    _countryProxy = new QSortFilterProxyModel(this) ;
    _geographyProxy = new QSortFilterProxyModel(this);

//  Remove column unnecessary from country table
    _countryMod->removeColumn(_countryMod->fieldIndex("countryupdated"));
    _countryMod->removeColumn(_countryMod->fieldIndex("countrycreated"));
    _countryMod->removeColumn(_countryMod->fieldIndex("countryflag"));

//    Configure models and proxy
    _countryMod->select();
    _geographyMod->select();
    _countryProxy->setSourceModel(_countryMod);
    _geographyProxy->setSourceModel(_geographyMod);
    _geographyMod->sort(_geographyMod->fieldIndex("cityid"), Qt::AscendingOrder);

    ui->tvCountry->setModel(_countryProxy);
    ui->tvGeography->setModel(_geographyProxy);


//  Configure tableview
    ui->tvCountry->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvCountry->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvCountry->setEditTriggers(QAbstractItemView::NoEditTriggers);
  //  ui->tvCountry->setSortingEnabled(true);

    ui->tvCountry->resizeColumnsToContents();
    ui->tvCountry->horizontalHeader()->setStretchLastSection(true);

    ui->tvGeography->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tvGeography->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tvGeography->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tvGeography->setColumnHidden(_geographyMod->fieldIndex("departamentid"), true);
//    ui->tvGeography->setSortingEnabled(true);
    ui->tvGeography->resizeColumnsToContents();
    ui->tvGeography->horizontalHeader()->setStretchLastSection(true);

}

void Geography::on_leCountryNameF_textEdited(const QString &arg1)
{

    _countryProxy->setFilterKeyColumn(_countryMod->fieldIndex("countryname"));
    _countryProxy->setSortCaseSensitivity(Qt::CaseInsensitive);
    _countryProxy->setFilterFixedString(arg1);
}

void Geography::on_leCountryIdF_textEdited(const QString &arg1)
{
    _countryProxy->setFilterKeyColumn(_countryMod->fieldIndex("countryid"));
    _countryProxy->setFilterRegExp(arg1);
}



Geography::~Geography()
{
    delete ui;
}
