#ifndef CUSTOMERSELECTIONFORM_HPP
#define CUSTOMERSELECTIONFORM_HPP

#include <QDialog>

#include "../lib/models/customer.hpp"
#include "customereditform.hpp"

namespace Ui {
class CustomerSelectionForm;
}

class CustomerSelectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerSelectionForm(QWidget *parent = 0);
    ~CustomerSelectionForm();

signals:
    void sendFormDataSendingCustomer(Customer*);
    void sendFormDataReceivingCustomer(Customer*);

private slots:
    void on_btn_cancel_clicked();

    void on_btn_new_clicked();

    void on_btn_search_clicked();

    void on_btn_apply_clicked();

    void receiveData(bool b);

private:
    Ui::CustomerSelectionForm *ui;
    Customer *m_customer;
    bool sending;

    CustomerEditForm *m_newCustomerForm;
};

#endif // CUSTOMERSELECTIONFORM_HPP
