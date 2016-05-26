#ifndef STATUSUPDATEFORM_HPP
#define STATUSUPDATEFORM_HPP

#include <QWidget>

namespace Ui {
class StatusUpdateForm;
}

class StatusUpdateForm : public QWidget
{
    Q_OBJECT

public:
    explicit StatusUpdateForm(QWidget *parent = 0);
    ~StatusUpdateForm();

private slots:
    void on_btn_find_clicked();

    void on_btn_onayla_clicked();

    void on_btn_exit_clicked();

private:
    Ui::StatusUpdateForm *ui;
};

#endif // STATUSUPDATEFORM_HPP
