#include "shipmentmanagementform.hpp"
#include "ui_shipmentmanagementform.h"

#include "../lib/db/connection.hpp"
#include "../lib/models/shipment.hpp"
#include "../lib/helpers/stringhelper.hpp"

#include "shipmenteditform.hpp"
#include "customermanagementform.hpp"
#include "customerselectionform.hpp"

#include <QTableWidgetItem>
#include <QMessageBox>

ShipmentManagementForm::ShipmentManagementForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShipmentManagementForm)
{
    ui->setupUi(this);
}

ShipmentManagementForm::~ShipmentManagementForm()
{
    delete ui;
}

void ShipmentManagementForm::on_btn_search_clicked()
{
    QString keyword = ui->txt_keyword->text();
    ShipmentList shipmentList = Connection::getConnection()->getShipments(keyword);

    if (shipmentList.first()->getId() != 0) {
        ui->tbl_shipments->setColumnCount(3);
        ui->tbl_shipments->setRowCount(shipmentList.size());
    }
    else {
        ui->tbl_shipments->setColumnCount(1);
        ui->tbl_shipments->setRowCount(1);
        ui->tbl_shipments->setHorizontalHeaderItem(0, new QTableWidgetItem(""));
        ui->tbl_shipments->setVerticalHeaderItem(0, new QTableWidgetItem(""));
        ui->tbl_shipments->setColumnWidth(0, 1000);
        ui->tbl_shipments->setItem(0, 0, new QTableWidgetItem("Kargo bulunamadı."));
        return;
    }

    ui->tbl_shipments->setColumnWidth(0, 100);
    ui->tbl_shipments->setColumnWidth(1, 180);
    ui->tbl_shipments->setColumnWidth(2, 180);
    ui->tbl_shipments->setHorizontalHeaderItem(0, new QTableWidgetItem("Kargo Kodu"));
    ui->tbl_shipments->setHorizontalHeaderItem(1, new QTableWidgetItem("Gönderici"));
    ui->tbl_shipments->setHorizontalHeaderItem(2, new QTableWidgetItem("Alıcı"));

    int i = 0;
    foreach (Shipment *s, shipmentList) {
        ui->tbl_shipments->setItem(i, 0, new QTableWidgetItem(QString::number(s->getId())));
        ui->tbl_shipments->setItem(i, 1, new QTableWidgetItem(
                                       StringHelper::concatStrWithSep({s->getSendingCustomer()->getName(), s->getSendingCustomer()->getSurname()}," "))
                                   );
        ui->tbl_shipments->setItem(i, 2, new QTableWidgetItem(
                                       StringHelper::concatStrWithSep({s->getReceivingCustomer()->getName(), s->getReceivingCustomer()->getSurname()}," "))
                                   );
        i++;
    }
}

void ShipmentManagementForm::on_btn_exit_clicked()
{
    this->close();
}

void ShipmentManagementForm::on_btn_delete_clicked()
{
    QModelIndex currentIndex = ui->tbl_shipments->currentIndex();
    int id = ui->tbl_shipments->item(currentIndex.row(), 0)->text().toInt();
    Shipment *shipment = Connection::getConnection()->getShipment(id);

    QMessageBox msgBox(QMessageBox::Question,
                tr("Silmek istediğinizden emin misiniz?"),
                tr("Silmek istediğinizden emin misiniz?"),
                QMessageBox::Yes | QMessageBox::No,
                this);
    msgBox.setButtonText(QMessageBox::Yes, tr("Evet"));
    msgBox.setButtonText(QMessageBox::No, tr("Hayır"));
    if (msgBox.exec() == QMessageBox::Yes) {
        Connection::getConnection()->deleteShipment(shipment);
        ui->lbl_status->setText("Kargo silindi!");
        on_btn_search_clicked();
    }
}

void ShipmentManagementForm::on_btn_new_clicked()
{
    Shipment *s = new Shipment();
    ShipmentEditForm *form = new ShipmentEditForm(s);
    form->setIsNew(true);
    form->show();
}
