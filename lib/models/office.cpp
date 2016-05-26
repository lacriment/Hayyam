#include "office.hpp"

int Office::getId() const
{
    return m_id;
}

QString Office::getName() const
{
    return m_name;
}

City *Office::getCity() const
{
    return m_city;
}

QString Office::getAddress() const
{
    return m_address;
}

void Office::setId(int id)
{
    if (m_id == id) return;
    m_id = id;
    idChanged(m_id);
}

void Office::setName(const QString &name)
{
    if (m_name == name) return;
    m_name = name;
    nameChanged(m_name);
}

void Office::setCity(City *city)
{
    if (m_city == city) return;
    m_city = city;
    cityChanged(m_city);
}

void Office::setAddress(const QString &address)
{
    if (m_address == address) return;
    m_address = address;
    addressChanged(m_address);
}

Office::Office(QObject *parent) : QObject(parent)
{
    this->m_id = 0;
    this->m_name = "";
    this->m_address = "";
    this->m_city = new City;
}
