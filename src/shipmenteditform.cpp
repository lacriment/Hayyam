#include "shipmenteditform.hpp"
#include "ui_shipmenteditform.h"

#include "customerselectionform.hpp"
#include "../lib/algorithm/pricing.hpp"

#include <QDebug>

ShipmentEditForm::ShipmentEditForm(Shipment *shipment, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShipmentEditForm)
{
    ui->setupUi(this);

    m_shipment = shipment;

    if (isNew) {
        ui->txt_width->setText(QString::number(m_shipment->getWidth()));
        ui->txt_height->setText(QString::number(m_shipment->getHeight()));
        ui->txt_weight->setText(QString::number(m_shipment->getWeight()));
        ui->txt_length->setText(QString::number(m_shipment->getLength()));
        ui->btn_sending_customer->setText(m_shipment->getSendingCustomer()->getName());
        ui->btn_receiving_customer->setText(m_shipment->getReceivingCustomer()->getName());
        ui->cb_payment_type->setCurrentIndex(m_shipment->getPaymentType());
        ui->btn_sending_office->setText(m_shipment->getSendingOffice()->getName());
        ui->btn_receiving_office->setText(m_shipment->getReceivingOffice()->getName());
    }
}

ShipmentEditForm::~ShipmentEditForm()
{
    delete ui;
}

bool ShipmentEditForm::getIsNew() const
{
    return isNew;
}

void ShipmentEditForm::setIsNew(bool value)
{
    isNew = value;
}

void ShipmentEditForm::on_btn_cancel_clicked()
{
    this->close();
}

void ShipmentEditForm::on_btn_sending_customer_clicked()
{
    m_customerSelectionForm = new CustomerSelectionForm(this);
    m_customerSelectionForm->show();

    connect(this, SIGNAL(sendData(bool)), m_customerSelectionForm, SLOT(receiveData(bool)));
    emit sendData(true); // sending customer

    connect(m_customerSelectionForm, SIGNAL(sendFormDataSendingCustomer(Customer*)),
            this, SLOT(receiveFormDataSendingCustomer(Customer*)));
}

void ShipmentEditForm::on_btn_receiving_customer_clicked()
{
    m_customerSelectionForm = new CustomerSelectionForm(this);
    m_customerSelectionForm->show();

    connect(this, SIGNAL(sendData(bool)), m_customerSelectionForm, SLOT(receiveData(bool)));
    emit sendData(false); // receiving customer

    connect(m_customerSelectionForm, SIGNAL(sendFormDataReceivingCustomer(Customer*)),
            this, SLOT(receiveFormDataReceivingCustomer(Customer*)));
}

void ShipmentEditForm::receiveFormDataSendingCustomer(Customer *c)
{
    ui->btn_sending_customer->setText(c->getName() + " " + c->getSurname());
    m_shipment->setSendingCustomer(c);
}

void ShipmentEditForm::receiveFormDataReceivingCustomer(Customer *c)
{
    ui->btn_receiving_customer->setText(c->getName() + " " + c->getSurname());
    m_shipment->setReceivingCustomer(c);
}

void ShipmentEditForm::receiveFormDataSendingOffice(Office *o)
{
    ui->btn_sending_office->setText(o->getName());
    m_shipment->setSendingOffice(o);
}

void ShipmentEditForm::receiveFormDataReceivingOffice(Office *o)
{
    ui->btn_receiving_office->setText(o->getName());
    m_shipment->setSendingOffice(o);
}

void ShipmentEditForm::on_btn_sending_office_clicked()
{
    m_officeSelectionForm = new OfficeSelectionForm(this);
    m_officeSelectionForm->show();

    connect(this, SIGNAL(sendData(bool)), m_officeSelectionForm, SLOT(receiveData(bool)));
    emit sendData(true); // sending customer

    connect(m_officeSelectionForm, SIGNAL(sendFormDataSendingOffice(Office*)),
            this, SLOT(receiveFormDataSendingOffice(Office*)));
}

void ShipmentEditForm::on_btn_receiving_office_clicked()
{
    m_officeSelectionForm = new OfficeSelectionForm(this);
    m_officeSelectionForm->show();

    connect(this, SIGNAL(sendData(bool)), m_officeSelectionForm, SLOT(receiveData(bool)));
    emit sendData(false); // sending customer

    connect(m_officeSelectionForm, SIGNAL(sendFormDataReceivingOffice(Office*)),
            this, SLOT(receiveFormDataReceivingOffice(Office*)));
}

void ShipmentEditForm::clearForm()
{
    ui->txt_height->clear();
    ui->txt_weight->clear();
    ui->txt_length->clear();
    ui->txt_width->clear();
    ui->cb_payment_type->setCurrentIndex(0);
    ui->btn_receiving_customer->setText("Seçiniz..");
    ui->btn_sending_customer->setText("Seçiniz..");
    ui->btn_receiving_office->setText("Seçiniz..");
    ui->btn_sending_office->setText("Seçiniz..");
}

void ShipmentEditForm::on_btn_apply_clicked()
{
    m_shipment->setWidth(ui->txt_width->text().toInt());
    m_shipment->setHeight(ui->txt_height->text().toInt());
    m_shipment->setWeight(ui->txt_weight->text().toInt());
    m_shipment->setLength(ui->txt_length->text().toInt());
    m_shipment->setPaymentType(ui->cb_payment_type->currentIndex());
    if (isNew) {
        m_shipment->setStatus("Hazırlanıyor.");
        m_shipment->setAmount(Pricing::calculateAmount(m_shipment));
        Connection::getConnection()->createShipment(m_shipment);
        ui->lbl_status->setText("Kayıt Oluşturuldu!");
        clearForm();
    } else {
        Connection::getConnection()->updateShipment(m_shipment);
        ui->lbl_status->setText("Kayıt Güncellendi!");
    }
}
