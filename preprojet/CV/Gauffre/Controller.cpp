#include "Controller.h"
#include "ui_GameWindow.h"
#include "stdlib.h"

using namespace std;

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);

    configWindow = new ConfigGameWindow(this);

    connect(ui->newButton, SIGNAL (clicked()), this, SLOT (configure()));
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

void Controller::initBoard(int w, int h){
    srand(time(NULL));
    this->width = w;
    this->height = h;
    this->gameBoard.clear();
    for (int i = 0; i < h; i++) {
        gameBoard.insert(w);
    }
    this->turn = rand() % 2;
    this->displayBoard();
    changePlayer();


}

void Controller::changePlayer(){
    !turn;
    if ((mode == PvC && turn) || mode == CvC)
        QTimer::singleShot(delay, this, SLOT(iaPlay()));
    else
        playerPlay();
}

void Controller::hasPlayed(Point p){
    for (int i = 0; i < h; i++) {
        if (i >= p.x)
            if (gameBoard[i] > p.y)
                this->gameBoard[i] = p.y;
    }
    changePlayer();
}

void Controller::iaPlay(){
    hasPlayed(play(this->gameBoard, gameDifficulty));
}
/*
isWon(){

}
*/
