#include "officeselectionform.hpp"
#include "ui_officeselectionform.h"

#include "../lib/db/connection.hpp"
#include <QDebug>

OfficeSelectionForm::OfficeSelectionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OfficeSelectionForm)
{
    ui->setupUi(this);

    QStringList cityNames;
    CityList cities = Connection::getConnection()->getAllCities();
    std::for_each(cities.begin(), cities.end(), [&cityNames] (City *city) { cityNames.append(city->getName()); });
    ui->cb_city->addItems(cityNames);

    QStringList officeNames;
    OfficeList offices = Connection::getConnection()->getOfficesByCityId(
                Connection::getConnection()->getCities(ui->cb_city->currentText()).first()->getId());
    std::for_each(offices.begin(), offices.end(), [&officeNames] (Office *office) { officeNames.append(office->getName()); });
    ui->cb_office->clear();
    ui->cb_office->addItems(officeNames);
}

OfficeSelectionForm::~OfficeSelectionForm()
{
    delete ui;
}

void OfficeSelectionForm::on_btn_cancel_clicked()
{
    this->close();
}

void OfficeSelectionForm::on_btn_apply_clicked()
{
    m_office = Connection::getConnection()->getOffices(
                ui->cb_office->currentText()).first();

    if (sending) {
        emit sendFormDataSendingOffice(m_office);
    } else {
        emit sendFormDataReceivingOffice(m_office);
    }
    this->close();
}

void OfficeSelectionForm::receiveData(bool b)
{
    this->sending = b;
}

void OfficeSelectionForm::on_cb_city_currentTextChanged(const QString &arg1)
{
    ui->cb_office->clear();
    QStringList officeNames;
    OfficeList offices = Connection::getConnection()->getOfficesByCityId(
                Connection::getConnection()->getCities(arg1).first()->getId());
    std::for_each(offices.begin(), offices.end(), [&officeNames] (Office *office) { officeNames.append(office->getName()); });
    ui->cb_office->addItems(officeNames);
}
