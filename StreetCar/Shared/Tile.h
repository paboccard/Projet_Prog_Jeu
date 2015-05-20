#ifndef TILE_H
#define TILE_H
#include "Square.h"
#include <vector>
#define IMPOSSIBLE false
#define OBLIGATORY true
#define NORTH 3
#define SOUTH 1
#define WEST  0
#define EST   2

typedef struct {
    int s1,s2; // s1 <= s2 . 
} Rail;

class Tile:public Square {
    bool tree;
    std::vector<Rail> ways;
    int turn;
    idTile type;
    int idPlayer;
    bool access [4];
    
 public:
    Tile();
    bool change(Tile t);
};

#endif
