#include "app.hpp"
#include "ui_app.h"

#include "../lib/helpers/filehelper.hpp"
#include "../lib/db/connection.hpp"
#include <QDebug>

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
