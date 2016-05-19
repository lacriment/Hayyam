#include "app.hpp"
#include "ui_app.h"

#include "../lib/helpers/filehelper.hpp"
#include "../lib/db/connection.hpp"

#include <QDebug>

#include "statusupdateform.hpp"

App::App(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);
    Connection::getConnection();
    qDebug() << Connection::getConnection()->getShipment(1)->getAmount();
    qDebug() << Connection::getConnection()->getShipment(2)->getAmount();
    qDebug() << Connection::getConnection()->getShipment(3)->getAmount();
    qDebug() << Connection::getConnection()->getShipment(5)->getAmount();
    qDebug() << Connection::getConnection()->getShipment(4)->getAmount();
    qDebug() << Connection::getConnection()->getShipment(3)->getAmount();
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
