#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include "../../Utils.h"
#include "../../Automata/solver.h"
#include <ConfigGameWindow.h>
#include <QTimer>
#include "GaufreItem.h"

namespace Ui {
class Controller;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);

    ~Controller();

private slots:
    void iaPlay();
    void configure();
    void gaufreHoverEnter(Point p);
    void gaufreHoverLeave(Point p);
    void gaufrePressed(Point p);

private:
    void initBoard(int w, int h);
    void changePlayer();
    void hasPlayed(Point p);
    bool isWon();
    void openDialogue();

private:
    Ui::Controller *ui;
    ConfigGameWindow *configWindow;
    QVector<QVector<GaufreItem* > > imageBoard;

    QGraphicsScene *scene;

    QPixmap *imageGaufre;
    QPixmap *imageGaufreSelect;
    QPixmap *imagePoison;
    QPixmap *imageEat;
    QPixmap *imageEatHaut;
    QPixmap *imageEatCote;
    QPixmap *imageEatCoin;



    int width, height, delay;

    board gameBoard;
    mode gameMode;
    difficulty gameDifficulty;
    bool turn;
    QString playerToStr1();
    QString playerToStr2();
};

#endif // CONTROLLER_H
