#ifndef CUSTOMERMANAGEMENTFORM_HPP
#define CUSTOMERMANAGEMENTFORM_HPP

#include <QDialog>

namespace Ui {
class CustomerManagementForm;
}

class CustomerManagementForm : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerManagementForm(QWidget *parent = 0);
    ~CustomerManagementForm();

private slots:
    void on_btn_search_clicked();

    void on_btn_exit_clicked();

    void on_btn_new_clicked();

    void on_btn_edit_clicked();

    void on_btn_delete_clicked();

private:
    Ui::CustomerManagementForm *ui;
};

#endif // CUSTOMERMANAGEMENTFORM_HPP
