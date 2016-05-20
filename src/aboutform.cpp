#include "aboutform.hpp"
#include "ui_aboutform.h"

#include "../lib/helpers/filehelper.hpp"

AboutForm::AboutForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);
}

AboutForm::~AboutForm()
{
    delete ui;
}
