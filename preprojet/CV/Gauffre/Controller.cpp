#include "Controller.h"
#include "ui_GameWindow.h"
#include "stdlib.h"
#include <QGraphicsPixmapItem>

using namespace std;

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controller)
{
    ui->setupUi(this);
    srand(time(NULL));

    delay = 3000;

    imageGaufre = new QPixmap("../image/gaufre.png");
    imageGaufreSelect = new QPixmap("../image/gaufreSelect.png");
    imageEat = new QPixmap("../image/gaufreEat.png");
    imagePoison = new QPixmap("../image/poison.png");


    configWindow = new ConfigGameWindow(this);
    scene = new QGraphicsScene();

    initBoard(5, 4);

    scene->setSceneRect(0, 0, 640, 480);
    ui->graphicsView->setScene(scene);


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
    imageBoard.clear();

    for (int i = 0; i < h; i++) {
        gameBoard.push_back(w);
        imageBoard.push_back(QVector<GaufreItem*>());

        for (int j = 0; j < w; j ++) {
            imageBoard[i].push_back(new GaufreItem(j, i));
            imageBoard[i][j]->setImage(imageGaufre);
            scene->addItem(imageBoard[i][j]);
        }
    }

    imageBoard[0][0]->setImage(imagePoison);

    this->turn = rand() % 2;
    this->displayBoard();
    changePlayer();
}

void Controller::changePlayer() {
    turn = !turn;
    if ((gameMode == PvC && turn) || gameMode == CvC)
        QTimer::singleShot(delay, this, SLOT(iaPlay()));


}

void Controller::hasPlayed(Point p) {
    for (int i = 0; i < height; i++) {
        if (i >= p.x)
            if (gameBoard[i] > p.y)
                this->gameBoard[i] = p.y;
    }
    changePlayer();
}

void Controller::displayBoard()
{

}

void Controller::iaPlay(){
    hasPlayed(play(this->gameBoard, gameDifficulty));
}
/*
isWon(){

}
*/
