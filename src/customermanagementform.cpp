#include "customermanagementform.hpp"
#include "ui_customermanagementform.h"

#include "../lib/db/connection.hpp"
#include "../lib/models/customer.hpp"

#include "customereditform.hpp"

#include <QTableWidgetItem>
#include <QMessageBox>

CustomerManagementForm::CustomerManagementForm(Customer *customer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerManagementForm)
{
    ui->setupUi(this);

    m_customer = customer;
}

CustomerManagementForm::~CustomerManagementForm()
{
    delete ui;
}

void CustomerManagementForm::on_btn_search_clicked()
{
    QString keyword = ui->txt_keyword->text();
    CustomerList customerList = Connection::getConnection()->getCustomers(keyword);

    if (customerList.first()->getId() != 0) {
        ui->tbl_customers->setColumnCount(7);
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
    CustomerEditForm *form = new CustomerEditForm(m_customer);
    form->setIsNew(true);
    form->show();
}

void CustomerManagementForm::on_btn_edit_clicked()
{
    QModelIndex currentIndex = ui->tbl_customers->currentIndex();
    int id = ui->tbl_customers->item(currentIndex.row(), 0)->text().toInt();
    m_customer = Connection::getConnection()->getCustomer(id);
    CustomerEditForm *form = new CustomerEditForm(m_customer);
    form->setIsNew(false);
    form->show();
}

void CustomerManagementForm::on_btn_delete_clicked()
{
    QModelIndex currentIndex = ui->tbl_customers->currentIndex();
    int id = ui->tbl_customers->item(currentIndex.row(), 0)->text().toInt();
    m_customer = Connection::getConnection()->getCustomer(id);

    QMessageBox msgBox(QMessageBox::Question,
                tr("Silmek istediğinizden emin misiniz?"),
                tr("Silmek istediğinizden emin misiniz?"),
                QMessageBox::Yes | QMessageBox::No,
                this);
    msgBox.setButtonText(QMessageBox::Yes, tr("Evet"));
    msgBox.setButtonText(QMessageBox::No, tr("Hayır"));
    if (msgBox.exec() == QMessageBox::Yes) {
        Connection::getConnection()->deleteCustomer(m_customer);
        ui->lbl_status->setText("Müşteri silindi!");
        on_btn_search_clicked();
    }
}

void CustomerManagementForm::on_tbl_customers_cellDoubleClicked(int row)
{
    int id = ui->tbl_customers->item(row, 0)->text().toInt();
    m_customer = Connection::getConnection()->getCustomer(id);
    CustomerEditForm *form = new CustomerEditForm(m_customer);
    form->setIsNew(false);
    form->show();
}
