#include "GraphicsOption.h"
#include "ui_GraphicsOption.h"

GraphicsOption::GraphicsOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphicsOption)
{
	ui->setupUi(this);
}

GraphicsOption::~GraphicsOption()
{
	delete ui;
}

void GraphicsOption::on_buttonAccept_clicked(){
	emit accepted();
}

void GraphicsOption::on_buttonCancel_clicked(){
	emit rejected();
}
