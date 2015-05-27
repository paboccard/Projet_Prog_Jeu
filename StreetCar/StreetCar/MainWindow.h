#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainMenu.h"
#include "NewLocalGame.h"
#include "ProfilMenu.h"
#include "BoardWidget.h"

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
		void acceptProfil();
		void rejectProfil();
		void acceptNewGameLocal();
		void rejectNewGameLocal();
		void newProfilNewGameLocal();

	private:
		MainMenu *mainMenu;
		NewLocalGame *newLocalGame;
		ProfilMenu *profilMenu;
		BoardWidget *boardWidget;
		Ui::MainWindow *ui;
		int state;
};

#endif // MAINWINDOW_H
