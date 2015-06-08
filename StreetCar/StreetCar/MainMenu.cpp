#include "MainMenu.h"
#include "ui_MainMenu.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <iostream>

using namespace std;

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

    ui->labelMenu->hide();
    QLabel* l = new QLabel();
    l = ui->labelMenu;

    buttonContinue = new ButtonMenu(l,"Continuer la partie", this);
    buttonContinue->setMinimumSize(50,0);
    connect(buttonContinue, SIGNAL(clicked()),this, SLOT(buttonContinue_clicked()));

    buttonNewGame = new ButtonMenu(l,"Nouveau jeu (local)", this);
    buttonNewGame->setMinimumSize(50,0);
    connect(buttonNewGame, SIGNAL(clicked()),this, SLOT(buttonNewGame_clicked()));

	buttonNewGameNetwork = new ButtonMenu(l,"Nouveau jeu (reseau)", this);
    buttonNewGameNetwork->setMinimumSize(50,0);
    connect(buttonNewGameNetwork, SIGNAL(clicked()),this, SLOT(buttonNewGameNetwork_clicked()));

    buttonLoadSave = new ButtonMenu(l,"Charger une partie", this);
    buttonLoadSave->setMinimumSize(50,0);
    connect(buttonLoadSave, SIGNAL(clicked()),this, SLOT(buttonLoadSave_clicked()));

    buttonProfile = new ButtonMenu(l,"Profil", this);
    buttonProfile->setMinimumSize(50,0);
    connect(buttonProfile, SIGNAL(clicked()),this, SLOT(buttonProfile_clicked()));

    buttonOptions = new ButtonMenu(l,"Options", this);
    buttonOptions->setMinimumSize(50,0);
    connect(buttonOptions, SIGNAL(clicked()),this, SLOT(buttonOptions_clicked()));

    buttonQuit = new ButtonMenu(l,"Quitter", this);
    buttonQuit->setMinimumSize(50,0);
    connect(buttonQuit, SIGNAL(clicked()),this, SLOT(buttonQuit_clicked()));

    ui->gridLayoutMenu->addWidget(buttonContinue,0,1);
    ui->gridLayoutMenu->addWidget(buttonNewGame,1,1);
    ui->gridLayoutMenu->addWidget(buttonNewGameNetwork,2,1);
    ui->gridLayoutMenu->addWidget(buttonLoadSave,3,1);
    ui->gridLayoutMenu->addWidget(buttonProfile,4,1);
    ui->gridLayoutMenu->addWidget(buttonOptions,5,1);
    ui->gridLayoutMenu->addWidget(buttonQuit,6,1);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::buttonContinue_clicked()
{
    emit continueGame();
}

void MainMenu::buttonNewGame_clicked(){
     emit newGame();
}

void MainMenu::buttonNewGameNetwork_clicked()
{
    emit newGameNetwork();
}

void MainMenu::buttonLoadSave_clicked()
{
    emit loadSaveGame();
}

void MainMenu::buttonProfile_clicked()
{
    emit profil();
}

void MainMenu::buttonOptions_clicked()
{
    emit options();
}

void MainMenu::buttonQuit_clicked()
{
    emit exitGame();
}
