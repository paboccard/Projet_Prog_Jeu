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
