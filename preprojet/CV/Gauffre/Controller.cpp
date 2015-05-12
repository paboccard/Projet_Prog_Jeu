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
    scene->setSceneRect(0,0, 200, 200);
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

void Controller::gaufreHoverEnter(Point p)
{
    for (unsigned int i = p.x; i < gameBoard.size(); i ++)
        for (int j = p.y; j < gameBoard[i]; j ++)
            imageBoard[i][j]->setImage(imageGaufreSelect);
}

void Controller::gaufreHoverLeave(Point p)
{
    for (unsigned int i = p.x; i < gameBoard.size(); i ++)
        for (int j = p.y; j < gameBoard[i]; j ++)
             imageBoard[i][j]->setImage(imageGaufre);

}

void Controller::gaufrePressed(Point p)
{
    hasPlayed(p);
}

void Controller::initBoard(int w, int h){
    width = w;
    height = h;

    gameBoard.clear();
    imageBoard.clear();

    for (int i = 0; i < h; i++) {
        gameBoard.push_back(w);
        imageBoard.push_back(QVector<GaufreItem*>());

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
    cout << "A player play in (" << p.x << " , " << p.y << ")" << endl;

    if (p.x >= gameBoard.size() || p.y >= gameBoard[p.x])
    {
        cout << "It's not possible to play here" << endl;
        return;
    }

    for (unsigned int i = p.x; i < gameBoard.size(); i++) {
        gameBoard[i] = p.y;
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
