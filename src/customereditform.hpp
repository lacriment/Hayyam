#ifndef CUSTOMEREDITFORM_HPP
#define CUSTOMEREDITFORM_HPP

#include <QDialog>

#include "../lib/models/customer.hpp"
#include "../lib/models/city.hpp"
#include "../lib/db/connection.hpp"

namespace Ui {
class CustomerEditForm;
}

class CustomerEditForm : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerEditForm(Customer *customer = NULL, QWidget *parent = 0);
    ~CustomerEditForm();

    bool getIsNew() const;
    void setIsNew(bool value);

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::CustomerEditForm *ui;

    Customer *m_customer;
    bool isNew;
    void clearForm();

};

#endif // CUSTOMEREDITFORM_HPP
