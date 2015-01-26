#include "brand.h"
#include "ui_brand.h"

Brand::Brand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Brand)
{
    ui->setupUi(this);



    _brandModel = new BrandModel(this);
    _mapper = new QDataWidgetMapper(this);
    _mode = DBConn::combinedMode;

    _brandModel->select();

    _mapper->setModel(_brandModel);
    _mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    _mapper->addMapping(ui->leBrandId, _brandModel->fieldIndex("brandid"));
    _mapper->addMapping(ui->leBrandName, _brandModel->fieldIndex("brandname"));
    _mapper->addMapping(ui->dtBrandCreated, _brandModel->fieldIndex("brandcreated"));
    _mapper->addMapping(ui->dtBrandUpdated, _brandModel->fieldIndex("brandupdated"));
    _mapper->setCurrentModelIndex(_brandModel->index(0,1));


    ui->tvBrands->setModel(_brandModel);
    ui->tvBrands->verticalHeader()->setHidden(true);
    ui->tvBrands->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->leBrandId->setReadOnly(true);
    ui->leBrandName->setReadOnly(true);
    ui->dtBrandCreated->setReadOnly(true);
    ui->dtBrandUpdated->setReadOnly(true);
    ui->btnConfirm->setVisible(false);

    createConnections();

    ui->leBrandName->setValidator(new QRegExpValidator(Utils::emptyLine));

}

Brand::~Brand()
{
    delete ui;
}

void Brand::createConnections()
{
    connect(ui->tvBrands, SIGNAL(clicked(QModelIndex)), _mapper, SLOT(setCurrentModelIndex(QModelIndex)));
   // connect(ui->btnNew, SIGNAL(clicked()), this, SLOT(on_btnNew_clicked()));
//    connect(ui->leFiBrandName, SIGNAL(textChanged(QString)), _brandModel, SLOT(filterByName(QString)));
    connect(ui->leBrandName, SIGNAL(editingFinished()), this, SLOT(verificar()));
    connect(this, SIGNAL(isValidField()), this, SLOT(ver));
}

void Brand::insertBrand()
{
//    ui->leBrandId->setReadOnly(false);
    ui->leBrandId->setText("0");
    ui->leBrandName->setReadOnly(false);
    ui->leBrandName->setText("");
    ui->dtBrandCreated->setDateTime(Utils::now());
    ui->dtBrandUpdated->setDateTime(Utils::now());
}

/*
 * ************************************************
 * VALIDATE THE FORM
 */
bool Brand::isValidForm()
{
    if (!ui->leBrandName->hasAcceptableInput()) {
        QMessageBox::critical(0, "El campo 'Marca' no es valido", "sdafsd");

        return false;
    }
    return true;
}

/*
 * ###### SLOTS
 */
void Brand::on_btnNew_clicked()
{
    _mode = DBConn::insertMode;
    ui->btnConfirm->setVisible(true);
    ui->btnConfirm->setText(tr("Agregar"));
    ui->widgetActions->setVisible(false);
    insertBrand();

}

void Brand::on_btnEdit_clicked()
{
    _mode = DBConn::updateMode;
    ui->btnConfirm->setVisible(true);
    ui->btnConfirm->setText(tr("Modificar"));
    ui->widgetActions->setVisible(false);
    ui->leBrandName->setReadOnly(false);
    ui->dtBrandUpdated->setDateTime(Utils::now());

}

void Brand::on_btnDelete_clicked()
{
    _mode = DBConn::deleteMode;
    ui->btnConfirm->setVisible(true);
    ui->btnConfirm->setText(tr("Eliminar"));
    ui->widgetActions->setVisible(false);

}

void Brand::on_btnConfirm_clicked()
{
    int row;
    switch(_mode) {
    case 0:
         row = _brandModel->rowCount();
//        _brandModel->insertRows(row,1);
//        _brandModel->setData(_brandModel->index(row, 1), ui->leBrandName->text());
//        _brandModel->setData(_brandModel->index(row, 2), ui->dtBrandCreated->text());
//        _brandModel->setData(_brandModel->index(row, 3), ui->dtBrandUpdated->text());

//        _brandModel->submitAll();
//        if(_brandModel->lastError().type() != QSqlError::NoError)
//            QMessageBox::warning(this, tr("Error"), _brandModel->lastError().text());
//        _mapper->setCurrentModelIndex(_brandModel->index(row, 1));
//        ui->widgetActions->setVisible(true);
         //qDebug() << _brandModel->excInsert(ui->leBrandName->text());
         if (isValidForm()) {
             qDebug() << "ok";
         } else {
             qDebug() << "no";
         }


        break;
    case 2:

        row = ui->tvBrands->currentIndex().row();
        _brandModel->excUpdate(row, ui->leBrandName->text());

//        _brandModel->setData(_brandModel->index(row, _brandModel->fieldIndex("brandname")), ui->leBrandName->text());
//        _brandModel->setData(_brandModel->index(row, _brandModel->fieldIndex("brandupdated")), ui->dtBrandUpdated->text());


//        _brandModel->submitAll();
//        if(_brandModel->lastError().type() != QSqlError::NoError)
//            QMessageBox::warning(this, tr("Error"), _brandModel->lastError().text());
//        _mapper->setCurrentModelIndex(_brandModel->index(row, 1));
//        ui->widgetActions->setVisible(true);


        break;
    case 3:

        break;
    }

}

//bool Brand::isValidField()
//{

//    return true;
//}

void Brand::verificar()
{
    emit isValidField();
}

void Brand::ver()
{
    qDebug() << "llego a ver";
}
