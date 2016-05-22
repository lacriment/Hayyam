#ifndef CUSTOMERMANAGEMENTFORM_HPP
#define CUSTOMERMANAGEMENTFORM_HPP

#include <QDialog>
#include "../lib/models/customer.hpp"

namespace Ui {
class CustomerManagementForm;
}

class CustomerManagementForm : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerManagementForm(Customer *customer, QWidget *parent = 0);
    ~CustomerManagementForm();

private slots:
    void on_btn_search_clicked();

    void on_btn_exit_clicked();

    void on_btn_new_clicked();

    void on_btn_edit_clicked();

    void on_btn_delete_clicked();

    void on_tbl_customers_cellDoubleClicked(int row);

private:
    Ui::CustomerManagementForm *ui;
    Customer *m_customer;
};

#endif // CUSTOMERMANAGEMENTFORM_HPP
