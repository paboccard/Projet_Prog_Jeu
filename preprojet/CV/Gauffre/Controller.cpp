#include "Controller.h"
#include "ui_GameWindow.h"

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);
}

Controller::~Controller()
{

    delete ui;
}
