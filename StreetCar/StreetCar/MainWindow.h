#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainMenu.h"
#include "NewLocalGame.h"
#include "ProfilMenu.h"
#include "BoardWidget.h"

#include "OptionsMenu.h"
#include "SoundOption.h"
#include "ServerOption.h"
#include "RulesOption.h"
#include "GraphicsOption.h"
#include "CreditsOption.h"
#include "LoadSaveGame.h"
#include "NewNetworkGame.h"
#include "DescriptionPlayersNetwork.h"
#include "CreateNetworkGame.h"


#include "ServerInputThread.h"
#include "ServerOutputThread.h"

#include "../Shared/Profile.h"
#include "../Shared/ProdCons.h"
#include "../Shared/CreateGame.h"

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		bool connectionReseau();

	public slots:
		void loadMenuNewGame();
		void loadMenuNewGameNetwork();
		void loadMenuloadSaveGame();
		void loadMenuProfil();
		void loadMenuOptions();

		void acceptNewGameLocal();
		void rejectNewGameLocal();
		void newProfilNewGameLocal();

		void connectGameServer();
		void refreshGameServer();
		void rejectNewGameNetwork();
		void createNewGameNetwork();
		void acceptNewGameNetwork();

		void playGameNetwork();
		void exitGameNetwork();

		void createGameNetwork();
		void rejectGameNetwork();

		void startTravel();
		void helpGame();
		void quitGame();

		void acceptLoadGame();
		void rejectedLoadSaveGame();
		void deleteSaveGame();
		void saveGame();

		void acceptProfil(Profile p);
		void rejectProfil();

		void loadSoundOption();
		void loadServerOption();
		void loadGraphicsOption();
		void loadRulesOption();
		void loadCreditsOption();
		void backMainMenu();

		void acceptSoundOption();
		void rejectSoundOption();

		void acceptGraphicsOption();
		void rejectGraphicsOption();

		void acceptServerOption();
		void rejectServerOption();

		void backMenuOption();

	private:
		MainMenu *mainMenu;
		NewLocalGame *newLocalGame;
		NewNetworkGame *newNetworkGame;
		DescriptionPlayersNetwork * descriptionPlayersNetwork;
		CreateNetworkGame *createNetworkGame;
		LoadSaveGame *loadSaveGame;
		ProfilMenu *profilMenu;
		BoardWidget *boardWidget;
		OptionsMenu *optionsMenu;
		SoundOption *soundOption;
		ServerOption *serverOption;
		RulesOption *rulesOption;
		GraphicsOption *graphicsOption;
		CreditsOption *creditsOption;
		Ui::MainWindow *ui;

		int state;
		int sockfd;

		Profile currentProfile;

		ServerOutputThread *threadOutput;
		ServerInputThread *threadInput;
		ProdCons<Pack*> *prodConsOutput;
};

#endif // MAINWINDOW_H
