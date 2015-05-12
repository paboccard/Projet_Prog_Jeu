#ifndef GAME_H
#define GAME_H

#include "../../Utils.h"

typedef struct{
    std::string name;
    board gameBoard;
    int width, height;
    mode gameMode;
    difficulty diff1;
    difficulty diff2;
    bool turn;
}  Game;


#endif // GAME_H
