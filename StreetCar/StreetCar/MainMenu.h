#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_buttonNewGame_clicked();
	void on_buttonLoadSave_clicked();
    void on_buttonProfil_clicked();
	void on_buttonOptions_clicked();
	void on_buttonNewGameNetwork_clicked();

	void on_buttonExit_clicked();

	signals:
    void newGame();
	void newGameNetwork();
	void loadSaveGame();
    void profil();
	void options();
	void exitGame();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
