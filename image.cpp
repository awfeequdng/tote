#include "image.h"
#include "ui_image.h"

Image::Image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Image)
{
    ui->setupUi(this);
}

Image::~Image()
{
    delete ui;
}
