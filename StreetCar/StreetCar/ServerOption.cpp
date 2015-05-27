#include "ServerOption.h"
#include "ui_ServerOption.h"

ServerOption::ServerOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ServerOption)
{
	ui->setupUi(this);
}

ServerOption::~ServerOption()
{
	delete ui;
}

void ServerOption::on_buttonAccept_clicked(){
	emit accepted();
}

void ServerOption::on_buttonCancel_clicked(){
	emit rejected();
}
