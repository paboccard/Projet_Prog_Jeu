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
	connect(mainMenu, SIGNAL(exit()), qApp, SLOT(quit()));

	connect(profilMenu, SIGNAL(accepted(Profile)), this, SLOT(acceptProfil(Profile)));
	connect(profilMenu, SIGNAL(rejected()), this, SLOT(rejectProfil()));

	connect(newLocalGame, SIGNAL(accepted()), this, SLOT(acceptNewGameLocal()));
	connect(newLocalGame, SIGNAL(rejected()), this, SLOT(rejectNewGameLocal()));
	connect(newLocalGame, SIGNAL(newProfil()), this, SLOT(newProfilNewGameLocal()));

	state = 1;
}

MainWindow::~MainWindow()
{
	delete mainMenu;
	delete newLocalGame;
	delete profilMenu;
	delete boardWidget;
	delete optionsWindow;
	delete ui;
}

void MainWindow::loadMenuNewGame()
{
	mainMenu->hide();
	if (currentProfile.name.empty()) {
		profilMenu->show();
		state = 2;
	}
	else {
		newLocalGame->show();
		state = 3;
	}
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

void MainWindow::acceptProfil(Profile p)
{
	profilMenu->hide();
	switch(state) {
		case 2:
		case 4:
			currentProfile = p;
			newLocalGame->show();
			state = 3;
			break;
		case 5:
			currentProfile = p;
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


	int sockfd;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		cout << "ERROR opening socket" << endl;

	threadOutput = new ServerOutputThread(sockfd);

	threadOutput->start();
	//boardWidget->show();
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
