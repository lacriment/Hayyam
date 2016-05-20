#ifndef HELPFORM_HPP
#define HELPFORM_HPP

#include <QDialog>

namespace Ui {
class HelpForm;
}

class HelpForm : public QDialog
{
    Q_OBJECT

public:
    explicit HelpForm(QWidget *parent = 0);
    ~HelpForm();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::HelpForm *ui;
};

#endif // HELPFORM_HPP
