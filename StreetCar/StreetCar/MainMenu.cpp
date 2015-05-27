#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_buttonNewGame_clicked()
{
    emit newGame();
}

void MainMenu::on_buttonNewGameNetwork_clicked()
{
	emit newGameNetwork();
}

void MainMenu::on_buttonLoadSave_clicked()
{
	emit loadSaveGame();
}

void MainMenu::on_buttonProfil_clicked()
{
    emit profil();
}

void MainMenu::on_buttonOptions_clicked()
{
	emit options();
}

void MainMenu::on_buttonQuit_clicked()
{
	emit exitGame();
}




