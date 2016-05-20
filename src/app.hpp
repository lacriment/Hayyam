#ifndef APP_HPP
#define APP_HPP

#include <QMainWindow>

namespace Ui {
class App;
}

class App : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(QWidget *parent = 0);
    ~App();

private slots:
    void on_btn_updateStatus_clicked();

    void on_btn_exit_clicked();

    void on_btn_about_clicked();

    void on_btn_help_clicked();

private:
    Ui::App *ui;
};

#endif // APP_HPP
