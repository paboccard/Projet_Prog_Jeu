#include "Board.h"
#include "Tile.h"
#include "Stop.h"
#include "Square.h"
#include "Utils.h"
using namespace std;

Board::Board(){
	
	// all tiles are empty
	for(int i=1; i<13; i++)
		for(int j=1; j<13; j++)
			board[i][j] = Tile(Empty,0);
	
	// wall on the board
	for(int k=0; k<14; k++){
		board[0][k] = Tile(Wall,0);
		board[13][k] = Tile(Wall,0);
		board[k][0] = Tile(Wall,0);
		board[k][13] = Tile(Wall,0);
	}
	
	// terminus on the board
	board[0][2] = Tile(Terminus4_1,0);
	board[0][3] = Tile(Terminus4_2,0);
	board[0][6] = Tile(Terminus5_1,0);
	board[0][7] = Tile(Terminus5_2,0);
	board[0][10] = Tile(Terminus6_1,0);
	board[0][11] = Tile(Terminus6_2,0);
	
	board[2][0] = Tile(Terminus3_2,0);
	board[3][0] = Tile(Terminus3_1,0);
	board[6][0] = Tile(Terminus2_2,0);
	board[7][0] = Tile(Terminus2_1,0);
	board[10][0] = Tile(Terminus1_2,0);
	board[11][0] = Tile(Terminus1_1,0);
	
	board[13][2] =  Tile(Terminus6_4,0);
	board[13][3] =  Tile(Terminus6_3,0);
	board[13][6] =  Tile(Terminus4_4,0);
	board[13][7] =  Tile(Terminus4_3,0);
	board[13][10] = Tile(Terminus5_4,0);
	board[13][11] =  Tile(Terminus5_3,0);
	
	board[2][13] = Tile(Terminus2_3,0);
	board[3][13] = Tile(Terminus2_4,0);
	board[6][13] = Tile(Terminus1_3,0);
	board[7][13] = Tile(Terminus1_4,0);
	board[10][13] = Tile(Terminus3_3,0);
	board[11][13] = Tile(Terminus3_4,0);

	// stop on the board
	// Convention: de haut en bas, de gauche à droite A ---> B
	// Par rapport à l'image du google doc
	board[1][8] = Stop(StationA);
	board[2][4] = Stop(StationB);
	board[4][6] = Stop(StationC);
	board[4][11] = Stop(StationD);
	board[5][1] = Stop(StationE);
	board[6][9] = Stop(StationF);
	board[7][4] = Stop(StationG);
	board[8][12] = Stop(StationH);
	board[9][2] = Stop(StationI);
	board[9][7] = Stop(StationJ);
	board[11][9] = Stop(StationK);
	board[12][5] = Stop(StationL);
	
	station[0] = {1,8};
	station[1] = {2,4};
	station[2] = {4,6};
	station[3] = {4,11};
	station[4] = {5,1};
	station[5] = {6,9};
	station[6] = {7,4};
	station[7] = {8,12};
	station[8] = {9,2};
	station[9] = {9,7};
	station[10] = {11,9};
	station[11] = {12,5};
	
}

Square Board::get(int line, int row)
{
	return board[line][row];
}

void Board::whichTerminus(int line, Point term[2][2]){
	
	switch(line){
		case 1:
			term[0][0] = {10,0};
			term[0][1] = {11,0};
			term[1][0] = {6,13};
			term[1][1] = {7,13};
			break;
		case 2:
			term[0][0] = {6,0};
			term[0][1] = {7,0};
			term[1][0] = {2,13};
			term[1][1] = {3,13};
			break;
		case 3:
			term[0][0] = {2,0};
			term[0][1] = {3,0};
			term[1][0] = {10,13};
			term[1][1] = {11,13};
			break;
		case 4:
			term[0][0] = {0,2};
			term[0][1] = {0,3};
			term[1][0] = {13,6};
			term[1][1] = {13,7};
			break;
		case 5:
			term[0][0] = {0,6};
			term[0][1] = {0,7};
			term[1][0] = {13,10};
			term[1][1] = {13,11};
			break;
		case 6:
			term[0][0] = {0,10};
			term[0][1] = {0,11};
			term[1][0] = {13,2};
			term[1][1] = {13,3};
			break;
		default:
			cout << "FATAL ERROR: Board.cpp function whichTerminus: line unknown" << endl;
			break;
	}
}

Point Board::get(int numStation){
	return station[numStation];
}
  
void Board::set(int line, int row, Tile t)
{
	board[line][row] = t;
}

bool Board::putPossible(int line, int row, Tile t)
{
	return 	board[line][row].isEmpty()
			&& adjacentNorthPossible(t, board[line-1][row])
			&& adjacentSouthPossible(t, board[line+1][row])
			&& adjacentEastPossible(t, board[line][row+1])
			&& adjacentWestPossible(t, board[line][row-1]);
}

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
		res = (a.access[NORTH] xor b.access[SOUTH]);
	}
	return res;
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
		res = (a.access[SOUTH] xor b.access[NORTH]);
	}
	return res;
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
		res = (a.access[EAST] xor b.access[WEST]);
	}
	return res;
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
		res = (a.access[WEST] xor b.access[EAST]);
	}
	return res;
}
