#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include "../../Utils.h"
#include "../../Automata/solver.h"



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

private:
    void initBoard(int w, int h);
    void changePlayer();
    void hasPlayed(Point p);
    bool isWon();

private:
    Ui::Controller *ui;
    int width, height, delay;
    board gameBoard;
    mode gameMode;
    difficulty gameDifficulty;
    bool turn;
};

#endif // CONTROLLER_H
