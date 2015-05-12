#include "ConfigGameWindow.h"
#include "ui_ConfigGameWindow.h"
#include <iostream>

using namespace std;

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

int ConfigGameWindow::getWidth()
{
    return ui->widthSpinBox->value();
}

int ConfigGameWindow::getHeight()
{
    return ui->heightSpinBox->value();
}

mode ConfigGameWindow::getMode()
{
    if (ui->pvpRadioButton->isChecked())
        return PvP;
    else if (ui->pvcRadioButton->isChecked())
        return PvC;
    else
        return CvC;
}

difficulty ConfigGameWindow::getDiff1()
{
    if (ui->pvcRadioButton->isChecked())
        return (difficulty)ui->difficultypvcComboBox->currentIndex();
    else
        return (difficulty)ui->difficultycvcComboBox1->currentIndex();
}

difficulty ConfigGameWindow::getDiff2()
{
    return (difficulty)ui->difficultycvcComboBox2->currentIndex();
}
