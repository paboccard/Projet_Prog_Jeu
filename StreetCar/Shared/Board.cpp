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
    board[0][2] = Tile(Terminus4_1,0, 0, 2);
    board[0][3] = Tile(Terminus4_2,0,0,3);
    board[0][6] = Tile(Terminus5_1,0,0,6);
    board[0][7] = Tile(Terminus5_2,0,0,7);
    board[0][10] = Tile(Terminus6_1,0,0,10);
    board[0][11] = Tile(Terminus6_2,0,0,11);

    board[2][0] = Tile(Terminus3_2,0,2,0);
    board[3][0] = Tile(Terminus3_1,0,3,0);
    board[6][0] = Tile(Terminus2_2,0,6,0);
    board[7][0] = Tile(Terminus2_1,0,7,0);
    board[10][0] = Tile(Terminus1_2,0,10,0);
    board[11][0] = Tile(Terminus1_1,0,11,0);

    board[13][2] =  Tile(Terminus6_4,0,13,2);
    board[13][3] =  Tile(Terminus6_3,0,13,3);
    board[13][6] =  Tile(Terminus4_4,0,13,6);
    board[13][7] =  Tile(Terminus4_3,0,13,7);
    board[13][10] = Tile(Terminus5_4,0,13,10);
    board[13][11] =  Tile(Terminus5_3,0,13,11);

    board[2][13] = Tile(Terminus2_3,0,2,13);
    board[3][13] = Tile(Terminus2_4,0,3,13);
    board[6][13] = Tile(Terminus1_3,0,6,13);
    board[7][13] = Tile(Terminus1_4,0,7,13);
    board[10][13] = Tile(Terminus3_3,0,10,13);
    board[11][13] = Tile(Terminus3_4,0,11,13);

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

    station[0] = (Point){8,1};
    station[1] = (Point){4,2};
    station[2] = (Point){6,4};
    station[3] = (Point){11,4};
    station[4] = (Point){1,5};
    station[5] = (Point){9,6};
    station[6] = (Point){4,7};
    station[7] = (Point){12,8};
    station[8] = (Point){2,9};
    station[9] = (Point){7,9};
    station[10] = (Point){9,11};
    station[11] = (Point){5,12};

}

Square Board::get(int line, int row)
{
    return board[line][row];
}
Square* Board::getPointer(int line, int row)
{
    return &board[line][row];
}

void Board::whichTerminus(int line, Point term[2][2]){

    switch(line){
    case 1:
	term[0][0] = (Point){0,10};
	term[0][1] = (Point){0,11};
	term[1][0] = (Point){13,6};
	term[1][1] = (Point){13,7};
	break;
    case 2:
	term[0][0] = (Point){0,6};
	term[0][1] = (Point){0,7};
	term[1][0] = (Point){13,2};
	term[1][1] = (Point){13,3};
	break;
    case 3:
	term[0][0] = (Point){0,2};
	term[0][1] = (Point){0,3};
	term[1][0] = (Point){13,10};
	term[1][1] = (Point){13,11};
	break;
    case 4:
	term[0][0] = (Point){2,0};
	term[0][1] = (Point){3,0};
	term[1][0] = (Point){6,13};
	term[1][1] = (Point){7,13};
	break;
    case 5:
	term[0][0] = (Point){6,0};
	term[0][1] = (Point){7,0};
	term[1][0] = (Point){10,13};
	term[1][1] = (Point){11,13};
	break;
    case 6:
	term[0][0] = (Point){10,0};
	term[0][1] = (Point){11,0};
	term[1][0] = (Point){2,13};
	term[1][1] = (Point){3,13};
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
	t.coordinates = {line, row};
    board[line][row] = t;
	//board[line][row].type = t.type;
}

/*t1 can be replace by t2 ?*/
bool Board::changePossible(Tile t1, Tile t2){
	
	int row = t1.coordinates.x;
	int line = t1.coordinates.y;
	
	bool search = true;
	bool search2 ;
	unsigned int j;
	unsigned int i = 0;
	while(search && i != t1.ways.size() ){
		j = 0;
		search2 = false;
		while(!search2 && j != t2.ways.size() ){
			
			search2 = ((t1.ways[i].s1 == t2.ways[j].s1) && (t1.ways[i].s2 == t2.ways[j].s2));
			j++;
		}
		i++;
		search = search2;
	}
	
	return adjacentNorthPossible(t2, board[line-1][row])
		&& adjacentSouthPossible(t2, board[line+1][row])
		&& adjacentEastPossible(t2, board[line][row+1])
		&& adjacentWestPossible(t2, board[line][row-1])
		&& search;
}


bool Board::putPossible(int line, int row, Tile t)
{
    return 	board[line][row].isEmpty()
	&& adjacentNorthPossible(t, board[line-1][row])
	&& adjacentSouthPossible(t, board[line+1][row])
	&& adjacentEastPossible(t, board[line][row+1])
	&& adjacentWestPossible(t, board[line][row-1]);
}

Stop* Board::nextToStop(int line, int row)
{
    // case station A
    if ((((line + 1 == 1)||(line - 1 == 1)) && (row == 8)) || ((line == 1 ) && ((row + 1 == 8)||(row - 1 == 8))))
        return (Stop*) &board[1][8];
    else if ((((line + 1 == 2)||(line - 1 == 2)) && (row == 4)) || ((line == 2 ) && ((row + 1 == 4)||(row - 1 == 4))))
        return (Stop*) &board[2][4];
    else if ((((line + 1 == 3)||(line - 1 == 3)) && (row == 6)) || ((line == 3 ) && ((row + 1 == 6)||(row - 1 == 6))))
        return (Stop*) &board[4][6];
    else if ((((line + 1 == 4)||(line - 1 == 4)) && (row == 11)) || ((line == 4 ) && ((row + 1 == 11)||(row - 1 == 11))))
        return (Stop*) &board[4][11];
    else if ((((line + 1 == 5)||(line - 1 == 5)) && (row == 1)) || ((line == 5 ) && ((row + 1 == 1)||(row - 1 == 1))))
        return (Stop*) &board[5][1];
    else if ((((line + 1 == 6)||(line - 1 == 6)) && (row == 9)) || ((line == 6 ) && ((row + 1 == 9)||(row - 1 == 9))))
        return (Stop*) &board[6][9];
    else if ((((line + 1 == 7)||(line - 1 == 7)) && (row == 4)) || ((line == 7 ) && ((row + 1 == 4)||(row - 1 == 4))))
        return (Stop*) &board[7][4];
    else if ((((line + 1 == 8)||(line - 1 == 8)) && (row == 12)) || ((line == 8 ) && ((row + 1 == 12)||(row - 1 == 12))))
        return (Stop*) &board[8][12];
    else if ((((line + 1 == 9)||(line - 1 == 9)) && (row == 2)) || ((line == 9 ) && ((row + 1 == 9)||(row - 1 == 2))))
        return (Stop*) &board[9][2];
    else if ((((line + 1 == 9)||(line - 1 == 9)) && (row == 7)) || ((line == 9 ) && ((row + 1 == 7)||(row - 1 == 7))))
        return (Stop*) &board[9][7] ;
    else if ((((line + 1 == 11)||(line - 1 == 11)) && (row == 9)) || ((line == 11 ) && ((row + 1 == 9)||(row - 1 == 9))))
        return (Stop*) &board[11][9];
    else if ((((line + 1 == 12)||(line - 1 == 12)) && (row == 5)) || ((line == 12 ) && ((row + 1 == 5)||(row - 1 == 5))))
        return (Stop*) &board[12][5];
    else
    return NULL;

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

void Board::copy(Board copy){
	
	for(int i = 0 ; i < 14 ; i++){
		for(int j = 0 ; j < 14 ; j++){
			board[i][j] = copy.board[i][j];
		}
	}
	
	for(int i = 0 ; i < 12 ; i++){
		station[i] = copy.station[i];
	}
}
