#include "geography.h"
#include "ui_geography.h"

Geography::Geography(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Geography)
{
    ui->setupUi(this);
}

Geography::~Geography()
{
    delete ui;
}
