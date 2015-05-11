#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include <ConfigGameWindow.h>

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
    void configure();

private:
    initBoard(int w, int h);
    changePlayer();
    hasPlayed(Point p);
    iaPlay();
    isWon();

private:
    Ui::Controller *ui;
    ConfigGameWindow *configWindow;

    int width, height;
    board gameBoard;
    mode gameMode;
    bool turn;
};

#endif // CONTROLLER_H
