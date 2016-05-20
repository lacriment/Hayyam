#include "distance.hpp"

int Distance::getId() const
{
    return m_id;
}

Office *Distance::getFirstOffice() const
{
    return m_firstOffice;
}

Office *Distance::getSecondOffice() const
{
    return m_secondOffice;
}

double Distance::getValue() const
{
    return m_value;
}

void Distance::setId(int id)
{
    if (m_id == id) return;
    m_id = id;
    idChanged(m_id);
}

void Distance::setFirstOffice(Office *firstOffice)
{
    if (m_firstOffice == firstOffice) return;
    m_firstOffice = firstOffice;
    firstOfficeChanged(m_firstOffice);
}


void Distance::setSecondOffice(Office *secondOffice)
{
    if (m_secondOffice == secondOffice) return;
    m_secondOffice = secondOffice;
    secondOfficeChanged(m_secondOffice);
}

void Distance::setValue(double value)
{
    if (m_value == value) return;
    m_value = value;
    valueChanged(m_value);
}

Distance::Distance(QObject *parent) : QObject(parent)
{
    this->m_id = 0;
    this->m_firstOffice = new Office;
    this->m_secondOffice = new Office;
    this->m_value = 0;
}
