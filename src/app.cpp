#include "app.hpp"
#include "ui_app.h"

#include "../lib/helpers/filehelper.hpp"

#include <QDebug>

App::App(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::App)
{
    ui->setupUi(this);
    qDebug() << FileHelper::fileToString("database.sql");
}

App::~App()
{
    delete ui;
}
