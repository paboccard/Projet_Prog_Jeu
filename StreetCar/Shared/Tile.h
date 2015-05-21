#ifndef TILE_H
#define TILE_H
#include "Square.h"
<<<<<<< HEAD
#include <iostream>
=======
#include "Utils.h"
>>>>>>> d5879a5788535e591473394e6154f14f448a363d
#include <vector>
#include <fstream>
#define IMPOSSIBLE false
#define OBLIGATORY true
#define NORTH 3
#define SOUTH 1
#define WEST  0
#define EAST  2

typedef struct {
    int s1,s2; // s1 <= s2 . 
} Rail;

<<<<<<< HEAD
class Tile:public Square {
 public:
	 
=======
class Tile : public Square {
 public:
>>>>>>> d5879a5788535e591473394e6154f14f448a363d
    bool tree;
    std::vector<Rail> ways;
    int turn;
    idTile type;
    int idPlayer;
    
    Tile();
	Tile(idTile t, int p); // type is t and idPlayer is p
    bool change(Tile t);
    friend std::ostream& operator << (std::ostream &f, Tile &t);
    friend std::istream& operator >> (std::istream &f, Tile &t);
};

#endif
