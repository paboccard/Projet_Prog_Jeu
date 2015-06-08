#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "ButtonMenu.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

public slots:
    void buttonContinue_clicked();
    void buttonNewGame_clicked();
    void buttonNewGameNetwork_clicked();
    void buttonLoadSave_clicked();
    void buttonProfile_clicked();
    void buttonOptions_clicked();
    void buttonQuit_clicked();

private slots:
    /*void on_buttonNewGame_clicked();
	void on_buttonLoadSave_clicked();
    void on_buttonProfil_clicked();
	void on_buttonOptions_clicked();
	void on_buttonNewGameNetwork_clicked();
	void on_buttonExit_clicked();
	void on_buttonContinue_clicked();

	void on_buttonContinue_pressed();

	void on_buttonContinue_released();

    //void on_buttonNewGame_pressed();

    //void on_buttonNewGame_released();

    void on_buttonNewGameNetwork_pressed();

    void on_buttonNewGameNetwork_released();*/

signals:
	void continueGame();
    void newGame();
	void newGameNetwork();
	void loadSaveGame();
    void profil();
	void options();
	void exitGame();

private:
    Ui::MainMenu *ui;
    ButtonMenu *buttonContinue;
    ButtonMenu *buttonNewGame;
    ButtonMenu *buttonNewGameNetwork;
    ButtonMenu *buttonLoadSave;
    ButtonMenu *buttonProfile;
    ButtonMenu *buttonOptions;
    ButtonMenu *buttonQuit;
};

#endif // MAINMENU_H
