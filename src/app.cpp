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
    //qDebug() << Connection::getShipment(1)->getId();
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
