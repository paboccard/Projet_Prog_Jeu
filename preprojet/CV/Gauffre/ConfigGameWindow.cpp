#include "ConfigGameWindow.h"
#include "ui_ConfigGameWindow.h"

ConfigGameWindow::ConfigGameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigGameWindow)
{
    ui->setupUi(this);
}

ConfigGameWindow::~ConfigGameWindow()
{
    delete ui;
}
