#include "MainMenu.h"
#include "ui_MainMenu.h"
#include <QtGui>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_buttonContinue_clicked()
{
	emit newGame();
}

void MainMenu::on_buttonNewGame_clicked()
{
    emit newGame();
}

void MainMenu::on_buttonNewGameNetwork_clicked()
{
	emit newGameNetwork();
}

void MainMenu::on_buttonLoadSave_clicked()
{
	emit loadSaveGame();
}

void MainMenu::on_buttonProfil_clicked()
{
    emit profil();
}

void MainMenu::on_buttonOptions_clicked()
{
	emit options();
}

void MainMenu::on_buttonExit_clicked()
{
	emit exitGame();
}
