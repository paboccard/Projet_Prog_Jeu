#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	mainMenu = new MainMenu();
	newLocalGame = new NewLocalGame();
	newLocalGame->hide();
	profilMenu = new ProfilMenu();
	profilMenu->hide();
	boardWidget = new BoardWidget();
	boardWidget->hide();
	optionsWindow = new OptionsWindow();
	optionsWindow->hide();

	ui->layoutMenu->addWidget(mainMenu);
	ui->layoutMenu->addWidget(newLocalGame);
	ui->layoutMenu->addWidget(profilMenu);
	ui->layoutMenu->addWidget(boardWidget);
	ui->layoutMenu->addWidget(optionsWindow);

	connect(mainMenu, SIGNAL(newGame()), this, SLOT(loadMenuNewGame()));
	connect(mainMenu, SIGNAL(profil()), this, SLOT(loadMenuProfil()));
	connect(mainMenu, SIGNAL(options()), this, SLOT(loadMenuOptions()));

	connect(profilMenu, SIGNAL(accepted()), this, SLOT(acceptProfil()));
	connect(profilMenu, SIGNAL(rejected()), this, SLOT(rejectProfil()));

	connect(newLocalGame, SIGNAL(accepted()), this, SLOT(acceptNewGameLocal()));
	connect(newLocalGame, SIGNAL(rejected()), this, SLOT(rejectNewGameLocal()));
	connect(newLocalGame, SIGNAL(newProfil()), this, SLOT(newProfilNewGameLocal()));


	state = 1;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::loadMenuNewGame()
{
	mainMenu->hide();
	profilMenu->show();
	state = 2;
}

void MainWindow::loadMenuProfil()
{
	mainMenu->hide();
	profilMenu->show();
	state = 5;
}

void MainWindow::loadMenuOptions()
{
	mainMenu->hide();
	optionsWindow->show();
	state = 6;
}

void MainWindow::acceptProfil()
{
	profilMenu->hide();
	switch(state) {
		case 2:
		case 4:
			newLocalGame->show();
			state = 3;
			break;
		case 5:
			mainMenu->show();
			state = 1;
			break;
	}
}

void MainWindow::rejectProfil()
{
	profilMenu->hide();
	switch(state) {
		case 2:
		case 5:
			mainMenu->show();
			state = 1;
			break;
		case 4:
			newLocalGame->show();
			state = 3;
			break;
	}
}

void MainWindow::acceptNewGameLocal()
{
	newLocalGame->hide();
	boardWidget->show();
	state = 4;
}

void MainWindow::rejectNewGameLocal()
{
	newLocalGame->hide();
	mainMenu->show();
	state = 1;
}

void MainWindow::newProfilNewGameLocal()
{
	newLocalGame->hide();
	profilMenu->show();
	state = 4;
}
