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
#include "ChooseCards.h"
#include "DeleteProfile.h"


#include "ServerInputThread.h"
#include "ServerOutputThread.h"

#include "../Shared/Profile.h"
#include "../Shared/Player.h"
#include "../Shared/ProdCons.h"
#include "../Shared/CreateGame.h"
//#include "../TestFrame/BoardView.h"

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
//#include <QSound>
//#include "qsound.h"
#include "../TestFrame/GameWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		bool connectionReseau(QString iP = "127.0.0.1");

    protected:
        void setFixedSize(int x, int y);
		void resizeEvent(QResizeEvent *e);

	public slots:
		void loadBoardGame();
		void loadMenuNewGame();
		void loadMenuNewGameNetwork();
		void loadMenuloadSaveGame();
		void loadMenuProfil();
		void loadMenuOptions();

		void acceptNewGameLocal(int nb, QVector<Profile> p);
		void newProfilNewGameLocal();
        void validCards();

		void connectGameServer();
		void refreshGameServer();
		void createNewGameNetwork();
		void acceptNewGameNetwork();

		void playGameNetwork();
		void exitGameNetwork();

		void createGameNetwork();
		void rejectGameNetwork();

		void startTravel();
		void helpGame();

		void acceptLoadGame();
		void deleteSaveGame();
		void saveGame();

		void acceptProfil(Profile p);
		void modifyProfil(Profile p);
		void rejectProfil();

		void loadSoundOption();
		void loadServerOption();
		void loadGraphicsOption();
		void loadRulesOption();
		void loadCreditsOption();
		void backMainMenu();

		void acceptOptionGraphics(bool fullScreen, int w, int h);
		void acceptOptionSound(bool musicOn);
		void acceptOptionServer();
		void backMenuOption();
		void receivePacket(Pack*);

		void chooseCardsGame();

		void delProfilNewGameLocal();
		void acceptDelProfile(Profile p);
		void rejectDelProfile();

		void exitGame();

	private:
		MainMenu *mainMenu;
		NewLocalGame *newLocalGame;
		NewNetworkGame *newNetworkGame;
		DescriptionPlayersNetwork * descriptionPlayersNetwork;
		CreateNetworkGame *createNetworkGame;
		LoadSaveGame *loadSaveGame;
		ProfilMenu *profilMenu;
		//BoardWidget *boardWidget;
		OptionsMenu *optionsMenu;
		SoundOption *soundOption;
		ServerOption *serverOption;
		RulesOption *rulesOption;
		GraphicsOption *graphicsOption;
		CreditsOption *creditsOption;
		ChooseCards *chooseCards;
		DeleteProfile *deleteProfile;
		Ui::MainWindow *ui;

        int widthWindow;
        int heightWindow;
		int widthDesktop;
		int heightDesktop;

		GameWidget *gameWidget;


		int state;
		int sockfd;
		int idPlayer;

//		QSound *sound;

		int indexPlayerSend;

		Profile currentProfile;
		vector<Profile> profiles;
        QVector<Profile> profilesToPlay;
		QVector<Player*> players;
		QVector<int> playersHere;

		ServerOutputThread *threadOutput;
		ServerInputThread *threadInput;
		ProdCons<Pack*> *prodConsOutput;
};

#endif // MAINWINDOW_H
