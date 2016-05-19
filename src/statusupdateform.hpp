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

private:
    Ui::StatusUpdateForm *ui;
};

#endif // STATUSUPDATEFORM_HPP
