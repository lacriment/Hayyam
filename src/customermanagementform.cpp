#include "customermanagementform.hpp"
#include "ui_customermanagementform.h"

#include "../lib/db/connection.hpp"

CustomerManagementForm::CustomerManagementForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerManagementForm)
{
    ui->setupUi(this);
}

CustomerManagementForm::~CustomerManagementForm()
{
    delete ui;
}

void CustomerManagementForm::on_btn_search_clicked()
{
    QString keyword = ui->txt_keyword->text();
}

void CustomerManagementForm::on_btn_exit_clicked()
{
    this->close();
}
