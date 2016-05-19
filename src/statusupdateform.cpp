#include "statusupdateform.hpp"
#include "ui_statusupdateform.h"

#include "../lib/db/connection.hpp"
#include "../lib/models/shipment.hpp"

StatusUpdateForm::StatusUpdateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusUpdateForm)
{
    ui->setupUi(this);
}

StatusUpdateForm::~StatusUpdateForm()
{
    delete ui;
}

void StatusUpdateForm::on_btn_find_clicked()
{
    Shipment *s = new Shipment();
    int trackingCode = ui->txt_trackingCode->text().toInt();
    s = Connection::getConnection()->getShipment(trackingCode);
    if (s->getAmount()) {
        ui->lbl_sender->setText(s->getSendingCustomer()->getName());
        ui->lbl_receiver->setText(s->getReceivingCustomer()->getName());
        ui->lbl_status->setText(s->getStatus());
        ui->lbl_done->setText("Gönderi bulundu!");
    }
    else {
        ui->lbl_done->setText("Gönderi bulunamadı!");
        ui->lbl_sender->setText("");
        ui->lbl_receiver->setText("");
        return;
    }
    delete s;
}

void StatusUpdateForm::on_pushButton_clicked()
{
    Shipment *s = new Shipment();
    int trackingCode = ui->txt_trackingCode->text().toInt();
    s = Connection::getConnection()->getShipment(trackingCode);
    s->setStatus(ui->cb_status->currentText());
    Connection::getConnection()->updateShipment(s);
    ui->lbl_done->setText("Başarılı!");
    delete s;
}
