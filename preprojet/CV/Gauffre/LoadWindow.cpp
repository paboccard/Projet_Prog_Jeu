#include "LoadWindow.h"
#include "ui_LoadWindow.h"

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);
}

LoadWindow::~LoadWindow()
{
    delete ui;
}
