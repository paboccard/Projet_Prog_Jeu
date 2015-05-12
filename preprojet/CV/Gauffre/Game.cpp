#include "Game.h"

using namespace std;

istream& operator >> (istream &f, Game &g){
    f >> g.name;
    f >> g.width >> g.height;
    for (int i = 0; i<g.height; i++){
        int j;
        f >> j;
        g.gameBoard.push_back(j);
    }
    int i;
    f >> i;
    g.gameMode = (mode)i;
    if (g.gameMode == 1) {
        f >> i;
        g.diff1 = (difficulty)i;
    }
    else if (g.gameMode == 2){
        f >> i;
        g.diff1 = (difficulty)i;
        f >> i;
        g.diff2 = (difficulty)i;
    }
    f >> g.turn;

    return f;
}

ostream& operator << (ostream &f, Game &g){
    f << g.name << endl;
    f << g.width << g.height << endl;
    for (int i = 0; i<g.height; i++){
        f << g.gameBoard[i];
    }
    f << endl;
    f << (int)g.gameMode << endl;
    if (g.gameMode == 1)
        f << (int)g.diff1 << endl;
    else if (g.gameMode == 2){
        f << (int)g.diff1 << (int)g.diff2 << endl;
    }
    f << g.turn << endl;

    return f;
}




