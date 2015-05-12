#include "Controller.h"
#include "ui_GameWindow.h"
#include "stdlib.h"
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <fstream>
#include <QInputDialog>

using namespace std;

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);

    srand(time(NULL));

    delay = 1000;

    imageGaufre = new QPixmap("../image/gaufre.png");
    imageGaufreSelect = new QPixmap("../image/gaufreSelect.png");
    imageEat = new QPixmap("../image/gaufreEat.png");
    imageEatHaut = new QPixmap("../image/gaufreEatHaut.png");
    imageEatCote = new QPixmap("../image/gaufreEatCote.png");
    imageEatCoin = new QPixmap("../image/gaufreEatCoin.png");
    imagePoison = new QPixmap("../image/gaufrePoison.png");


    configWindow = new ConfigGameWindow(this);
    scene = new QGraphicsScene();

    game.gameMode = PvC;
    game.difficulty1 = Medium;
    initBoard(5, 4);

    scene->setSceneRect(0,0, 200, 200);
    ui->graphicsView->setScene(scene);

    connect(configWindow, SIGNAL(accepted()), this, SLOT(slotConfig()));
    connect(ui->newButton, SIGNAL (clicked()), this, SLOT(newGame()));
    connect(ui->configureAction, SIGNAL(triggered()), this, SLOT(configure()));
    connect(ui->saveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->loadAction, SIGNAL(triggered()), this, SLOT(load()));
    connect(ui->exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->undoAction, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->redoAction, SIGNAL(triggered()), this, SLOT(redo()));
}

Controller::~Controller()
{
    delete configWindow;
    delete ui;
}

void Controller::configure()
{
    configWindow->show();
}

void Controller::gaufreHoverEnter(Point p)
{
    if ((gameMode == PvC && !turn) || gameMode == PvP)
        if (p.x != 0 || p.y != 0)
            for (int i = p.x; i < height; i ++)
                for (int j = p.y; j < gameBoard[i]; j ++)
                    imageBoard[i][j]->setImage(imageGaufreSelect);
}

void Controller::gaufreHoverLeave(Point p)
{
    if ((gameMode == PvC && !turn) || gameMode == PvP)
        if (p.x != 0 || p.y != 0)
            for (int i = p.x; i < height; i ++)
                for (int j = p.y; j < gameBoard[i]; j ++)
                     imageBoard[i][j]->setImage(imageGaufre);

}

void Controller::gaufrePressed(Point p)
{
    if ((gameMode == PvC && !turn) || gameMode == PvP)
        if (p.x != 0 || p.y != 0)
            hasPlayed(p);
}

void Controller::slotConfig()
{
    cout << "config" << endl;
    game.gameMode = configWindow->getMode();
    if (game.gameMode == PvC || game.gameMode == CvC)
        gameDifficulty1 = configWindow->getDiff1();

    if (game.gameMode == CvC)
        gameDifficulty2 = configWindow->getDiff2();

    cout << "game mode : " << game.gameMode << endl;
    cout << "game diff1 : " << game.gameDifficulty1 << endl;
    cout << "game diff2 : " << game.gameDifficulty2 << endl;
    initBoard(configWindow->getWidth(), configWindow->getHeight());
}

void Controller::newGame()
{
    initBoard(game.width, game.height);
}

void Controller::undo()
{

}

void Controller::redo()
{

}

void Controller::initBoard(int w, int h){
    game.width = w;
    game.height = h;

    listBoard.clear();
    game.gameBoard.clear();
    for (int i = 0; i < imageBoard.size(); i ++)
    {
        for (int j = 0; j < imageBoard[i].size(); j ++)
        {
            scene->removeItem(imageBoard[i][j]);
            delete imageBoard[i][j];
        }
        imageBoard[i].clear();
    }

    imageBoard.clear();

    for (int i = 0; i < h; i++) {
        game.gameBoard.push_back(w);
        imageBoard.push_back(vector<GaufreItem*>());

        for (int j = 0; j < w; j ++) {
            GaufreItem *item = new GaufreItem((Point){i, j});
            imageBoard[i].push_back(item);
            item->setImage(imageGaufre);
            item->setPos(j*imageGaufre->width(), i*imageGaufre->height());
            connect(item, SIGNAL(hoverEnter(Point)), this, SLOT(gaufreHoverEnter(Point)));
            connect(item, SIGNAL(hoverLeave(Point)), this, SLOT(gaufreHoverLeave(Point)));
            connect(item, SIGNAL(pressed(Point)), this, SLOT(gaufrePressed(Point)));
            scene->addItem(item);

        }
    }

    listBoard.push_back(game.gameBoard);

    imageBoard[0][0]->setImage(imagePoison);

    turn = rand() % 2;
    changePlayer();
}

void Controller::changePlayer() {
    turn = !turn;
    if ((game.gameMode == PvC && turn) || game.gameMode == CvC)
        QTimer::singleShot(delay, this, SLOT(iaPlay()));

    if(!turn){
         ui->playerLabel1->setText("<b>" + playerToStr1());
         ui->playerLabel2->setText(playerToStr2());
    }else{
        ui->playerLabel1->setText(playerToStr1());
        ui->playerLabel2->setText("<b>" + playerToStr2());
    }

}


void Controller::hasPlayed(Point p) {
    cout << "A player play in (" << p.x << " , " << p.y << ")" << endl;

    if (p.x >= (int) game.gameBoard.size() || p.y >= game.gameBoard[p.x]){
        cout << "It's not possible to play here" << endl;
        return;
    }

    for (int i = p.x; i < height; i++) {
        for (int j = p.y; j < width; j ++){
            if (i == 0 && j == p.y)
                imageBoard[i][j]->setImage(imageEatCote);
            else if (j == 0 && i == p.x)
                imageBoard[i][j]->setImage(imageEatHaut);
            else if (i == p.x && j == p.y)
                imageBoard[i][j]->setImage(imageEatCoin);
            else if (i == 0)
                imageBoard[i][j]->setImage(imageEat);
            else if (j == 0)
                imageBoard[i][j]->setImage(imageEat);
            else if (i == p.x && gameBoard[i-1]>j)
                imageBoard[i][j]->setImage(imageEatHaut);
            else if (j == p.y && gameBoard[i]>=p.y)
                imageBoard[i][j]->setImage(imageEatCote);
            else
                imageBoard[i][j]->setImage(imageEat);
        }

        if (game.gameBoard[i] > p.y)
            game.gameBoard[i] = p.y;
    }

    listBoard.push_back(game.gameBoard);

    if (!isWon())
        changePlayer();
    else{
        if(turn)
            QMessageBox::information(this, "Gagnant", playerToStr2() + " a gagné!");
        else
            QMessageBox::information(this, "Gagnant", playerToStr1() + " a gagné!");
    }
}

QString Controller::playerToStr1()
{
    switch (game.gameMode) {
    case PvP:
        return tr("Joueur 1");
        break;
    case PvC:
        return tr("Joueur");
        break;
    default:
        return tr("Ordinateur 1");
        break;
    }
}

QString Controller::playerToStr2()
{
    switch(game.gameMode){
    case PvP:
        return tr("Joueur 2");
        break;
    case PvC:
        return tr("Ordinateur");
        break;
    default:
        return tr("Ordinateur 2");
        break;
    }
}

void Controller::iaPlay(){

    if (gameMode == PvC || gameMode == CvC && !turn) {
        cout << "IA play in difficulty " << gameDifficulty1 << endl;
        hasPlayed(play(game.gameBoard, game.gameDifficulty1));
    }
    else {
        cout << "IA play in difficulty " << game.gameDifficulty2 << endl;
        hasPlayed(play(game.gameBoard, game.gameDifficulty2));
    }
}

bool Controller::isWon(){
    bool won;

    if (this->gameBoard[0]==1 && this->gameBoard[1] == 0) {
        won = true;
        cout << "won" << endl;
    }
    else
        won = false;

    return won;
}

void Controller::save(){
    vector<Game> listeGame;
    Game g;
    bool ajout = true;
    QString nameGame = QInputDialog::getText(this, tr("Sauvegarde de la partie"), tr("Nom de la partie : "));
    if (!nameGame.isEmpty()){

        fstream file("save.txt", ios::in | ios::out);
        while (file >> g){
            listeGame.push_back(g);
        }
        for (int i = 0; i<listeGame.size(); i++){
            if (listeGame[i].name == nameGame){
                QMessageBox::critical(this, tr("Erreur"), tr("Nom de la partie déjà existant !"));
                ajout = false;
            }
        }
        if (ajout){
            game.name = nameGame;
            file << game << endl;
        }
    }
}


