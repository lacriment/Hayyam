#ifndef OFFICESELECTIONFORM_HPP
#define OFFICESELECTIONFORM_HPP

#include <QDialog>

#include "../lib/models/office.hpp"

namespace Ui {
class OfficeSelectionForm;
}

class OfficeSelectionForm : public QDialog
{
    Q_OBJECT

public:
    explicit OfficeSelectionForm(QWidget *parent = 0);
    ~OfficeSelectionForm();

signals:
    void sendFormDataSendingOffice(Office*);
    void sendFormDataReceivingOffice(Office*);

private slots:
    void on_btn_cancel_clicked();

    void on_btn_apply_clicked();

    void receiveData(bool b);

    void on_cb_city_currentTextChanged(const QString &arg1);

private:
    Ui::OfficeSelectionForm *ui;
    Office *m_office;
    bool sending;
};

#endif // OFFICESELECTIONFORM_HPP
