#include "Controller.h"
#include "ui_GameWindow.h"
#include "../../Utils.h"
#include <vector>

using namespace std;

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);

}

Controller::~Controller()
{

    delete ui;
}


void Controller::initBoard(int w, int h){
    this->width = w;
    this->height = h;
    gameBoard.clear();
    for (int i = 0; i < h; ++i) {
        gameBoard.insert(w);
    }
    this->displayBoard();

}

//changePlayer();
//hasPlayed(Point p);
//iaPlay();
//isWon();
