#include "app.hpp"
#include "ui_app.h"

#include "../lib/helpers/filehelper.hpp"
#include "../lib/helpers/stringhelper.hpp"
#include "../lib/db/connection.hpp"

#include <QDebug>

#include "statusupdateform.hpp"
#include "aboutform.hpp"
#include "helpform.hpp"
#include "customermanagementform.hpp"
#include "shipmentmanagementform.hpp"

App::App(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);
    Connection::getConnection();
}

App::~App()
{
    delete ui;
}

void App::on_btn_updateStatus_clicked()
{
    StatusUpdateForm *form = new StatusUpdateForm();
    form->show();
}

void App::on_btn_exit_clicked()
{
    this->close();
}

void App::on_btn_about_clicked()
{
    AboutForm *form = new AboutForm();
    form->show();
}

void App::on_btn_help_clicked()
{
    HelpForm *form = new HelpForm();
    form->show();
}

void App::on_btn_customerInfo_clicked()
{
    CustomerManagementForm *form = new CustomerManagementForm(new Customer);
    form->show();
}

void App::on_btn_newShipment_clicked()
{
    ShipmentManagementForm *form = new ShipmentManagementForm();
    form->show();
}
