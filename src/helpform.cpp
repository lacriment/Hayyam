#include "helpform.hpp"
#include "ui_helpform.h"

#include "../lib/helpers/stringhelper.hpp"
#include "../lib/helpers/filehelper.hpp"

HelpForm::HelpForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
    ui->txt_help->setReadOnly(true);
    ui->txt_help->setHtml(StringHelper::flattenStringList(FileHelper::fileToString("help.html")));
}

HelpForm::~HelpForm()
{
    delete ui;
}

void HelpForm::on_btn_ok_clicked()
{
    this->close();
}
