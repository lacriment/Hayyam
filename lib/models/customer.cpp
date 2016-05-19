#include "customer.hpp"

int Customer::getId() const
{
    return m_Id;
}

QString Customer::getTc() const
{
    return m_Tc;
}

QString Customer::getName() const
{
    return m_Name;
}

QString Customer::getSurname() const
{
    return m_Surname;
}

QString Customer::getPhone() const
{
    return m_Phone;
}

City *Customer::getCity() const
{
    return m_city;
}

QString Customer::getAddress() const
{
    return m_Address;
}

void Customer::setId(int value)
{
    if (m_Id == value) return;
    m_Id = value;
    this->idChanged(m_Id);
}

void Customer::setTc(const QString &value)
{
    if (m_Tc == value) return;
    m_Tc = value;
    tcChanged(m_Tc);
}

void Customer::setName(const QString &value)
{
    if (m_Name == value) return;
    m_Name = value;
    nameChanged(m_Name);
}

void Customer::setSurname(const QString &value)
{
    if (m_Surname == value) return;
    m_Surname = value;
    surnameChanged(m_Surname);
}

void Customer::setPhone(const QString &value)
{
    if (m_Phone == value) return;
    m_Phone = value;
    phoneChanged(m_Phone);
}

void Customer::setAddress(const QString &value)
{
    if (m_Address == value) return;
    m_Address = value;
    addressChanged(m_Address);
}

void Customer::setCity(City *city)
{
    if (m_city == city) return;
    m_city = city;
    cityChanged(m_city);
}

Customer::Customer(QObject *parent) : QObject(parent)
{
    this->m_city = NULL;
}
