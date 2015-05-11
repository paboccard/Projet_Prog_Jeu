#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>

namespace Ui {
class Controller;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);

    ~Controller();

private:
    initBoard(int w, int h);
    changePlayer();
    hasPlayed(Point p);
    iaPlay();
    isWon();

private:
    Ui::Controller *ui;
    int width, height;
    board gameBoard;
    mode gameMode;
    bool turn;
};

#endif // CONTROLLER_H


changeplayer(){
    !turn;
    if (mode == 1 && turn)
        Timer(IAPlayed());
    else if (mode == 2)
        Timer(IAPlayed());
    else if (!jeuFini)
        joueurPlay();
}
