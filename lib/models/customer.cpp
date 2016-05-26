#include "customer.hpp"
#include "../db/connection.hpp"

int Customer::getId() const
{
    return m_Id;
}

QString Customer::getTc() const
{
    return m_tc;
}

QString Customer::getName() const
{
    return m_name;
}

QString Customer::getSurname() const
{
    return m_surname;
}

QString Customer::getPhone() const
{
    return m_phone;
}

City *Customer::getCity() const
{
    return m_city;
}

QString Customer::getAddress() const
{
    return m_address;
}

void Customer::setId(int value)
{
    if (m_Id == value) return;
    m_Id = value;
    this->idChanged(m_Id);
}

void Customer::setTc(const QString &value)
{
    if (m_tc == value) return;
    m_tc = value;
    tcChanged(m_tc);
}

void Customer::setName(const QString &value)
{
    if (m_name == value) return;
    m_name = value;
    nameChanged(m_name);
}

void Customer::setSurname(const QString &value)
{
    if (m_surname == value) return;
    m_surname = value;
    surnameChanged(m_surname);
}

void Customer::setPhone(const QString &value)
{
    if (m_phone == value) return;
    m_phone = value;
    phoneChanged(m_phone);
}

void Customer::setAddress(const QString &value)
{
    if (m_address == value) return;
    m_address = value;
    addressChanged(m_address);
}

void Customer::setCity(City *city)
{
    if (m_city == city) return;
    m_city = city;
    cityChanged(m_city);
}

Customer::Customer(QObject *parent) : QObject(parent)
{
    this->m_Id = 0;
    this->m_tc = "";
    this->m_name = "";
    this->m_surname = "";
    this->m_phone = "";
    this->m_address = "";
    this->m_city = new City;
}
