#ifndef SHIPMENTMANAGEMENTFORM_HPP
#define SHIPMENTMANAGEMENTFORM_HPP

#include <QDialog>

namespace Ui {
class ShipmentManagementForm;
}

class ShipmentManagementForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShipmentManagementForm(QWidget *parent = 0);
    ~ShipmentManagementForm();

private slots:
    void on_btn_search_clicked();

    void on_btn_exit_clicked();

    void on_btn_delete_clicked();

    void on_btn_new_clicked();

    void on_btn_edit_clicked();

    void on_tbl_shipments_cellDoubleClicked(int row);

private:
    Ui::ShipmentManagementForm *ui;
};

#endif // SHIPMENTMANAGEMENTFORM_HPP
