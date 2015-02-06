#include "geography.h"
#include "ui_geography.h"


Geography::Geography(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Geography)
{
    ui->setupUi(this);

    setWindowTitle(tr("Geografia"));

    qDebug() << GLOBALS::INS;

//  Create objects
    _countryMod = new CountryModel(this);
    _geographyMod = new GeographyModel(this);
    _countryProxy = new QSortFilterProxyModel(this) ;
    _geographyProxy = new QSortFilterProxyModel(this);
    _cityMapper = new QDataWidgetMapper(this);
    _cityModel = new CityModel(this);

//  Configure the mapper
    _cityMapper->setModel(_geographyProxy);
    _cityMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    _cityMapper->addMapping(ui->leDepartamentId, _geographyMod->fieldIndex("departamentid") );
    _cityMapper->addMapping(ui->leDepartamentName, _geographyMod->fieldIndex("departamentname") );
    _cityMapper->addMapping(ui->dtDepartamentCreated, _geographyMod->fieldIndex("departamentcreated") );
    _cityMapper->addMapping(ui->dtDepartamentUpdated, _geographyMod->fieldIndex("departamentupdated") );
    _cityMapper->addMapping(ui->leCityId, _geographyMod->fieldIndex("cityid"));
    _cityMapper->addMapping(ui->leCityName, _geographyMod->fieldIndex("cityname"));
    _cityMapper->addMapping(ui->dtCityCreated, _geographyMod->fieldIndex("citycreated"));
    _cityMapper->addMapping(ui->dtCityUpdated, _geographyMod->fieldIndex("cityupdated"));
    _cityMapper->addMapping(ui->leNeighborhoodId, _geographyMod->fieldIndex("neighborhoodid"));
    _cityMapper->addMapping(ui->leNeighborhoodName, _geographyMod->fieldIndex("neighborhoodname"));
    _cityMapper->addMapping(ui->dtNeighborhoodCreated, _geographyMod->fieldIndex("neighborhoodupdate"));
    _cityMapper->addMapping(ui->dtNeighborhoodUpdated, _geographyMod->fieldIndex("neighborhoodupdated"));
    _cityMapper->toFirst();



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
    ui->tvGeography->setColumnHidden(_geographyMod->fieldIndex("cityid"), true);
    ui->tvGeography->setColumnHidden(_geographyMod->fieldIndex("neighborhoodid"), true);
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

void Geography::on_tvGeography_clicked(const QModelIndex &index)
{
        _cityMapper->setCurrentModelIndex(index);
}

void Geography::on_btnAddDepartament_clicked()
{
    _Form = new DepartamentForm(this, 0);

    _Form->show();
}
