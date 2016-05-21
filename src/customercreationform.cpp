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

    QStringList cityList;
    CityList cities = Connection::getConnection()->getAllCities();

    // Lambda Expressions Rocks !!!
    std::for_each(cities.begin(), cities.end(), [&cityList] (City *city) { cityList.append(city->getName()); });

    ui->cb_city->addItems(cityList);
}

CustomerCreationForm::~CustomerCreationForm()
{
    delete ui;
}


void CustomerCreationForm::on_btn_save_clicked()
{
    Customer *c = new Customer();
    c->setTc(ui->txt_tc->text());
    c->setName(ui->txt_name->text());
    c->setSurname(ui->txt_surname->text());
    c->setPhone(ui->txt_phone->text());
    c->setCity(Connection::getConnection()->getCities(ui->cb_city->currentText()).first());
    c->setAddress(ui->txt_address->toPlainText());
    Connection::getConnection()->createCustomer(c);

    ui->lbl_status->setText("Kayıt Oluşturuldu!");
    ui->txt_tc->clear();
    ui->txt_name->clear();
    ui->txt_surname->clear();
    ui->txt_phone->clear();
    ui->txt_address->clear();
}

void CustomerCreationForm::on_btn_cancel_clicked()
{
    this->close();
}
