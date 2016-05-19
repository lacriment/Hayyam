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
    ui->lbl_lblSender->setText(s->getSendingCustomer()->getName());
    ui->lbl_lblReceiver->setText(s->getReceivingCustomer()->getName());
    ui->lbl_status->setText(s->getStatus());
}
