#include "customercreationform.hpp"
#include "ui_customercreationform.h"

#include "../lib/models/customer.hpp"
#include "../lib/models/city.hpp"

#include "../lib/db/connection.hpp"

CustomerCreationForm::CustomerCreationForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerCreationForm)
{
    ui->setupUi(this);
}

CustomerCreationForm::~CustomerCreationForm()
{
    delete ui;
}


void CustomerCreationForm::on_btn_save_clicked()
{
    Customer *c = new Customer();
}

void CustomerCreationForm::on_btn_cancel_clicked()
{
    this->close();
}
