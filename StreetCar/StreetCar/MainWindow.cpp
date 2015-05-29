#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>

#define MAINMENU 1
#define PROFILGAMELOCAL 2
#define NEWGAMELOCAL 3
#define PROFILS 4
#define BOARD 5
#define CARDS 6
#define PROFILGAMENET 7
#define NEWGAMENET 8
#define DESCRIPTIONPLAYERS 9
#define CREATEGAME 10
#define LOADGAME 11
#define PROFIL 12
#define OPTIONS 13
#define SOUND 14
#define GRAPHICS 15
#define SERVER 16
#define RULES 17
#define CREDITS 18


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
	chooseCards = new ChooseCards();
	chooseCards->hide();

	int widthWindow = width();
	//int heightWindow = height();

	mainMenu->setMinimumWidth(widthWindow/2);
	//mainMenu->setMinimumHeight(heightWindow-(heightWindow/2));
	newLocalGame->setMinimumWidth(widthWindow/2);
	newNetworkGame->setMinimumWidth(widthWindow/2);
	descriptionPlayersNetwork->setMinimumWidth(widthWindow/2);
	createNetworkGame->setMinimumWidth(widthWindow/2);
	loadSaveGame->setMinimumWidth(widthWindow/2);
	profilMenu->setMinimumWidth(widthWindow/2);
	optionsMenu->setMinimumWidth(widthWindow/2);
	soundOption->setMinimumWidth(widthWindow/2);
	serverOption->setMinimumWidth(widthWindow/2);
	rulesOption->setMinimumWidth(widthWindow/2);
	graphicsOption->setMinimumWidth(widthWindow/2);
	creditsOption->setMinimumWidth(widthWindow/2);
	chooseCards->setMinimumWidth(widthWindow);
	boardWidget->setMinimumWidth(widthWindow);

	ui->layoutMenu->addWidget(mainMenu);
	ui->layoutMenu->addWidget(newLocalGame);
	ui->layoutMenu->addWidget(newNetworkGame);
	ui->layoutMenu->addWidget(descriptionPlayersNetwork);
	ui->layoutMenu->addWidget(createNetworkGame);
	ui->layoutMenu->addWidget(loadSaveGame);
	ui->layoutMenu->addWidget(profilMenu);
	ui->layoutMenu->addWidget(optionsMenu);
	ui->layoutMenu->addWidget(soundOption);
	ui->layoutMenu->addWidget(serverOption);
	ui->layoutMenu->addWidget(rulesOption);
	ui->layoutMenu->addWidget(graphicsOption);
	ui->layoutMenu->addWidget(creditsOption);

	ui->layoutMenu->addWidget(chooseCards);
	ui->layoutMenu->addWidget(boardWidget);


	connect(mainMenu, SIGNAL(newGame()), this, SLOT(loadMenuNewGame()));
	connect(mainMenu, SIGNAL(newGameNetwork()), this, SLOT(loadMenuNewGameNetwork()));
	connect(mainMenu, SIGNAL(loadSaveGame()), this, SLOT(loadMenuloadSaveGame()));
	connect(mainMenu, SIGNAL(profil()), this, SLOT(loadMenuProfil()));
	connect(mainMenu, SIGNAL(options()), this, SLOT(loadMenuOptions()));
	connect(mainMenu, SIGNAL(exitGame()), qApp, SLOT(quit()));

	connect(newLocalGame, SIGNAL(accepted()), this, SLOT(acceptNewGameLocal()));
	connect(newLocalGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
	connect(newLocalGame, SIGNAL(newProfil()), this, SLOT(newProfilNewGameLocal()));

	connect(newNetworkGame, SIGNAL(connected()), this, SLOT(connectGameServer()));
	connect(newNetworkGame, SIGNAL(refreshed()), this, SLOT(refreshGameServer()));
	connect(newNetworkGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
	connect(newNetworkGame, SIGNAL(created()), this, SLOT(createNewGameNetwork()));
	connect(newNetworkGame, SIGNAL(accepted()), this, SLOT(acceptNewGameNetwork()));

	connect(descriptionPlayersNetwork, SIGNAL(accepted()), this, SLOT(playGameNetwork()));
	connect(descriptionPlayersNetwork, SIGNAL(rejected()), this, SLOT(exitGameNetwork()));

	connect(createNetworkGame, SIGNAL(accepted()), this, SLOT(createGameNetwork()));
	connect(createNetworkGame, SIGNAL(rejected()), this, SLOT(rejectGameNetwork()));

	connect(boardWidget, SIGNAL(startedTravel()), this, SLOT(startTravel()));
	connect(boardWidget, SIGNAL(saved()), this, SLOT(saveGame()));
	connect(boardWidget, SIGNAL(helped()), this, SLOT(helpGame()));
	connect(boardWidget, SIGNAL(exitGame()), this, SLOT(backMainMenu()));

	connect(loadSaveGame, SIGNAL(accepted()), this, SLOT(acceptLoadGame()));
	connect(loadSaveGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
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

	connect(soundOption, SIGNAL(accepted()), this, SLOT(acceptOption()));
	connect(soundOption, SIGNAL(rejected()), this, SLOT(backMenuOption()));

	connect(graphicsOption, SIGNAL(accepted()), this, SLOT(acceptOption()));
	connect(graphicsOption, SIGNAL(rejected()), this, SLOT(backMenuOption()));

	connect(serverOption, SIGNAL(accepted()), this, SLOT(acceptOption()));
	connect(serverOption, SIGNAL(rejected()), this, SLOT(backMenuOption()));

	connect(rulesOption, SIGNAL(backOptions()), this, SLOT(backMenuOption()));

	connect(creditsOption, SIGNAL(backOptions()), this, SLOT(backMenuOption()));


	state = MAINMENU;
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
		state = PROFILGAMELOCAL;
	}else {
		newLocalGame->show();
		state = NEWGAMELOCAL;
	}
}

void MainWindow::loadMenuNewGameNetwork()
{
	mainMenu->hide();
	if (currentProfile.name.empty()) {
		profilMenu->show();
		state = PROFILGAMENET;
	}else {
		newNetworkGame->show();
		state = NEWGAMENET;
	}
}

void MainWindow::loadMenuloadSaveGame()
{
	mainMenu->hide();
	loadSaveGame->show();
	state = LOADGAME;
}

void MainWindow::loadMenuProfil()
{
	mainMenu->hide();
	profilMenu->show();
	state = PROFIL;
}

void MainWindow::loadMenuOptions()
{
	mainMenu->hide();
	optionsMenu->show();
	state = OPTIONS;
}

void MainWindow::loadSoundOption()
{
	optionsMenu->hide();
	soundOption->show();
	state = SOUND;
}

void MainWindow::loadGraphicsOption()
{
	optionsMenu->hide();
	graphicsOption->show();
	state = GRAPHICS;
}

void MainWindow::loadServerOption()
{
	optionsMenu->hide();
	serverOption->show();
	state = SERVER;
}

void MainWindow::loadRulesOption()
{
	optionsMenu->hide();
	rulesOption->show();
	state = RULES;
}

void MainWindow::loadCreditsOption()
{
	optionsMenu->hide();
	creditsOption->show();
	state = CREDITS;
}

void MainWindow::backMainMenu()
{
	if(state==NEWGAMELOCAL){
		newLocalGame->hide();
	}else if(state==BOARD){
		boardWidget->hide();
	}else if(state==NEWGAMENET){
		newNetworkGame->hide();
	}else if(state==LOADGAME){
		loadSaveGame->hide();
	}else if(state==OPTIONS){
		optionsMenu->hide();
	}
	mainMenu->show();
	state = MAINMENU;
}

void MainWindow::acceptProfil(Profile p)
{
	profilMenu->hide();
	switch(state) {
		case PROFILGAMELOCAL:
			currentProfile = p;
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILS:
			currentProfile = p;
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILGAMENET:
			currentProfile = p;
			newNetworkGame->show();
			state = NEWGAMENET;
			break;
		case PROFIL:
			currentProfile = p;
			mainMenu->show();
			state = MAINMENU;
			break;
	}
}

void MainWindow::rejectProfil()
{
	profilMenu->hide();
	switch(state) {
		case PROFILGAMELOCAL:
			mainMenu->show();
			state = MAINMENU;
			break;
		case PROFILS:
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILGAMENET:
		case PROFIL:
			mainMenu->show();
			state = MAINMENU;
			break;
	}
}

void MainWindow::acceptOption()
{
	if(state==SOUND){
		soundOption->hide();
	}else if(state==GRAPHICS){
		graphicsOption->hide();
	}else if(state==SERVER){
		serverOption->hide();
	}
	optionsMenu->show();
	state = OPTIONS;
}

void MainWindow::backMenuOption(){
	if(state==SOUND){
		soundOption->hide();
	}else if(state==GRAPHICS){
		graphicsOption->hide();
	}else if(state==SERVER){
		serverOption->hide();
	}else if(state==RULES){
		rulesOption->hide();
	}else if(state==CREDITS){
		creditsOption->hide();
	}
	optionsMenu->show();
	state = OPTIONS;
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
	chooseCards->show();
	state = CARDS;
}


void MainWindow::newProfilNewGameLocal()
{
	newLocalGame->hide();
	profilMenu->show();
	state = PROFILS;
}

void MainWindow::acceptLoadGame(){
	loadSaveGame->hide();
	boardWidget->show();
	state = BOARD;
}

void MainWindow::deleteSaveGame(){
	loadSaveGame->show();
	state = LOADGAME;
}

void MainWindow::saveGame(){
	if(state==BOARD){
		boardWidget->hide();
	}
	loadSaveGame->show();
	state = LOADGAME;
}

void MainWindow::connectGameServer(){
	newNetworkGame->show();
	state = NEWGAMENET;
}

void MainWindow::refreshGameServer(){
	newNetworkGame->show();
	state = NEWGAMENET;
}

void MainWindow::acceptNewGameNetwork(){
	newNetworkGame->hide();
	descriptionPlayersNetwork->show();
	state = DESCRIPTIONPLAYERS;
}

void MainWindow::createNewGameNetwork(){
	newNetworkGame->hide();
	createNetworkGame->show();
	state = CREATEGAME;
}

void MainWindow::playGameNetwork(){
	descriptionPlayersNetwork->hide();
	boardWidget->show();
	state = BOARD;
}

void MainWindow::exitGameNetwork(){
	descriptionPlayersNetwork->hide();
	newNetworkGame->show();
	state = NEWGAMENET;
}

void MainWindow::createGameNetwork(){
	createNetworkGame->hide();
	descriptionPlayersNetwork->show();
	state = DESCRIPTIONPLAYERS;
}

void MainWindow::rejectGameNetwork(){
	createNetworkGame->hide();
	newNetworkGame->show();
	state = NEWGAMENET;
}

void MainWindow::startTravel(){
	boardWidget->show();
	state = BOARD;
}

void MainWindow::helpGame(){
	boardWidget->hide();
}

void MainWindow::chooseCardsGame(){
	if(state==DESCRIPTIONPLAYERS){
		descriptionPlayersNetwork->hide();
	}else if(state==NEWGAMELOCAL){
		newLocalGame->hide();
	}
	chooseCards->show();
	state = CARDS;
}
