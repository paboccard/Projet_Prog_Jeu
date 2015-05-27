#include "LoadSaveGame.h"
#include "ui_LoadSaveGame.h"

LoadSaveGame::LoadSaveGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LoadSaveGame)
{
	ui->setupUi(this);
}

LoadSaveGame::~LoadSaveGame()
{
	delete ui;
}

void LoadSaveGame::on_buttonAccept_clicked(){
	emit accepted();
}

void LoadSaveGame::on_buttonCancel_clicked(){
	emit rejected();
}

void LoadSaveGame::on_buttonDelete_clicked()
{
	emit deleted();
}

void LoadSaveGame::on_buttonSave_clicked()
{
	emit saved();
}
