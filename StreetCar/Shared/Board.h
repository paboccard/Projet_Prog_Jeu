#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include "Tile.h"
#include "Stop.h"

using namespace std;

class Board
{
public:
	
	// GET/SET board
	Tile get(int line, int row);
	void set(int line, int row, Tile t);
	
	// GET/SET terminus
	Point get(int line, int access);
	void set(int line, int access);
	
	bool putPossible(int line, int row, Tile t);

private:
	Square board[14][14];
	Point terminus[6][2];

	bool adjacentNorthPossible(Tile a, Square b);
	bool adjacentSouthPossible(Tile a, Square b);
	bool adjacentEastPossible(Tile a, Square b);
	bool adjacentWestPossible(Tile a, Square b);
}

#endif