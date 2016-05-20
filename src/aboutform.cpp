#include "aboutform.hpp"
#include "ui_aboutform.h"

#include "../lib/helpers/filehelper.hpp"
#include "../lib/helpers/stringhelper.hpp"

AboutForm::AboutForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutForm)
{
    ui->setupUi(this);
    ui->txt_about->setReadOnly(true);
    ui->txt_about->setHtml(StringHelper::flattenStringList(FileHelper::fileToString("../about.html")));
}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_pushButton_clicked()
{
    this->close();
}
