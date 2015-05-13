#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include "../../Utils.h"
#include "../../Automata/solver.h"
#include <ConfigGameWindow.h>
#include <LoadWindow.h>
#include <QTimer>
#include "GaufreItem.h"
#include "Game.h"

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
    void slotConfig();
    void newGame();
    void save();
    void load();
    void undo();
    void redo();
    void slotLoadGame(Game g);

private:
    void initBoard(int w, int h);
    void changePlayer();
    void hasPlayed(Point p);
    bool isWon();
    void initImageBoard();

private:
    Ui::Controller *ui;
    ConfigGameWindow *configWindow;
    LoadWindow *loadWindow;
    std::vector<std::vector<GaufreItem* > > imageBoard;

    QGraphicsScene *scene;

    QPixmap *imageGaufre;
    QPixmap *imageGaufreSelect;
    QPixmap *imagePoison;
    QPixmap *imageEat;
    QPixmap *imageEatHaut;
    QPixmap *imageEatCote;
    QPixmap *imageEatCoin;

    Game game;
    int delay;
    std::vector<board> listBoardUndo;
    std::vector<board> listBoardRedo;

    QString playerToStr1();
    QString playerToStr2();
    QString difficultyToStr1();
    QString difficultyToStr2();
    QString difficultyToStr(difficulty diff);
};

#endif // CONTROLLER_H
