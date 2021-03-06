#ifndef ABOUTFORM_HPP
#define ABOUTFORM_HPP

#include <QDialog>

namespace Ui {
class AboutForm;
}

class AboutForm : public QDialog
{
    Q_OBJECT

public:
    explicit AboutForm(QWidget *parent = 0);
    ~AboutForm();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::AboutForm *ui;
};

#endif // ABOUTFORM_HPP
