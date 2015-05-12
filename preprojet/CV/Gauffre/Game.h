#ifndef GAME_H
#define GAME_H

#include "../../Utils.h"
#include <fstream>

typedef struct{
    std::string name;
    board gameBoard;
    int width, height;
    mode gameMode;
    difficulty diff1;
    difficulty diff2;
    bool turn;
}  Game;

std::ostream& operator>>(std::ostream &f, Game &g);
std::istream& operator<<(std::istream &f, Game &g);


#endif // GAME_H
