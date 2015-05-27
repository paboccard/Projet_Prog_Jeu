#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainMenu.h"
#include "NewLocalGame.h"
#include "ProfilMenu.h"
#include "BoardWidget.h"
#include "OptionsWindow.h"
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

	public slots:
		void loadMenuNewGame();
		void loadMenuProfil();
		void acceptProfil(Profile p);
		void rejectProfil();
		void acceptNewGameLocal();
		void rejectNewGameLocal();
		void newProfilNewGameLocal();
		void loadMenuOptions();

	private:
		MainMenu *mainMenu;
		NewLocalGame *newLocalGame;
		ProfilMenu *profilMenu;
		BoardWidget *boardWidget;
		OptionsWindow *optionsWindow;
		Ui::MainWindow *ui;

		int state;

		Profile currentProfile;

		ServerOutputThread *threadOutput;
		ProdCons<Pack*> *prodConsInput;
		ProdCons<Pack*> *prodConsOutput;
};

#endif // MAINWINDOW_H
