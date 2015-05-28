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
	newNetworkGame = new NewNetworkGame();
	newNetworkGame->hide();
	descriptionPlayersNetwork = new DescriptionPlayersNetwork();
	descriptionPlayersNetwork->hide();
	createNetworkGame = new CreateNetworkGame();
	createNetworkGame->hide();
	boardWidget = new BoardWidget();
	boardWidget->hide();
	loadSaveGame = new LoadSaveGame();
	loadSaveGame->hide();
	profilMenu = new ProfilMenu();
	profilMenu->hide();
	optionsMenu = new OptionsMenu();
	optionsMenu->hide();
	soundOption = new SoundOption();
	soundOption->hide();
	serverOption = new ServerOption();
	serverOption->hide();
	rulesOption = new RulesOption();
	rulesOption->hide();
	graphicsOption = new GraphicsOption();
	graphicsOption->hide();
	creditsOption = new CreditsOption();
	creditsOption->hide();


	ui->layoutMenu->addWidget(mainMenu);
	ui->layoutMenu->addWidget(newLocalGame);
	ui->layoutMenu->addWidget(newNetworkGame);
	ui->layoutMenu->addWidget(descriptionPlayersNetwork);
	ui->layoutMenu->addWidget(createNetworkGame);
	ui->layoutMenu->addWidget(boardWidget);
	ui->layoutMenu->addWidget(loadSaveGame);
	ui->layoutMenu->addWidget(profilMenu);
	ui->layoutMenu->addWidget(optionsMenu);
	ui->layoutMenu->addWidget(soundOption);
	ui->layoutMenu->addWidget(serverOption);
	ui->layoutMenu->addWidget(rulesOption);
	ui->layoutMenu->addWidget(graphicsOption);
	ui->layoutMenu->addWidget(creditsOption);


	connect(mainMenu, SIGNAL(newGame()), this, SLOT(loadMenuNewGame()));
	connect(mainMenu, SIGNAL(newGameNetwork()), this, SLOT(loadMenuNewGameNetwork()));
	connect(mainMenu, SIGNAL(loadSaveGame()), this, SLOT(loadMenuloadSaveGame()));
	connect(mainMenu, SIGNAL(profil()), this, SLOT(loadMenuProfil()));
	connect(mainMenu, SIGNAL(options()), this, SLOT(loadMenuOptions()));
	connect(mainMenu, SIGNAL(exitGame()), qApp, SLOT(quit()));

	connect(newLocalGame, SIGNAL(accepted()), this, SLOT(acceptNewGameLocal()));
	connect(newLocalGame, SIGNAL(rejected()), this, SLOT(rejectNewGameLocal()));
	connect(newLocalGame, SIGNAL(newProfil()), this, SLOT(newProfilNewGameLocal()));

	connect(newNetworkGame, SIGNAL(connected()), this, SLOT(connectGameServer()));
	connect(newNetworkGame, SIGNAL(refreshed()), this, SLOT(refreshGameServer()));
	connect(newNetworkGame, SIGNAL(rejected()), this, SLOT(rejectNewGameNetwork()));
	connect(newNetworkGame, SIGNAL(created()), this, SLOT(createNewGameNetwork()));
	connect(newNetworkGame, SIGNAL(accepted()), this, SLOT(acceptNewGameNetwork()));

	connect(descriptionPlayersNetwork, SIGNAL(accepted()), this, SLOT(playGameNetwork()));
	connect(descriptionPlayersNetwork, SIGNAL(rejected()), this, SLOT(exitGameNetwork()));

	connect(createNetworkGame, SIGNAL(accepted()), this, SLOT(createGameNetwork()));
	connect(createNetworkGame, SIGNAL(rejected()), this, SLOT(rejectGameNetwork()));

	connect(boardWidget, SIGNAL(startedTravel()), this, SLOT(startTravel()));
	connect(boardWidget, SIGNAL(saved()), this, SLOT(saveGame()));
	connect(boardWidget, SIGNAL(helped()), this, SLOT(helpGame()));
	connect(boardWidget, SIGNAL(exitGame()), this, SLOT(quitGame()));

	connect(loadSaveGame, SIGNAL(accepted()), this, SLOT(acceptLoadGame()));
	connect(loadSaveGame, SIGNAL(rejected()), this, SLOT(rejectedLoadSaveGame()));
	connect(loadSaveGame, SIGNAL(deleted()), this, SLOT(deleteSaveGame()));
	connect(loadSaveGame, SIGNAL(saved()), this, SLOT(saveGame()));

	connect(profilMenu, SIGNAL(accepted(Profile)), this, SLOT(acceptProfil(Profile)));
	connect(profilMenu, SIGNAL(rejected()), this, SLOT(rejectProfil()));

	connect(optionsMenu, SIGNAL(soundOption()), this, SLOT(loadSoundOption()));
	connect(optionsMenu, SIGNAL(serverOption()), this, SLOT(loadServerOption()));
	connect(optionsMenu, SIGNAL(graphicsOption()), this, SLOT(loadGraphicsOption()));
	connect(optionsMenu, SIGNAL(rulesOption()), this, SLOT(loadRulesOption()));
	connect(optionsMenu, SIGNAL(creditsOption()), this, SLOT(loadCreditsOption()));
	connect(optionsMenu, SIGNAL(backMenu()), this, SLOT(backMainMenu()));

	connect(soundOption, SIGNAL(accepted()), this, SLOT(acceptSoundOption()));
	connect(soundOption, SIGNAL(rejected()), this, SLOT(rejectSoundOption()));

	connect(graphicsOption, SIGNAL(accepted()), this, SLOT(acceptGraphicsOption()));
	connect(graphicsOption, SIGNAL(rejected()), this, SLOT(rejectGraphicsOption()));

	connect(serverOption, SIGNAL(accepted()), this, SLOT(acceptServerOption()));
	connect(serverOption, SIGNAL(rejected()), this, SLOT(rejectServerOption()));

	connect(rulesOption, SIGNAL(backOptions()), this, SLOT(backMenuOption()));

	connect(creditsOption, SIGNAL(backOptions()), this, SLOT(backMenuOption()));


	state = 1;
}

MainWindow::~MainWindow()
{
	delete mainMenu;
	delete newLocalGame;
	delete newNetworkGame;
	delete descriptionPlayersNetwork;
	delete createNetworkGame;
	delete boardWidget;
	delete loadSaveGame;
	delete profilMenu;
	delete optionsMenu;
	delete soundOption;
	delete graphicsOption;
	delete serverOption;
	delete rulesOption;
	delete creditsOption;
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

void MainWindow::loadMenuNewGameNetwork()
{
	mainMenu->hide();
	newNetworkGame->show();
	state = 14;
}

void MainWindow::loadMenuloadSaveGame()
{
	mainMenu->hide();
	loadSaveGame->show();
	state = 12;
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
	optionsMenu->show();
	state = 6;
}

void MainWindow::loadSoundOption()
{
	optionsMenu->hide();
	soundOption->show();
	state = 7;
}

void MainWindow::loadGraphicsOption()
{
	optionsMenu->hide();
	graphicsOption->show();
	state = 8;
}

void MainWindow::loadServerOption()
{
	optionsMenu->hide();
	serverOption->show();
	state = 9;
}

void MainWindow::loadRulesOption()
{
	optionsMenu->hide();
	rulesOption->show();
	state = 10;
}

void MainWindow::loadCreditsOption()
{
	optionsMenu->hide();
	creditsOption->show();
	state = 11;
}

void MainWindow::backMainMenu()
{
	optionsMenu->hide();
	mainMenu->show();
	state = 1;
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

void MainWindow::acceptSoundOption()
{
	soundOption->hide();
	optionsMenu->show();
	state = 6;
}

void MainWindow::rejectSoundOption()
{
	soundOption->hide();
	optionsMenu->show();
	state = 6;
}

void MainWindow::acceptGraphicsOption()
{
	graphicsOption->hide();
	optionsMenu->show();
	state = 6;
}

void MainWindow::rejectGraphicsOption()
{
	graphicsOption->hide();
	optionsMenu->show();
	state = 6;
}

void MainWindow::acceptServerOption()
{
	serverOption->hide();
	optionsMenu->show();
	state = 6;
}

void MainWindow::rejectServerOption()
{
	serverOption->hide();
	optionsMenu->show();
	state = 6;
}

void MainWindow::backMenuOption(){
	if(state==10){
		rulesOption->hide();
	}else if(state==11){
		creditsOption->hide();
	}
	optionsMenu->show();
	state = 6;
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

void MainWindow::acceptLoadGame(){
	loadSaveGame->hide();
	boardWidget->show();
	state = 13;
}

void MainWindow::rejectedLoadSaveGame(){
	loadSaveGame->hide();
	mainMenu->show();
	state = 1;
}

void MainWindow::deleteSaveGame(){
	loadSaveGame->show();
	state = 12;
}

void MainWindow::saveGame(){
	if(state==17){
		boardWidget->hide();
	}
	loadSaveGame->show();
	state = 12;
}

void MainWindow::connectGameServer(){
	newNetworkGame->show();
	state = 14;
}

void MainWindow::refreshGameServer(){
	newNetworkGame->show();
	state = 14;
}

void MainWindow::rejectNewGameNetwork(){
	newNetworkGame->hide();
	mainMenu->show();
	state = 1;
}

void MainWindow::acceptNewGameNetwork(){
	newNetworkGame->hide();
	descriptionPlayersNetwork->show();
	state = 15;
}

void MainWindow::createNewGameNetwork(){
	newNetworkGame->hide();
	createNetworkGame->show();
	state = 16;
}

void MainWindow::playGameNetwork(){
	descriptionPlayersNetwork->hide();
	boardWidget->show();
	state = 17;
}

void MainWindow::exitGameNetwork(){
	descriptionPlayersNetwork->hide();
	newNetworkGame->show();
	state = 14;
}

void MainWindow::createGameNetwork(){
	createNetworkGame->hide();
	descriptionPlayersNetwork->show();
	state = 15;
}

void MainWindow::rejectGameNetwork(){
	createNetworkGame->hide();
	newNetworkGame->show();
	state = 14;
}

void MainWindow::startTravel(){
	boardWidget->show();
	state = 17;
}

void MainWindow::helpGame(){
	boardWidget->hide();
}

void MainWindow::quitGame(){
	boardWidget->hide();
	mainMenu->show();
	state = 1;
}
