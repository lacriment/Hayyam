#include "city.hpp"

int City::getId() const
{
    return m_id;
}

QString City::getName() const
{
    return m_name;
}

void City::setId(int value)
{
    if (m_id == value) return;
    m_id = value;
    idChanged(m_id);
}

void City::setName(const QString &value)
{
    if (m_name == value) return;
    m_name = value;
    nameChanged(m_name);
}

City::City(QObject *parent) : QObject(parent)
{
    
}
