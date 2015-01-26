#include "tote.h"
#include "ui_tote.h"
#include "brand.h"

#include <QDebug>


tote::tote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tote)
{
    ui->setupUi(this);

    // Connect the slots
    //connect(ui->actionListBrands, SIGNAL(triggered()), this, SLOT(on_actionListBrands_triggered()));
    //connect(ui->actionNewBrand, SIGNAL(triggered()), this, SLOT(on_actionNewBrand_triggered()));
    //connect(ui->actionListItems, SIGNAL(triggered()), this, SLOT(on_actionListItems_triggered()));
}

tote::~tote()
{
    delete ui;
}

/*
 * List of Brands
 */
void tote::on_actionListBrands_triggered()
{
    Brand *listBrands = new Brand(this);

    listBrands->show();
}


void tote::on_actionListItems_triggered()
{
    qDebug() << "Se clico en list tems";
}

void tote::on_actionNewBuy_triggered()
{
    qDebug() << "Se clico en nueva compra";
}

void tote::on_actionGeography_triggered()
{
    Geography *geographyW = new Geography(this);
    geographyW->show();

}
