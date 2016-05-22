#include "shipmenteditform.hpp"
#include "ui_shipmenteditform.h"

#include "customerselectionform.hpp"

#include <QDebug>

ShipmentEditForm::ShipmentEditForm(Shipment *shipment, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShipmentEditForm)
{
    ui->setupUi(this);

    m_shipment = shipment;


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
    qDebug() << o->getName();
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

void ShipmentEditForm::on_pushButton_3_clicked()
{
    if (isNew) {
        Connection::getConnection()->createShipment(m_shipment);
        //ui->lbl_status->setText("Kayıt Oluşturuldu!");
        //clearForm();
    } else {
        Connection::getConnection()->updateShipment(m_shipment);
        //ui->lbl_status->setText("Kayıt Güncellendi!");
    }
}
