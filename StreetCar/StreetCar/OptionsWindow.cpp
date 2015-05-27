#include "OptionsWindow.h"
#include "ui_OptionsWindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::OptionsWindow)
{
	ui->setupUi(this);
}

OptionsWindow::~OptionsWindow()
{
	delete ui;
}
