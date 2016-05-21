#include "customereditform.hpp"
#include "ui_customereditform.h"

CustomerEditForm::CustomerEditForm(Customer *customer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerEditForm)
{
    ui->setupUi(this);

    m_customer = customer;

    QStringList cityList;
    CityList cities = Connection::getConnection()->getAllCities();

    // Lambda Expressions Rocks
    std::for_each(cities.begin(), cities.end(), [&cityList] (City *city) { cityList.append(city->getName()); });

    ui->cb_city->addItems(cityList);

    if (m_customer != NULL) {
          connect(ui->txt_name, SIGNAL(textEdited(QString)), m_customer, SLOT(setName(QString)));
          connect(ui->txt_surname, SIGNAL(textEdited(QString)), m_customer, SLOT(setSurname(QString)));
          connect(ui->txt_phone, SIGNAL(textEdited(QString)), m_customer, SLOT(setPhone(QString)));
          connect(ui->txt_tc, SIGNAL(textEdited(QString)), m_customer, SLOT(setTc(QString)));

          connect(ui->txt_address, &QTextEdit::textChanged, m_customer,
                  [=]() { m_customer->setAddress(ui->txt_address->toPlainText());
          });

          // Lambdas Rocks AGAIN !!!
          // Burada Qt5 ve Lambda fonksiyon kullanamasam, model yapısının tamamen değişmesi gerekiyordu.
          connect(ui->cb_city, &QComboBox::currentTextChanged, m_customer,
                  [=]() { m_customer->setCity(
                          Connection::getConnection()->getCities(ui->cb_city->currentText()).first());
          });
    }
}

CustomerEditForm::~CustomerEditForm()
{
    delete ui;
}

bool CustomerEditForm::getIsNew() const
{
    return isNew;
}

void CustomerEditForm::setIsNew(bool value)
{
    isNew = value;
}

void CustomerEditForm::on_btn_save_clicked()
{
    if (isNew) {
        Connection::getConnection()->createCustomer(m_customer);
        ui->lbl_status->setText("Kayıt Oluşturuldu!");
        clearForm();
    } else {
        Connection::getConnection()->updateCustomer(m_customer);
    }
}

void CustomerEditForm::clearForm() {
    ui->txt_tc->clear();
    ui->txt_name->clear();
    ui->txt_surname->clear();
    ui->txt_phone->clear();
    ui->txt_address->clear();
    ui->cb_city->setCurrentIndex(0);
}

void CustomerEditForm::on_btn_cancel_clicked()
{
    this->close();
}
