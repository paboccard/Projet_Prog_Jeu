#include "NewNetworkGame.h"
#include "ui_NewNetworkGame.h"

NewNetworkGame::NewNetworkGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NewNetworkGame)
{
	ui->setupUi(this);
}

NewNetworkGame::~NewNetworkGame()
{
	delete ui;
}

void NewNetworkGame::on_buttonConnect_clicked()
{
	emit connected();
}

void NewNetworkGame::on_buttonRefresh_clicked()
{
	emit refreshed();
}

void NewNetworkGame::on_buttonCancel_clicked()
{
	emit rejected();
}

void NewNetworkGame::on_buttonCreate_clicked()
{
	emit created();
}

void NewNetworkGame::on_buttonNext_clicked()
{
	emit accepted();
}
