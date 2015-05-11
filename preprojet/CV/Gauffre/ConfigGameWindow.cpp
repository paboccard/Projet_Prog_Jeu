#include "ConfigGameWindow.h"
#include "ui_ConfigGameWindow.h"

ConfigGameWindow::ConfigGameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigGameWindow)
{
    ui->setupUi(this);
}

ConfigGameWindow::~ConfigGameWindow()
{
    delete ui;
}
