#include "CreateNetworkGame.h"
#include "ui_CreateNetworkGame.h"

CreateNetworkGame::CreateNetworkGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CreateNetworkGame)
{
	ui->setupUi(this);
}

CreateNetworkGame::~CreateNetworkGame()
{
	delete ui;
}

void CreateNetworkGame::on_buttonCreate_clicked()
{
	emit accepted();
}

void CreateNetworkGame::on_buttonCancel_clicked()
{
	emit rejected();
}
