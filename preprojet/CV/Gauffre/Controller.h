#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include <ConfigGameWindow.h>

namespace Ui {
class Controller;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);
    ~Controller();

private slots:
    void configure();

private:
    Ui::Controller *ui;
    ConfigGameWindow *configWindow;

};

#endif // CONTROLLER_H
