#ifndef CUSTOMERCREATIONFORM_HPP
#define CUSTOMERCREATIONFORM_HPP

#include <QDialog>

namespace Ui {
class CustomerCreationForm;
}

class CustomerCreationForm : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerCreationForm(QWidget *parent = 0);
    ~CustomerCreationForm();

private slots:

    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::CustomerCreationForm *ui;
};

#endif // CUSTOMERCREATIONFORM_HPP
