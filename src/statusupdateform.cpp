#include "statusupdateform.hpp"
#include "ui_statusupdateform.h"

#include "../lib/db/connection.hpp"
#include "../lib/models/shipment.hpp"
#include "../lib/helpers/stringhelper.hpp"

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
    if (s->getSendingCustomer() != NULL) {
        ui->lbl_sender->setText(StringHelper::concatStrWithWhitespace({s->getSendingCustomer()->getName(), s->getSendingCustomer()->getSurname()}));
        ui->lbl_receiver->setText(StringHelper::concatStrWithWhitespace({s->getReceivingCustomer()->getName(), s->getReceivingCustomer()->getSurname()}));
        ui->lbl_status->setText(s->getStatus());
        ui->lbl_done->setText("Gönderi bulundu!");
    }
    else {
        ui->lbl_done->setText("Gönderi bulunamadı!");
        ui->lbl_sender->setText("");
        ui->lbl_receiver->setText("");
        ui->lbl_status->setText("");
    }
    delete s;
}

void StatusUpdateForm::on_btn_onayla_clicked()
{
    if (ui->txt_trackingCode->text() == "") {
        ui->lbl_done->setText("Takip kodunu giriniz.");
    }
    else {
        Shipment *s = new Shipment();
        int trackingCode = ui->txt_trackingCode->text().toInt();
        s = Connection::getConnection()->getShipment(trackingCode);
        if (s->getSendingCustomer() != NULL) {
            s->setStatus(ui->cb_status->currentText());
            Connection::getConnection()->updateShipment(s);
            ui->lbl_done->setText("Başarılı!");
        }
        delete s;
    }
}


void StatusUpdateForm::on_btn_exit_clicked()
{
    this->close();
}
