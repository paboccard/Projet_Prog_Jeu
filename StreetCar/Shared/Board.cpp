#include "Board.h"
#include "Tile.h"
#include "Stop.h"

using namespace std;

Board::Board(){
	
	// all tiles are empty
	for(int i=1; i<13; i++)
		for(int j=1; j<13; j++)
			board[i][j] = new Tile();
	
	// wall of the board
	for(int k=0; k<14; k++){
		board[0][k] = new Tile(idTile.Wall);
		board[13][k] = new Tile(idTile.Wall);
		board[k][0] = new Tile(idTile.Wall);
		board[k][13] = new Tile(idTile.Wall);
	}
	
	/*
	 A COMPLETER MODIFIER 
	 */
	terminus[0][0].x=9;
	terminus[0][0].y=0;
	terminus[0][1].x=5;
	terminus[0][1].y=11;

	terminus[1][0].x=1;
	terminus[1][0].y=11;
	terminus[1][1].x=5;
	terminus[1][1].y=0;

	terminus[2][0].x=1;
	terminus[2][0].y=0;
	terminus[2][1].x=9;
	terminus[2][1].y=11;

	terminus[3][0].x=0;
	terminus[3][0].y=1;
	terminus[3][1].x=11;
	terminus[3][1].y=5;

	terminus[4][0].x=0;
	terminus[4][0].y=5;
	terminus[4][1].x=11;
	terminus[4][1].y=9;

	terminus[5][0].x=0;
	terminus[5][0].y=9;
	terminus[5][1].x=11;
	terminus[5][1].y=1;
}

Square Board::get(int line, int row)
{
	return board[line][row];
}
  
void Board::set(int line, int row, Square sq)
{
	board[line][row] = sq;
}

bool Board::putPossible(int line, int row, Square t)
{
	return 	board[line][row].isEmpty()
			&& adjacentNorthPossible(t, board[line-1][row])
			&& adjacentSouthPossible(t, board[line+1][row])
			&& adjacentEastPossible(t, board[line][row+1])
			&& adjacentWestPossible(t, board[line][row-1]);
}

/*bool Board::connectedToTerminus(Tile t, int direction){
	
	bool res;
	
	switch direction {
		case NORTH:
			res = (t.coordinates.x == Terminus[0][0].x) || (t.coordinates.x == Terminus[1][1].x) || (t.coordinates.x == Terminus[2][0].x);
			res = res && (t.access[NORTH] == OBLIGATORY);
			break;
		case EAST:
			res = (t.coordinates.y == Terminus[3][1].y) || (t.coordinates.y == Terminus[4][1].y) || (t.coordinates.y == Terminus[5][0].y);
			res = res && (t.access[EAST] == OBLIGATORY);
			break;
		case WEST:
			res = (t.coordinates.y == Terminus[3][0].y) || (t.coordinates.y == Terminus[4][0].y) || (t.coordinates.y == Terminus[5][1].y);
			res = res && (t.access[WEST] == OBLIGATORY);
			break;
		case SOUTH:
			res = (t.coordinates.x == Terminus[0][1].x) || (t.coordinates.x == Terminus[1][0].x) || (t.coordinates.x == Terminus[2][1].x);
			res = res && (t.access[SOUTH] == OBLIGATORY);
			break;
		default:
			cout << "FATAL ERROR: File Board.cpp function connectedToTerminus: direction unknown" << endl;
			res = false;
			break;
	}
}*/

/*We want play tile a
 * a
 * --
 * b
 * 
 * if b is an empty tile return true
 * else if b is a tile not empty, or a stop, we verify the connections with a.access[NORTH] and b.access[SOUTH] 
 */
bool Board::adjacentNorthPossible(Tile a, Square b){
	
	bool res;
	
	if(b.isEmpty()){
		res = true;
	}
	else if(b.isStation() || b.isWall()){
		res = !a.access[NORTH];
	}
	else if(b.isTerminus()){
		res = a.access[NORTH];
	}
	else{ // a normal tile
		res = (a.access[NORTH] xor b.access[SOUTH])
	}
}

bool Board::adjacentSouthPossible(Tile a, Square b){
	
	bool res;
	
	if(b.isEmpty()){
		res = true;
	}
	else if(b.isStation() || b.isWall()){
		res = !a.access[SOUTH];
	}
	else if(b.isTerminus()){
		res = a.access[SOUTH];
	}
	else{ // a normal tile
		res = (a.access[SOUTH] xor b.access[NORTH])
	}
}

bool Board::adjacentEastPossible(Tile a, Square b){
	
	bool res;
	
	if(b.isEmpty()){
		res = true;
	}
	else if(b.isStation() || b.isWall()){
		res = !a.access[EAST];
	}
	else if(b.isTerminus()){
		res = a.access[EAST];
	}
	else{ // a normal tile
		res = (a.access[EAST] xor b.access[WEST])
	}
}

bool Board::adjacentWestPossible(Tile a, Square b){
	
	bool res;
	
	if(b.isEmpty()){
		res = true;
	}
	else if(b.isStation() || b.isWall()){
		res = !a.access[WEST];
	}
	else if(b.isTerminus()){
		res = a.access[WEST];
	}
	else{ // a normal tile
		res = (a.access[WEST] xor b.access[EAST])
	}
}