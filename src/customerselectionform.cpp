#include "customerselectionform.hpp"
#include "ui_customerselectionform.h"

#include "customereditform.hpp"

CustomerSelectionForm::CustomerSelectionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerSelectionForm)
{
    ui->setupUi(this);

}

CustomerSelectionForm::~CustomerSelectionForm()
{
    delete ui;
}

void CustomerSelectionForm::on_btn_cancel_clicked()
{
    this->close();
}

void CustomerSelectionForm::on_btn_new_clicked()
{
    m_newCustomerForm = new CustomerEditForm(new Customer);
    m_newCustomerForm->setIsNew(true);
    m_newCustomerForm->show();
}

void CustomerSelectionForm::on_btn_search_clicked()
{
    QString keyword = ui->txt_keyword->text();
    CustomerList customerList = Connection::getConnection()->getCustomers(keyword);

    if (customerList.first()->getId() != 0) {
        ui->tbl_customers->setColumnCount(5);
        ui->tbl_customers->setRowCount(customerList.size());
    }
    else {
        ui->tbl_customers->setColumnCount(1);
        ui->tbl_customers->setRowCount(1);
        ui->tbl_customers->setHorizontalHeaderItem(0, new QTableWidgetItem(""));
        ui->tbl_customers->setVerticalHeaderItem(0, new QTableWidgetItem(""));
        ui->tbl_customers->setColumnWidth(0, 1000);
        ui->tbl_customers->setItem(0, 0, new QTableWidgetItem("Müşteri bulunamadı."));
        return;
    }

    ui->tbl_customers->setColumnWidth(0, 30);
    ui->tbl_customers->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->tbl_customers->setHorizontalHeaderItem(1, new QTableWidgetItem("TC"));
    ui->tbl_customers->setHorizontalHeaderItem(2, new QTableWidgetItem("İsim"));
    ui->tbl_customers->setHorizontalHeaderItem(3, new QTableWidgetItem("Soyisim"));
    ui->tbl_customers->setHorizontalHeaderItem(4, new QTableWidgetItem("Telefon"));
    int i = 0;
    foreach (Customer *c, customerList) {
        ui->tbl_customers->setItem(i, 0, new QTableWidgetItem(QString::number(c->getId())));
        ui->tbl_customers->setItem(i, 1, new QTableWidgetItem(c->getTc()));
        ui->tbl_customers->setItem(i, 2, new QTableWidgetItem(c->getName()));
        ui->tbl_customers->setItem(i, 3, new QTableWidgetItem(c->getSurname()));
        ui->tbl_customers->setItem(i, 4, new QTableWidgetItem(c->getPhone()));
        i++;
    }
}

void CustomerSelectionForm::on_btn_apply_clicked()
{
    QModelIndex currentIndex = ui->tbl_customers->currentIndex();
    int id = ui->tbl_customers->item(currentIndex.row(), 0)->text().toInt();
    m_customer = Connection::getConnection()->getCustomer(id);

    if (sending) {
        emit sendFormDataSendingCustomer(m_customer);
    } else {
        emit sendFormDataReceivingCustomer(m_customer);
    }

    this->close();
}

void CustomerSelectionForm::receiveData(bool b)
{
    this->sending = b;
}
