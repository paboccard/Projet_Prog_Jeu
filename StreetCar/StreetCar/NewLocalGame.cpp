#include "NewLocalGame.h"
#include "ui_NewLocalGame.h"

NewLocalGame::NewLocalGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NewLocalGame)
{
	ui->setupUi(this);
}

NewLocalGame::~NewLocalGame()
{
	delete ui;
}

void NewLocalGame::on_buttonCancel_clicked()
{
	emit rejected();
}

void NewLocalGame::on_buttonPlay_clicked()
{
	emit accepted();
}

void NewLocalGame::on_buttonNewProfil_clicked()
{
	emit newProfil();
}
