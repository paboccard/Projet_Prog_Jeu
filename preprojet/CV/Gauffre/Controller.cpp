#include "Controller.h"
#include "ui_GameWindow.h"
#include "stdlib.h"
#include <QGraphicsPixmapItem>
#include <QMessageBox>

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
    imagePoison = new QPixmap("../image/gaufrePoison.png");


    configWindow = new ConfigGameWindow(this);
    scene = new QGraphicsScene();

    initBoard(5, 4);
    scene->setSceneRect(0,0, 200, 200);
    ui->graphicsView->setScene(scene);


    connect(ui->newButton, SIGNAL (clicked()), this, SLOT (configure()));
    connect(ui->actionConfigurer_une_partie, SIGNAL(hovered()), this, SLOT(configure()));
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
    if (p.x != 0 || p.y != 0)
        for (int i = p.x; i < height; i ++)
            for (int j = p.y; j < gameBoard[i]; j ++)
                imageBoard[i][j]->setImage(imageGaufreSelect);
}

void Controller::gaufreHoverLeave(Point p)
{
    if (p.x != 0 || p.y != 0)
        for (int i = p.x; i < height; i ++)
            for (int j = p.y; j < gameBoard[i]; j ++)
                 imageBoard[i][j]->setImage(imageGaufre);

}

void Controller::gaufrePressed(Point p)
{
    if (p.x != 0 || p.y != 0)
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

    turn = rand() % 2;
    changePlayer();
}

void Controller::changePlayer() {
    turn = !turn;
    if ((gameMode == PvC && turn) || gameMode == CvC)
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

    if (p.x >= (int) gameBoard.size() || p.y >= gameBoard[p.x]){
        cout << "It's not possible to play here" << endl;
        return;
    }

    for (int i = p.x; i < height; i++) {
        for (int j = p.y; j < gameBoard[i]; j ++)
            imageBoard[i][j]->setImage(imageEat);

        if (gameBoard[i] > p.y)
            gameBoard[i] = p.y;
    }
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
    switch (gameMode) {
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
    switch(gameMode){
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
    hasPlayed(play(this->gameBoard, gameDifficulty));
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

