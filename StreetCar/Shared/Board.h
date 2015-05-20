#ifndef BOARD_H
#define BOARD_H

#include "Utils.h"

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
	Tile board[12][12];
	Point terminus[6][2];
	
	bool adjacentPossible(Tile a, Tile b);
}

#endif