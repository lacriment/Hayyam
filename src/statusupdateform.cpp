#include "statusupdateform.hpp"
#include "ui_statusupdateform.h"

StatusUpdateForm::StatusUpdateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusUpdateForm)
{
    ui->setupUi(this);
}

StatusUpdateForm::~StatusUpdateForm()
{
    delete ui;
}
