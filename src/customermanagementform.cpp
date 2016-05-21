#include "customermanagementform.hpp"
#include "ui_customermanagementform.h"

#include "../lib/db/connection.hpp"
#include "../lib/models/customer.hpp"

#include "customercreationform.hpp"

#include <QTableWidgetItem>

CustomerManagementForm::CustomerManagementForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerManagementForm)
{
    ui->setupUi(this);
}

CustomerManagementForm::~CustomerManagementForm()
{
    delete ui;
}

void CustomerManagementForm::on_btn_search_clicked()
{
    QString keyword = ui->txt_keyword->text();
    CustomerList customerList = Connection::getConnection()->getCustomers(keyword);


    ui->tbl_customers->setColumnCount(7);
    ui->tbl_customers->setRowCount(customerList.size());

    ui->tbl_customers->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->tbl_customers->setHorizontalHeaderItem(1, new QTableWidgetItem("TC"));
    ui->tbl_customers->setHorizontalHeaderItem(2, new QTableWidgetItem("İsim"));
    ui->tbl_customers->setHorizontalHeaderItem(3, new QTableWidgetItem("Soyisim"));
    ui->tbl_customers->setHorizontalHeaderItem(4, new QTableWidgetItem("Telefon"));
    ui->tbl_customers->setHorizontalHeaderItem(5, new QTableWidgetItem("Şehir"));
    ui->tbl_customers->setHorizontalHeaderItem(6, new QTableWidgetItem("Adres"));

    int i = 0;
    foreach (Customer *c, customerList) {
        ui->tbl_customers->setItem(i, 0, new QTableWidgetItem(QString::number(c->getId())));
        ui->tbl_customers->setItem(i, 1, new QTableWidgetItem(c->getTc()));
        ui->tbl_customers->setItem(i, 2, new QTableWidgetItem(c->getName()));
        ui->tbl_customers->setItem(i, 3, new QTableWidgetItem(c->getSurname()));
        ui->tbl_customers->setItem(i, 4, new QTableWidgetItem(c->getPhone()));
        ui->tbl_customers->setItem(i, 5, new QTableWidgetItem(c->getCity()->getName()));
        ui->tbl_customers->setItem(i, 6, new QTableWidgetItem(c->getAddress()));
        i++;
    }

}

void CustomerManagementForm::on_btn_exit_clicked()
{
    this->close();
}

void CustomerManagementForm::on_btn_new_clicked()
{
    CustomerCreationForm *form = new CustomerCreationForm();
    form->show();
}
