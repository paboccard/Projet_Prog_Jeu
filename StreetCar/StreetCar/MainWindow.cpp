#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../Shared/StartTravel.h"
#include "../Shared/PlayTravel.h"
#include "../Shared/StopTravel.h"
#include "../Shared/PlayTile.h"
#include "../Shared/PileWhenTravel.h"
#include "../Shared/IWantPlay.h"
#include "../Shared/StartGame.h"
#include "../Shared/CreateGame.h"
#include "../Shared/InitGame.h"
#include "../Shared/PlayedTile.h"
#include "../Shared/PlayedTravel.h"
#include "../Shared/StartedTravel.h"
#include "../Shared/StoppedTravel.h"
#include "../Shared/Validation.h"
#include "../Shared/Won.h"
#include "../Shared/PilePlayer.h"
#include "../Shared/NewPlayerAdd.h"
#include "../Shared/Pack.h"
#include "../Shared/Debug.h"
#include "../Shared/YourIdPlayer.h"
#include "../Shared/Goal.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QtGui>
#include <QGraphicsDropShadowEffect>


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
    int heightWindow = height();
    int heightHead = ui->label->height() + ui->labelName->height();

    mainMenu->setMinimumWidth(widthWindow/2);
    mainMenu->setMinimumHeight(heightWindow-heightHead);

	newLocalGame->setMinimumWidth(widthWindow/2);
	newNetworkGame->setMinimumWidth(widthWindow/2);
	descriptionPlayersNetwork->setMinimumWidth(widthWindow/2);
	createNetworkGame->setMinimumWidth(widthWindow/2);
    loadSaveGame->setMaximumWidth(widthWindow/2);
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

	connect(mainMenu, SIGNAL(continueGame()), this, SLOT(loadBoardGame()));
	connect(mainMenu, SIGNAL(newGame()), this, SLOT(loadMenuNewGame()));
	connect(mainMenu, SIGNAL(newGameNetwork()), this, SLOT(loadMenuNewGameNetwork()));
	connect(mainMenu, SIGNAL(loadSaveGame()), this, SLOT(loadMenuloadSaveGame()));
	connect(mainMenu, SIGNAL(profil()), this, SLOT(loadMenuProfil()));
	connect(mainMenu, SIGNAL(options()), this, SLOT(loadMenuOptions()));
	connect(mainMenu, SIGNAL(exitGame()), qApp, SLOT(quit()));

	connect(newLocalGame, SIGNAL(accepted(int, QVector<Profile>)), this, SLOT(acceptNewGameLocal(int, QVector<Profile>)));
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

	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
	effect->setColor(QColor(255,0,0,255));
	effect->setOffset(1,1);
	ui->labelName->setGraphicsEffect(effect);

	prodConsOutput = new ProdCons<Pack*>();
	threadInput = new ServerInputThread();
	threadOutput = new ServerOutputThread(prodConsOutput);
	connect(threadInput, SIGNAL(receive(Pack*)), this, SLOT(receivePacket(Pack*)));
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

void MainWindow::setFixedSize(int x, int y){
     x = this->geometry().width();
     y = this->geometry().height();

     int heightHead = ui->label->height() + ui->labelName->height();

     mainMenu->setMinimumWidth(x/2);
     mainMenu->setMinimumHeight(y-heightHead);
	 newLocalGame->setMinimumWidth(x/2);
	 newNetworkGame->setMinimumWidth(x/2);
	 descriptionPlayersNetwork->setMinimumWidth(x/2);
	 createNetworkGame->setMinimumWidth(x/2);
	 loadSaveGame->setMinimumWidth(x/2);
	 profilMenu->setMinimumWidth(x/2);
	 optionsMenu->setMinimumWidth(x/2);
	 soundOption->setMinimumWidth(x/2);
	 serverOption->setMinimumWidth(x/2);
	 rulesOption->setMinimumWidth(x/2);
	 graphicsOption->setMinimumWidth(x/2);
	 creditsOption->setMinimumWidth(x/2);
	 chooseCards->setMinimumWidth(x);
	 boardWidget->setMinimumWidth(x);
}

void MainWindow::loadBoardGame(){
	mainMenu->hide();
	ui->groupBox->hide();
	boardWidget->show();
	state = BOARD;
}

void MainWindow::loadMenuNewGame()
{
	mainMenu->hide();
	if (currentProfile.name.empty()) {
		profilMenu->hideModifyButton();
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
		profilMenu->hideModifyButton();
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
	profilMenu->showModifyButton();
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
	if(!p.name.empty()){
		profiles.push_back(p);
		newLocalGame->getProfiles()->clear();
		newLocalGame->getProfiles()->push_back(p);

		newLocalGame->getNames()->clear();
		for (int i = 0; i < profiles.size(); i++){
			p = profiles.at(i);
			newLocalGame->getNames()->push_back(QString::fromStdString(p.name));
		}
		//std::cout  << names->size() << endl;
		newLocalGame->update();
	}
	switch(state) {
		case PROFILGAMELOCAL:
			currentProfile = p;
			if(!currentProfile.name.empty()){
				ui->labelUser->setText(currentProfile.name.c_str());
			}
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILS:
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILGAMENET:
			currentProfile = p;
			if(!currentProfile.name.empty()){
				ui->labelUser->setText(currentProfile.name.c_str());
			}
			newNetworkGame->show();
			state = NEWGAMENET;
			break;
		case PROFIL:
			currentProfile = p;
			if(!currentProfile.name.empty()){
				ui->labelUser->setText(currentProfile.name.c_str());
			}
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

void MainWindow::receivePacket(Pack *p)
{
	cout << "read pack : " << p->idPack << endl;
	switch((packs)p->idPack) {
		case DEBUG:
			{

			}
			break;
		case INITGAME:
			{

			}
			break;
		case PLAYEDTILE:
			{

			}
			break;
		case PLAYEDTRAVEL:
			{

			}
			break;
		case STARTEDTRAVEL:
			{

			}
			break;
		case STOPPEDTRAVEL:
			{

			}
			break;
		case VALIDATION:
			{
				switch (((Validation*)p)->error) {
					case DISCONNECTED:
						qDebug() << "Disconnect to the server" << endl;
						boardWidget->hide();
						mainMenu->show();
						state = 1;
						QMessageBox::critical(this, tr("Deconnection"), tr("Deconnecté du serveur"));
						break;
					case GAMEFULL:
						qDebug() << "The game is full" << endl;
						boardWidget->hide();
						mainMenu->show();
						state = 1;
						QMessageBox::critical(this, tr("Partie plaine"), tr("Impossible de joindre la partie. Trop de joueurs connecté"));
						break;
				}
			}
			break;
		case WON:
			{

			}
			break;
		case PILEPLAYER:
			{

			}
			break;
		case NEWPLAYERADD:
			{
				qDebug() << "New Player " << endl;

				NewPlayerAdd *newPlayer = (NewPlayerAdd*)p;
				int i = 0;
				while (i < players.size() && players[i]->getMyIdPlayer() != newPlayer->idPlayer)
					i++;

				if (i < players.size())
					players[i]->setProfile(newPlayer->profile);
				else {
					Player *player = new Player();
					player->setMyIdPlayer(newPlayer->idPlayer);
					player->setProfile(newPlayer->profile);
					players.push_back(player);
				}
				delete newPlayer;
				indexPlayerSend ++;

				if (indexPlayerSend < profilesToPlay.size())
				{
					prodConsOutput->produce(new IWantPlay(profilesToPlay[i]));
					qDebug() << "send new player " << endl;

				}
			}
			break;
		case YOURIDPLAYER:
			{
				Player *player = new Player();
				player->setMyIdPlayer(((YourIdPlayer*)p)->idPlayer);
				players.push_back(player);
				qDebug() << "Current id player : " << ((YourIdPlayer*)p)->idPlayer;
			}
			break;
		case GOAL:
			{
				Goal *goal = (Goal*)p;
			}
			break;
		default:
			cout << "ERROR packet read is undefined main thread " << p->idPack << endl;
			break;
	}
}

void MainWindow::acceptNewGameLocal(int nb, QVector<Profile> p)
{

	if (connectionReseau()) {
		indexPlayerSend = 0;
		profilesToPlay = p;
		CreateGame *c = new CreateGame(nb);
		prodConsOutput->produce(c);
		prodConsOutput->produce(new IWantPlay(profilesToPlay.front()));
	}
	else {
		QMessageBox::critical(this, tr("Erreur réseau"), tr("Impossible de se connecter au server"));
		return;
	}
	newLocalGame->hide();
	//chooseCards->show();
	//state = CARDS;
}

bool MainWindow::connectionReseau()
{
	struct sockaddr_in serv_addr;
	struct hostent *server = NULL;
	int portno = 8080;
	int sockfd;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		cout << "ERROR opening socket" << endl;
		return false;
	}

	server = gethostbyname("localhost");
	if (server == NULL) {
		cout << "ERROR, no such host " << endl;
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));	//reset addr

	serv_addr.sin_family = AF_INET;

	bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);

	serv_addr.sin_port = htons(portno);

	//Adress by IP
	serv_addr.sin_addr.s_addr = inet_addr("152.77.82.244");
	//bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));


	cout << "start to connect to the server " << sockfd << endl;
	if (::connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		cout << "ERROR connecting " << endl;
		return false;
	}

	cout << "Connected to the server" << endl;

	threadInput->setSocket(sockfd);
	threadOutput->setSocket(sockfd);

	threadInput->start();
	threadOutput->start();

	//chooseCards->show();
	//state = CARDS;
	return true;
}


void MainWindow::newProfilNewGameLocal()
{
    newLocalGame->hide();
	profilMenu->hideModifyButton();
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
