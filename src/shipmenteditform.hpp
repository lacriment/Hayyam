#ifndef SHIPMENTEDITFORM_HPP
#define SHIPMENTEDITFORM_HPP

#include <QDialog>

#include "../lib/models/shipment.hpp"
#include "customerselectionform.hpp"
#include "officeselectionform.hpp"

namespace Ui {
class ShipmentEditForm;
}

class ShipmentEditForm : public QDialog
{
    Q_OBJECT

public:
    explicit ShipmentEditForm(Shipment *shipment, QWidget *parent = 0);
    ~ShipmentEditForm();

    bool getIsNew() const;
    void setIsNew(bool value);

signals:
    void sendData(bool);

private slots:
    void on_btn_cancel_clicked();

    void on_btn_sending_customer_clicked();

    void on_btn_receiving_customer_clicked();

    void receiveFormDataSendingCustomer(Customer *c);
    void receiveFormDataReceivingCustomer(Customer *c);

    void receiveFormDataSendingOffice(Office *o);
    void receiveFormDataReceivingOffice(Office *o);


    void on_btn_sending_office_clicked();

    void on_btn_receiving_office_clicked();

    void on_btn_apply_clicked();

private:
    Ui::ShipmentEditForm *ui;

    bool isNew;
    Shipment *m_shipment;
    CustomerSelectionForm *m_customerSelectionForm;
    OfficeSelectionForm *m_officeSelectionForm;

    void clearForm();

};

#endif // SHIPMENTEDITFORM_HPP
