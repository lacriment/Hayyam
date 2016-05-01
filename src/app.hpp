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

private:
    Ui::App *ui;
};

#endif // APP_HPP
