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

private:
    Ui::HelpForm *ui;
};

#endif // HELPFORM_HPP
