#include "shipment.hpp"


int Shipment::getId() const
{
    return m_id;
}

int Shipment::getLength() const
{
    return m_length;
}

int Shipment::getWidth() const
{
    return m_width;
}

int Shipment::getHeight() const
{
    return m_height;
}

int Shipment::getWeight() const
{
    return m_weight;
}

Customer *Shipment::getSendingCustomer() const
{
    return m_sendingCustomer;
}
Customer *Shipment::getReceivingCustomer() const
{
    return m_receivingCustomer;
}

int Shipment::getPaymentType() const
{
    return m_paymentType;
}

double Shipment::getAmount() const
{
    return m_amount;
}

int Shipment::getStatus() const
{
    return m_status;
}

Office *Shipment::getSendingOffice() const
{
    return m_sendingOffice;
}

Office *Shipment::getReceivingOffice() const
{
    return m_receivingOffice;
}

void Shipment::setId(int id)
{
    if (m_id == id) return;
    m_id = id;
    idChanged(m_id);
}

void Shipment::setLength(int length)
{
    if (m_length == length) return;
    m_length = length;
    lengthChanged(m_length);
}

void Shipment::setWidth(int width)
{
    if (m_width == width) return;
    m_width = width;
    widthChanged(m_width);
}

void Shipment::setHeight(int height)
{
    if (m_height == height) return;
    m_height = height;
    heightChanged(m_height);
}

void Shipment::setWeight(int weight)
{
    if (m_weight == weight) return;
    m_weight = weight;
}

void Shipment::setSendingCustomer(Customer *sendingCustomer)
{
    if (m_sendingCustomer == sendingCustomer) return;
    m_sendingCustomer = sendingCustomer;
    sendingCustomerChanged(m_sendingCustomer);
}


void Shipment::setReceivingCustomer(Customer *receivingCustomer)
{
    if (m_receivingCustomer == receivingCustomer) return;
    m_receivingCustomer = receivingCustomer;
    receivingCustomerChanged(m_receivingCustomer);
}

void Shipment::setPaymentType(int paymentType)
{
    if (m_paymentType == paymentType) return;
    m_paymentType = paymentType;
    paymentTypeChanged(m_paymentType);
}

void Shipment::setAmount(double amount)
{
    if (m_amount == amount) return;
    m_amount = amount;
    amountChanged(m_amount);
}

void Shipment::setStatus(int status)
{
    if (m_status == status) return;
    m_status = status;
    statusChanged(status);
}

void Shipment::setSendingOffice(Office *sendingOffice)
{
    if (m_sendingOffice == sendingOffice) return;
    m_sendingOffice = sendingOffice;
    sendingOfficeChanged(m_sendingOffice);
}

void Shipment::setReceivingOffice(Office *receivingOffice)
{
    if (m_receivingOffice == receivingOffice) return;
    m_receivingOffice = receivingOffice;
    receivingOfficeChanged(m_receivingOffice);
}

Shipment::Shipment(QObject *parent) : QObject(parent)
{
    
}
