#include "helpform.hpp"
#include "ui_helpform.h"

HelpForm::HelpForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
}

HelpForm::~HelpForm()
{
    delete ui;
}
