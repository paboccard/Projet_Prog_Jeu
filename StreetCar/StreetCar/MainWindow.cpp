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
#include "../Shared/Quit.h"
#include "../Shared/Board.h"
#include "../Shared/RefreshGamesNetwork.h"
#include "../Shared/CreateGameNetwork.h"
#include "../Shared/ResponseRefresh.h"
#include "../Shared/ResponsePlayerRefresh.h"
#include "../Shared/GameCreateNetwork.h"
#include "../Shared/IWantPlayNetwork.h"

#include <fcntl.h>
#include <sys/time.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include <QtGui>
#include <QGraphicsDropShadowEffect>
#include <QDesktopWidget>
#define MAINMENU 1
#define PROFILGAMELOCAL 2
#define NEWGAMELOCAL 3
#define PROFILS 4
#define DELPROFILE 5
#define BOARD 6
#define CARDS 7
#define PROFILGAMENET 8
#define NEWGAMENET 9
#define DESCRIPTIONPLAYERS 10
#define CREATEGAME 11
#define LOADGAME 12
#define PROFIL 13
#define OPTIONS 14
#define SOUND 15
#define GRAPHICS 16
#define SERVER 17
#define RULES 18
#define CREDITS 19
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
    //boardWidget = new BoardWidget();
    //boardWidget->hide();
    gameWidget = new GameWidget();
    gameWidget->hide();
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
    deleteProfile = new DeleteProfile();
    deleteProfile->hide();
    //size main window
    widthWindow = width();
    heightWindow = height();
<<<<<<< HEAD
	int heightHead = ui->label->height() + ui->labelName->height();

=======
    // int heightHead = ui->label->height() + ui->labelName->height();
>>>>>>> 1175c7e25b9136740839bfec70d690fa3a468420
    //center main window
    widthDesktop = qApp->desktop()->width();
    heightDesktop = qApp->desktop()->height();
    int x = widthDesktop/2 - widthWindow/2;
    int y = heightDesktop/2 - heightWindow/2 - 25;
    move(QPoint(x, y));
    //size windows
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
	chooseCards->setMaximumHeight(heightWindow-heightHead);
	deleteProfile->setMinimumWidth(widthWindow/2);
	//boardWidget->setMinimumWidth(widthWindow);
	gameWidget->setMinimumWidth(widthWindow);

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
	ui->layoutMenu->addWidget(deleteProfile);

	ui->layoutMenu->addWidget(chooseCards);
	//ui->layoutMenu->addWidget(boardWidget);
	//ui->layoutMenu->addWidget(gameWidget);

	ui->mainLayout->addWidget(gameWidget);

	//connect(mainMenu, SIGNAL(continueGame()), this, SLOT(loadBoardGame()));

	connect(mainMenu, SIGNAL(newGame()), this, SLOT(loadMenuNewGame()));
	connect(mainMenu, SIGNAL(newGameNetwork()), this, SLOT(loadMenuNewGameNetwork()));
	connect(mainMenu, SIGNAL(loadSaveGame()), this, SLOT(loadMenuloadSaveGame()));
	connect(mainMenu, SIGNAL(profil()), this, SLOT(loadMenuProfil()));
	connect(mainMenu, SIGNAL(options()), this, SLOT(loadMenuOptions()));
	connect(mainMenu, SIGNAL(exitGame()), qApp, SLOT(quit()));

	connect(newLocalGame, SIGNAL(accepted(int, QVector<Profile>)), this, SLOT(acceptNewGameLocal(int, QVector<Profile>)));
	connect(newLocalGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
	connect(newLocalGame, SIGNAL(newProfil()), this, SLOT(newProfilNewGameLocal()));
	connect(newLocalGame, SIGNAL(deleteProfil()), this, SLOT(delProfilNewGameLocal()));

	connect(newNetworkGame, SIGNAL(connected()), this, SLOT(connectGameServer()));
	connect(newNetworkGame, SIGNAL(refreshed()), this, SLOT(refreshGameServer()));
	connect(newNetworkGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
	connect(newNetworkGame, SIGNAL(created()), this, SLOT(createNewGameNetwork()));
	connect(newNetworkGame, SIGNAL(accepted()), this, SLOT(acceptNewGameNetwork()));

	connect(descriptionPlayersNetwork, SIGNAL(accepted()), this, SLOT(playGameNetwork()));
	connect(descriptionPlayersNetwork, SIGNAL(rejected()), this, SLOT(exitGameNetwork()));

	connect(createNetworkGame, SIGNAL(accepted()), this, SLOT(createGameNetwork()));
	connect(createNetworkGame, SIGNAL(rejected()), this, SLOT(rejectGameNetwork()));

/*	connect(boardWidget, SIGNAL(startedTravel()), this, SLOT(startTravel()));

    soundOption->setMinimumWidth(widthWindow/2);
    serverOption->setMinimumWidth(widthWindow/2);
    rulesOption->setMinimumWidth(widthWindow/2);
    graphicsOption->setMinimumWidth(widthWindow/2);
    creditsOption->setMinimumWidth(widthWindow/2);
    chooseCards->setMinimumWidth(widthWindow);
    deleteProfile->setMinimumWidth(widthWindow/2);
    //boardWidget->setMinimumWidth(widthWindow);
    gameWidget->setMinimumWidth(widthWindow);
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
    ui->layoutMenu->addWidget(deleteProfile);
    ui->layoutMenu->addWidget(chooseCards);
    //ui->layoutMenu->addWidget(boardWidget);
    //ui->layoutMenu->addWidget(gameWidget);
    ui->mainLayout->addWidget(gameWidget);
    //connect(mainMenu, SIGNAL(continueGame()), this, SLOT(loadBoardGame()));
    connect(mainMenu, SIGNAL(newGame()), this, SLOT(loadMenuNewGame()));
    connect(mainMenu, SIGNAL(newGameNetwork()), this, SLOT(loadMenuNewGameNetwork()));
    connect(mainMenu, SIGNAL(loadSaveGame()), this, SLOT(loadMenuloadSaveGame()));
    connect(mainMenu, SIGNAL(profil()), this, SLOT(loadMenuProfil()));
    connect(mainMenu, SIGNAL(options()), this, SLOT(loadMenuOptions()));
    connect(mainMenu, SIGNAL(exitGame()), qApp, SLOT(quit()));
    connect(newLocalGame, SIGNAL(accepted(int, QVector<Profile>)), this, SLOT(acceptNewGameLocal(int, QVector<Profile>)));
    connect(newLocalGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
    connect(newLocalGame, SIGNAL(newProfil()), this, SLOT(newProfilNewGameLocal()));
    connect(newLocalGame, SIGNAL(deleteProfil()), this, SLOT(delProfilNewGameLocal()));
    connect(chooseCards, SIGNAL(validated()), this, SLOT(validCards()));
    connect(newNetworkGame, SIGNAL(connected()), this, SLOT(connectGameServer()));
    connect(newNetworkGame, SIGNAL(refreshed()), this, SLOT(refreshGameServer()));
    connect(newNetworkGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
    connect(newNetworkGame, SIGNAL(created()), this, SLOT(createNewGameNetwork()));
    //connect(newNetworkGame, SIGNAL(accepted()), this, SLOT(acceptNewGameNetwork()));
    connect(descriptionPlayersNetwork, SIGNAL(accepted()), this, SLOT(playGameNetwork()));
    connect(descriptionPlayersNetwork, SIGNAL(rejected()), this, SLOT(exitGameNetwork()));
    connect(createNetworkGame, SIGNAL(accepted()), this, SLOT(createGameNetwork()));
    connect(createNetworkGame, SIGNAL(rejected()), this, SLOT(rejectGameNetwork()));
    /* connect(boardWidget, SIGNAL(startedTravel()), this, SLOT(startTravel()));
soundOption->setMinimumWidth(widthWindow/2);
serverOption->setMinimumWidth(widthWindow/2);
rulesOption->setMinimumWidth(widthWindow/2);
graphicsOption->setMinimumWidth(widthWindow/2);
creditsOption->setMinimumWidth(widthWindow/2);
chooseCards->setMinimumWidth(widthWindow);
//boardWidget->setMinimumWidth(widthWindow);
gameWidget->setMinimumWidth(widthWindow);
*/
    connect(loadSaveGame, SIGNAL(accepted()), this, SLOT(acceptLoadGame()));
    connect(loadSaveGame, SIGNAL(rejected()), this, SLOT(backMainMenu()));
    connect(loadSaveGame, SIGNAL(deleted()), this, SLOT(deleteSaveGame()));
    connect(loadSaveGame, SIGNAL(saved()), this, SLOT(saveGame()));
    connect(profilMenu, SIGNAL(accepted(Profile)), this, SLOT(acceptProfil(Profile)));
    connect(profilMenu, SIGNAL(modified(Profile)), this, SLOT(modifyProfil(Profile)));
    connect(profilMenu, SIGNAL(rejected()), this, SLOT(rejectProfil()));
    connect(deleteProfile, SIGNAL(accepted(Profile)), this, SLOT(acceptDelProfile(Profile)));
    connect(deleteProfile, SIGNAL(rejected()), this, SLOT(rejectDelProfile()));
    connect(optionsMenu, SIGNAL(soundOption()), this, SLOT(loadSoundOption()));
    connect(optionsMenu, SIGNAL(serverOption()), this, SLOT(loadServerOption()));
    connect(optionsMenu, SIGNAL(graphicsOption()), this, SLOT(loadGraphicsOption()));
    connect(optionsMenu, SIGNAL(rulesOption()), this, SLOT(loadRulesOption()));
    connect(optionsMenu, SIGNAL(creditsOption()), this, SLOT(loadCreditsOption()));
    connect(optionsMenu, SIGNAL(backMenu()), this, SLOT(backMainMenu()));
    connect(soundOption, SIGNAL(accepted(bool)), this, SLOT(acceptOptionSound(bool)));
    connect(soundOption, SIGNAL(rejected()), this, SLOT(backMenuOption()));
    connect(graphicsOption, SIGNAL(accepted(bool, int, int)), this, SLOT(acceptOptionGraphics(bool, int, int)));
    connect(graphicsOption, SIGNAL(rejected()), this, SLOT(backMenuOption()));
    connect(serverOption, SIGNAL(accepted()), this, SLOT(acceptOptionServer()));
    connect(serverOption, SIGNAL(rejected()), this, SLOT(backMenuOption()));
    connect(rulesOption, SIGNAL(backOptions()), this, SLOT(backMenuOption()));
    connect(creditsOption, SIGNAL(backOptions()), this, SLOT(backMenuOption()));
    connect(gameWidget, SIGNAL(exitGame()), this, SLOT(exitGame()));
    state = MAINMENU;
    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->labelName->setGraphicsEffect(effect);
    // if(sound->isAvailable())
    // printf("Sound Facility is available\n");
    // else
    // printf("Sound Facility is not available\n");
    // QString soundFile = QDir::toNativeSeparators("/home/k/kiragoje/Projet_Prog_Jeu/StreetCar/StreetCar/sound/Frontierland.wav");
    // cout << endl << soundFile.toStdString()<<endl;
    // sound = new QSound(soundFile);
    // sound->play();
    // sound->setLoops(10);
    prodConsOutput = new ProdCons<Pack*>();
    threadInput = new ServerInputThread();
    threadOutput = new ServerOutputThread(prodConsOutput);
    connect(threadInput, SIGNAL(receive(Pack*)), this, SLOT(receivePacket(Pack*)));
    gameWidget->setOutput(prodConsOutput);
}
MainWindow::~MainWindow()
{
    cout << "DESTRUCTEUR" << endl;
    prodConsOutput->produce(new Quit());
    delete mainMenu;
    delete newLocalGame;
    delete newNetworkGame;
    delete descriptionPlayersNetwork;
    delete createNetworkGame;
    //delete boardWidget;
    delete loadSaveGame;
    delete profilMenu;
    delete optionsMenu;
    delete soundOption;
    delete graphicsOption;
    delete serverOption;
    delete rulesOption;
    delete creditsOption;
    delete deleteProfile;
    delete ui;
}
void MainWindow::setFixedSize(int x, int y){
    this->update();
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
    //boardWidget->setMinimumWidth(x);
}
void MainWindow::resizeEvent(QResizeEvent *e)
{
    /*setGeometry(e->size());
x = this->geometry().width();
y = this->geometry().height();
*/
    /*
int x = width();
int y = height();
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
gameWidget->setMinimumWidth(x);
*/
}
void MainWindow::loadBoardGame(){
    mainMenu->hide();
    ui->groupBox->hide();
    gameWidget->show();
    //boardWidget->show();
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
        newLocalGame->hideDelProfile();
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
    if(currentProfile.name.empty()){
        profilMenu->hideModifyButton();
    }else{
        profilMenu->hideCreateButton();
        profilMenu->showModifyButton();
        profilMenu->currentProfile();
    }
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
        gameWidget->hide();
        //boardWidget->hide();
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
        //gestion double profile
        int nb =0;
        for (unsigned int i = 0; i < profiles.size(); i++){
            if((p.name == profiles.at(i).name) && (p.avatar == profiles.at(i).avatar)){
                nb++;
            }
        }
        if(nb>1){
            for (unsigned int i = 0; i < profiles.size(); i++){
                if((p.name == profiles.at(i).name) && (p.avatar == profiles.at(i).avatar)){
                    profiles.erase(profiles.begin()+i+1);
                }
            }
        }else{
            newLocalGame->getProfiles()->push_back(p);
            profilMenu->getProfiles()->push_back(p);
            deleteProfile->getProfiles()->push_back(p);
            deleteProfile->update();
        }
        newLocalGame->getNames()->clear();
        for (unsigned int i = 0; i < profiles.size(); i++){
            p = profiles.at(i);
            newLocalGame->getNames()->push_back(QString::fromStdString(p.name));
        }
        newLocalGame->update();
    }
    switch(state) {
    case PROFILGAMELOCAL:
        currentProfile = profiles.at(0);
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
        currentProfile = profiles.at(0);
        if(!currentProfile.name.empty()){
            ui->labelUser->setText(currentProfile.name.c_str());
        }
        newNetworkGame->show();
        state = NEWGAMENET;
        break;
    case PROFIL:
        currentProfile = profiles.at(0);
        if(!currentProfile.name.empty()){
            ui->labelUser->setText(currentProfile.name.c_str());
        }
        mainMenu->show();
        state = MAINMENU;
        break;
    }
<<<<<<< HEAD
	switch(state) {
		case PROFILGAMELOCAL:
            currentProfile = profiles.at(0);
			if(!currentProfile.name.empty()){
				ui->labelUser->setText(currentProfile.name.c_str());
			}
            newLocalGame->hideDelProfile();
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILS:
            newLocalGame->showDelProfile();
			newLocalGame->show();
			state = NEWGAMELOCAL;
			break;
		case PROFILGAMENET:
            currentProfile = profiles.at(0);
			if(!currentProfile.name.empty()){
				ui->labelUser->setText(currentProfile.name.c_str());
			}
			newNetworkGame->show();
			state = NEWGAMENET;
			break;
		case PROFIL:
            currentProfile = profiles.at(0);
			if(!currentProfile.name.empty()){
				ui->labelUser->setText(currentProfile.name.c_str());
			}
			mainMenu->show();
			state = MAINMENU;
			break;
	}
=======
>>>>>>> 1175c7e25b9136740839bfec70d690fa3a468420
}
void MainWindow::modifyProfil(Profile p){
    profilMenu->hide();
    currentProfile = p;
    ui->labelUser->setText(currentProfile.name.c_str());
    newLocalGame->getProfiles()->pop_front();
    newLocalGame->getProfiles()->push_front(p);
    profilMenu->getProfiles()->pop_front();
    profilMenu->getProfiles()->push_front(p);
    deleteProfile->getProfiles()->pop_front();
    deleteProfile->getProfiles()->push_front(p);
    newLocalGame->getNames()->pop_front();
    newLocalGame->getNames()->push_front(p.name.c_str());
    newLocalGame->update();
    mainMenu->show();
    state = MAINMENU;
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
void MainWindow::delProfilNewGameLocal(){
    newLocalGame->hide();
    deleteProfile->show();
    state = DELPROFILE;
}
void MainWindow::acceptDelProfile(Profile p){
	for (unsigned int i = 0; i < profiles.size(); i++){
		if((p.name == profiles.at(i).name) && (p.avatar == profiles.at(i).avatar)){
			if(profiles.end()-i!=profiles.begin()+i){
			   profiles.erase(profiles.begin()+i);
			   cout << "p: "<<i << profiles.at(i).name << endl;
			   newLocalGame->getProfiles()->erase(newLocalGame->getProfiles()->begin()+i);
			   newLocalGame->getNames()->erase(newLocalGame->getNames()->begin()+i);
			   deleteProfile->getProfiles()->erase(deleteProfile->getProfiles()->begin()+i);
			}else{
				profiles.pop_back();
				newLocalGame->getProfiles()->pop_back();
				newLocalGame->getNames()->pop_back();
				deleteProfile->getProfiles()->pop_back();
			}

		}
	}
	deleteProfile->update();
	newLocalGame->update();
	deleteProfile->hide();
	newLocalGame->show();
	state = NEWGAMELOCAL;
}
void MainWindow::rejectDelProfile(){
    deleteProfile->hide();
    newLocalGame->show();
    state = NEWGAMELOCAL;
}
void MainWindow::exitGame()
{
    prodConsOutput->produce(new Quit());
    ::close(sockfd);
    gameWidget->hide();
    ui->widgetContent->show();
    mainMenu->show();
    state = MAINMENU;
}
void MainWindow::acceptOptionGraphics(bool fullScreen, int w, int h)
{
    graphicsOption->hide();
    if(fullScreen==true){
<<<<<<< HEAD
		ui->centralWidget->update();
		ui->centralWidget->setFixedSize(w, h);
		this->setFixedWidth(w);
		this->setFixedHeight(h);
		ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/images/background) 0 0 0 0 stretch stretch;} #label {font-size: 30px;} QPushButton{font-size: 20px; margin-bottom:20px; margin-right:10px} ");
		this->updateGeometry();
		move(QPoint(0, 0));
    }else{
		ui->centralWidget->update();
		ui->centralWidget->setFixedSize(widthWindow, heightWindow+45);
		this->setFixedWidth(widthWindow);
		this->setFixedHeight(heightWindow+45);
		this->updateGeometry();
		ui->centralWidget->setStyleSheet("#centralWidget {border-image: url(:/images/background) 0 0 0 0 stretch stretch;} #label {font-size: 24px;} QPushButton{font-size: 20px} ");
		int x = widthDesktop/2 - widthWindow/2;
		int y = heightDesktop/2 - heightWindow/2 - 25;
		move(QPoint(x, y));
=======
        ui->centralWidget->update();
        ui->centralWidget->setFixedSize(w, h);
        this->setFixedWidth(w);
        this->setFixedHeight(h);
        this->updateGeometry();
        move(QPoint(0, 0));
    }else{
        ui->centralWidget->update();
        ui->centralWidget->setFixedSize(widthWindow, heightWindow+45);
        this->setFixedWidth(widthWindow);
        this->setFixedHeight(heightWindow+45);
        this->updateGeometry();
        int x = widthDesktop/2 - widthWindow/2;
        int y = heightDesktop/2 - heightWindow/2 - 25;
        move(QPoint(x, y));
>>>>>>> 1175c7e25b9136740839bfec70d690fa3a468420
    }
    optionsMenu->show();
    state = OPTIONS;
}
void MainWindow::acceptOptionSound(bool musicOn)
{
    soundOption->hide();
    /* if(musicOn==true){
sound->play();
sound->setLoops(10);
}else{
sound->stop();
}*/
    optionsMenu->show();
    state = OPTIONS;
}
void MainWindow::acceptOptionServer()
{
    serverOption->hide();
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
	cout << "G: read pack : " << p->toString()<< endl;
	switch((packs)p->idPack) {
		case DEBUG:
			{

			}
			break;
		case INITGAME:
			{
				qDebug() << "Init game";
				InitGame *game = (InitGame*)p;
				//cout << *game << endl;
				for (int i = 0; i < players.size(); i ++) {
					Tile *t[5];
					cout << "player " << i << " ";
					for (int j = 0; j < 5; j ++){
						t[j] = new Tile();
						*t[j] = game->hands[i][j];
						t[j]->setPlayer(i);
					}
					cout << endl;
					players[i]->setHand(t);
				}

				gameWidget->setPlayers(players);
				gameWidget->setMyPlayers(playersHere);
				gameWidget->setCurrentPlayer(game->idFirstPlayer);
				ui->widgetContent->hide();
				gameWidget->show();
			}
			break;
		case PLAYEDTILE:
			{
				PlayedTile *playedTil = (PlayedTile*)p;
				gameWidget->setPlayedTil(playedTil->tiles);
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
					case IMPOSSIBLE_PLAY:
						qDebug() << "IMPOSSIBLE_PLAY";
						QMessageBox::information(this, tr("Coup invalidé"), tr("Le coup à été invalidé par le server"));
						gameWidget->strokeInvalid();
						break;

					case TOO_MANY_TILES:
						qDebug() << "TOO_MANY_TILES";
						break;

					case WRONG_WAY:
						qDebug() << "WRONG_WAY";
						break;

					case TILE_NOT_IN_HAND:
						qDebug() << "TILE_NOT_IN_HAND";
						QMessageBox::critical(this, tr("Mains désynchronisé"), tr("ERREUR, La tuile joué ne se trouve pas dans la main"));
						qApp->quit();
						break;

					case DISCONNECTED:
						qDebug() << "DISCONNECTED";
						gameWidget->hide();
						//boardWidget->hide();
						mainMenu->show();
						state = 1;
						QMessageBox::critical(this, tr("Deconnection"), tr("Deconnecté du serveur"));
						break;

					case GAME_FULL:
						qDebug() << "GAME_FULL";
						gameWidget->hide();
						//boardWidget->hide();
						mainMenu->show();
						state = 1;
						QMessageBox::critical(this, tr("Partie plaine"), tr("Impossible de joindre la partie. Trop de joueurs connecté"));
						break;

					case WRONG_PLAYER:
						qDebug() << "WRONG_PLAYER";
						break;

					case TIME_FOR_REGULAR_PILE:
						qDebug() << "TIME_FOR_REGULAR_PILE";
						break;

					case TRAVEL_NOT_STARTED:
						qDebug() << "TRAVEL_NOT_STARTED";
						break;

					default:
						qDebug() << "auther Validation";
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
				PilePlayer *pile = (PilePlayer*)p;
				gameWidget->setPilePlayer(pile->idPlayer, pile->tilesPiled, pile->idxTiles);

				gameWidget->setCurrentPlayer(pile->idNextPlayer);
			}
			break;
		case NEWPLAYERADD:
			{

				NewPlayerAdd *newPlayer = (NewPlayerAdd*)p;
				qDebug() << "New Player " << QString::fromStdString(newPlayer->profile.name);

				/*
				int i = 0;
				while (i < players.size() && players[i]->getMyIdPlayer() != newPlayer->idPlayer)
					i++;

				if (i < players.size())
					players[i]->setProfile(newPlayer->profile);
				else {
					*/
					Player *player = new Player();
					player->setMyIdPlayer(newPlayer->idPlayer);
					player->setProfile(newPlayer->profile);
					players.push_back(player);
			//	}

				if (!isLocal)
					descriptionPlayersNetwork->addPlayer(player->getProfile());

				delete newPlayer;

				if (isLocal)
				{
					indexPlayerSend ++;
					cout << "profilesToPlay = " << profilesToPlay.size() << " - indexPlayerSend " << indexPlayerSend << endl;

					if (indexPlayerSend < profilesToPlay.size())
					{
						if (profilesToPlay.at(indexPlayerSend).type > 0){//if Computer -> fork()
							char *envp[] = { NULL };
							char *argv[] = { (char*)("../Computer/applicationComputer"),
											 (char*)profilesToPlay[indexPlayerSend].name.c_str(),
											 (char*)QString::number(profilesToPlay[indexPlayerSend].avatar).toStdString().c_str(),
											 (char*)QString::number(profilesToPlay[indexPlayerSend].type).toStdString().c_str(),
											 NULL};
							pid_t pid;
							if ((pid = fork()) == 0){ //child process
								cout << "FORK " << endl;

								int fd = open("logComputerx", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);


								dup2(fd, 1);   // make stdout go to file
								dup2(fd, 2);   // make stderr go to file - you may choose to not do this
								// or perhaps send stderr to another file

								::close(fd);
								execve(argv[0], argv, envp);
								exit(0);
							}
						}else
							prodConsOutput->produce(new IWantPlay(profilesToPlay[indexPlayerSend]));
						qDebug() << "send new player ";
					}
					else {
						prodConsOutput->produce(new StartGame());
						qDebug() << "start new party";
					}
				}
			}
			break;
		case YOURIDPLAYER:
			{
			/*	Player *player = new Player();
				player->setMyIdPlayer(((YourIdPlayer*)p)->idPlayer);
				players.push_back(player);*/
				//gameWidget->setYourId(((YourIdPlayer*)p)->idPlayer);
				playersHere.append(((YourIdPlayer*)p)->idPlayer);
			}
			break;
		case GOAL:
			{
				qDebug() << "my goal";
				Goal *goal = (Goal*)p;

				qDebug() << "line : " << goal->goalPlayer.line;
				qDebug() << "card : " << goal->goalPlayer.stop.numCard;
				int* s = goal->goalPlayer.stop.whichStation(goal->goalPlayer.line);

				vector<idTile> stations;
				stations.clear();

				for (int i = 0; i<3; i++) {
					stations.push_back((idTile)s[i]);
					qDebug() << "station " << i << " " << (idTile)s[i];
				}
				vector<Station*> it;
				for (unsigned i = 0; i < stations.size(); i++)
					it.push_back(gameWidget->getBoard()->getStation((idTile)stations[i]));

				players[goal->idPlayer]->setLine(goal->goalPlayer.line);
				players[goal->idPlayer]->setStopCard(goal->goalPlayer.stop.numCard);

				players[goal->idPlayer]->setItinerary(it);

				for(int i=0; i< players.size();i++){
					if(players.at(i)->getMyIdPlayer() == goal->idPlayer)
						ui->labelUser->setText(players.at(i)->getProfile().name.c_str());
				}
<<<<<<< HEAD
				newLocalGame->hide();
=======

				//QVector<Goal> * g = chooseCards->getGoal();
				//g = goal;
				//goal->goalPlayer
				//qDebug() << "goal line " << g->goalPlayer.line;
				chooseCards->update();

>>>>>>> 1175c7e25b9136740839bfec70d690fa3a468420
				chooseCards->show();
			}
			break;
		case GAMECREATENETWORK:
			{
				GameCreateNetwork *game = (GameCreateNetwork*)p;
				prodConsOutput->produce(new IWantPlayNetwork(currentProfile, game->numGame));
				descriptionPlayersNetwork->show();
				state = DESCRIPTIONPLAYERS;
				break;
			}
		case RESPONSEREFRESH:
			{
				ResponseRefresh *resp = (ResponseRefresh*)p;
				newNetworkGame->setServers(resp->gameNetwork);
				//newNetworkGame->show();
				//state = NEWGAMENET;
			}
			break;
		case RESPONSEPLAYERREFRESH:
			{
				ResponsePlayerRefresh *resp = (ResponsePlayerRefresh*)p;
				if (players.isEmpty())
					for (unsigned int i = 0;  i < resp->profiles.size(); i ++){
						Player *player = new Player();
						player->setProfile(resp->profiles[i]);
						players.push_back(player);
					}
			}
		case QUIT:
			{
				cout << "Quite" << endl;
			}
			break;
		default:
			cout << "ERROR packet read is undefined main thread " << p->idPack << endl;
			break;
	}
}
void MainWindow::validCards(){
    chooseCards->getGoal()->pop_front();
    for(int i=0; i< players.size();i++){
        if(players.at(i)->getMyIdPlayer() == chooseCards->getGoal()->at(0).idPlayer)
            ui->labelUser->setText(players.at(i)->getProfile().name.c_str());
    }
    if(chooseCards->getGoal()->size()!=0){
        chooseCards->update();
        chooseCards->show();
        QMessageBox::information(this, tr("Choisir cartes"), tr(ui->labelUser->text().toStdString().c_str())+tr(" doit choisir 2 cartes"));
        state = CARDS;
    }else{
        ui->widgetContent->hide();
        gameWidget->show();
        state = BOARD;
    }
}
void MainWindow::acceptNewGameLocal(int nb, QVector<Profile> p)
{
    char *envp[] = { NULL };
    char *argv[] = {"../Server/server", NULL};
    pid_t pid;
	isLocal = true;

#define FORK
#ifdef FORK
    if ((pid = fork()) == 0) //child process
        execve(argv[0], argv, envp);
#else
    if (false);
#endif
    else{
        sleep(1);
        if (connectionReseau()) {
            indexPlayerSend = 0;
            profilesToPlay = p;
            //gameWidget->getBoard()->initEmpty();
            qDebug() << "Create game";
            prodConsOutput->produce(new CreateGame(nb));
            qDebug() << "send first profil";
            if (profilesToPlay.front().type > 0){//if Computer -> fork()
                cout << "CREATION COMPUTER" << endl;
                char *envp[] = { NULL };
                char *argv[] = { (char*)("../Computer/applicationComputer"),
                                 (char*)profilesToPlay.front().name.c_str(),
                                 (char*)QString::number(profilesToPlay.front().avatar).toStdString().c_str(),
                                 (char*)QString::number(profilesToPlay.front().type).toStdString().c_str(),
                                 NULL};
                pid_t pid;
                if ((pid = fork()) == 0) //child process
                    execve(argv[0], argv, envp);
            }else
                prodConsOutput->produce(new IWantPlay(profilesToPlay.front()));
        }
        else {
            QMessageBox::critical(this, tr("Erreur réseau"), tr("Impossible de se connecter au server"));

            return;
<<<<<<< HEAD
		}
	}
=======
        }
    }
    newLocalGame->hide();
    chooseCards->show();
    state = CARDS;
>>>>>>> 1175c7e25b9136740839bfec70d690fa3a468420
}
bool MainWindow::connectionReseau(QString iP)
{
    struct sockaddr_in serv_addr;
    struct hostent *server = NULL;
    int portno = 8080;
    int sockfd;
    struct timeval tv;
    int flags;
    int result;
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
    bzero((char *) &serv_addr, sizeof(serv_addr)); //reset addr
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    //flags = fcntl(sockfd, F_GETFL,0);
    //fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
    //Adress by IP
    serv_addr.sin_addr.s_addr = inet_addr(iP.toStdString().c_str()); //244
    //bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    cout << "start to connect to the socket " << sockfd << endl;
    tv.tv_sec = 60;
    tv.tv_usec = 0;
    int MaxTries=0;
    while(MaxTries < 5 && (result = ::connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))) == -1)
    {
        sleep(1);
        cout << "MaxTries = " << MaxTries << endl;
        MaxTries++;
    }
    cout << "RESULT = "<< result << endl;
    if (result==-1){
        cout << "deconnected" << endl;
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
    profilMenu->showCreateButton();
    profilMenu->clear();
    profilMenu->show();
    state = PROFILS;
}
void MainWindow::acceptLoadGame(){
    loadSaveGame->hide();
    gameWidget->show();
    //boardWidget->show();
    state = BOARD;
}
void MainWindow::deleteSaveGame(){
    loadSaveGame->show();
    state = LOADGAME;
}
void MainWindow::saveGame(){
    if(state==BOARD){
        gameWidget->hide();
        //boardWidget->hide();
    }
    loadSaveGame->show();
    state = LOADGAME;
}
void MainWindow::connectGameServer(){
	if (connectionReseau(newNetworkGame->getIpServer())) {
		isLocal = false;
		prodConsOutput->produce(new RefreshGamesNetwork());
		newNetworkGame->connectedTotheServer();
	}
	else {
		QMessageBox::critical(this, tr("Erreur réseau"), tr("Impossible de se connecter au server"));
		return;
	}


}
void MainWindow::refreshGameServer(){
	/*newNetworkGame->show();
	state = NEWGAMENET;*/
	prodConsOutput->produce(new RefreshGamesNetwork());
}
void MainWindow::acceptNewGameNetwork(){
	qDebug() << "send IWHANTPLAYNETWORK";
	prodConsOutput->produce(new IWantPlayNetwork(currentProfile, newNetworkGame->getNum()));
	newNetworkGame->hide();
    descriptionPlayersNetwork->show();
    state = DESCRIPTIONPLAYERS;
}
void MainWindow::createNewGameNetwork(){
    newNetworkGame->hide();
    //prodConsOutput->produce(new CreateGameNetwork());
    createNetworkGame->show();
    state = CREATEGAME;
}
void MainWindow::playGameNetwork(){
    descriptionPlayersNetwork->hide();
    //boardWidget->show();
    gameWidget->show();
    state = BOARD;
}
void MainWindow::exitGameNetwork(){
    descriptionPlayersNetwork->hide();
    newNetworkGame->show();
    state = NEWGAMENET;
}
void MainWindow::createGameNetwork(){
    createNetworkGame->hide();
	qDebug() << "Create new network game";
	prodConsOutput->produce(new CreateGameNetwork((GameNetwork){createNetworkGame->getName().toStdString(), createNetworkGame->getNbrPlayers()}));
	//descriptionPlayersNetwork->show();
	//state = DESCRIPTIONPLAYERS;
}
void MainWindow::rejectGameNetwork(){
    createNetworkGame->hide();
    newNetworkGame->show();
    state = NEWGAMENET;
}
void MainWindow::startTravel(){
    /* boardWidget->show();
state = BOARD;
*/
}
void MainWindow::helpGame(){
    //boardWidget->hide();
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
