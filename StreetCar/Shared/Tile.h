#ifndef TILE_H
#define TILE_H
#include "Square.h"
#include <iostream>
#include "Utils.h"
#include <vector>
#include <fstream>
#define IMPOSSIBLE false
#define OBLIGATORY true

enum Orientation {
    WEST=0,
    SOUTH,
    EAST,
    NORTH
};

typedef struct {
    int s1,s2; // s1 <= s2 .
} Rail;

class Tile : public Square {
 public:
    bool tree;
    std::vector<Rail> ways;
    int turn;
    idTile type;
    int idPlayer;

    Tile(idTile t, int p); // type is t and idPlayer is p
    bool change(Tile t);
    friend std::ostream& operator << (std::ostream &f, Tile &t);
    friend std::istream& operator >> (std::istream &f, Tile &t);
};

#endif
