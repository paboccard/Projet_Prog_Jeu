#include "Game.h"

using namespace std;

ostream& operator >> (ostream &f, Game &g){
    f >> g.name;
    f >> g.width >> g.height;
    for (int i = 0; i<g.height; i++){
        int j;
        f >> j;
        g.gameBoard.push_back(j);
    }
    f >> g.gameMode;
    if (g.gameMode == 1)
        f >> g.diff1;
    else if (g.gameMode == 2){
        f >> g.diff1 >> g.diff2;
    }
    f >> g.turn;

    return f;
}

istream& operator << (istream &f, Game &g){
    f << g.name << endl;
    f << g.width << g.height << endl;
    for (int i = 0; i<g.height; i++){
        f << g.gameBoard[i];
    }
    f << endl;
    f << g.gameMode << endl;
    if (g.gameMode == 1)
        f << g.diff1 << endl;
    else if (g.gameMode == 2){
        f << g.diff1 << g.diff2 << endl;
    }
    f << g.turn;

    return f;
}




