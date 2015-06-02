#include "Board.h"
#include "Tile.h"
#include "Station.h"
#include "Square.h"
#include "Utils.h"
#include <cstdlib>
#include <cstdlib>
#include <time.h>
#include <QDebug>
using namespace std;

Board::Board(int s, int nb){
	size = s;
	nbrStation = nb;
	board = NULL;
	stations = NULL;
}

void Board::initRandom() {
	srand (time(NULL));

	size = 14;
	nbrStation = 13;
	board = new Square**[size];
	stations = new Station*[size];
    // all tiles are empty
	for(int i = 0; i < size; i++) {
		board[i] = new Square*[size];
		for(int j = 0; j < size; j++)
			setSquare(new Tile(Empty, i, j));
	}

	//for (int i = 0; i < nbrStation; i ++)


	// wall on the board
	for(int i = 0; i < size; i ++){
		changeSquare(new Tile(Wall, 0, i));
		changeSquare(new Tile(Wall, size-1, i));
		changeSquare(new Tile(Wall, i, 0));
		changeSquare(new Tile(Wall, i, size-1));
	}

	// terminus on the board
	/*
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
	*/

    // stop on the board
    // Convention: de haut en bas, de gauche à droite A ---> B
    // Par rapport à l'image du google doc
	/*
	board[1][8] = new Station(StationA);
	board[2][4] = new Station(StationB);
	board[4][6] = new Station(StationC);
	board[4][11] =new Station(StationD);
	board[5][1] = new Station(StationE);
	board[6][9] = new Station(StationF);
	board[7][4] = new Station(StationG);
	board[8][12] =new Station(StationH);
	board[9][2] = new Station(StationI);
	board[9][7] = new Station(StationJ);
	board[11][9] =new Station(StationK);
	board[12][5] =new Station(StationL);*/

	stations[0] = new Station(StationC, 8, 1);
	stations[1] = new Station(StationB, 4, 2);
	stations[2] = new Station(StationK, 6, 4);
	stations[3] = new Station(StationD, 11, 4);
	stations[4] = new Station(StationA, 1, 5);
	stations[5] = new Station(StationL, 9, 6);
	stations[6] = new Station(StationI, 4, 7);
	stations[7] = new Station(StationE, 12, 8);
	stations[8] = new Station(StationH, 2, 9);
	stations[9] = new Station(StationM, 7, 9);
	stations[10] = new Station(StationF, 9, 11);
	stations[11] = new Station(StationG, 5, 12);

	for (int i = 0; i < nbrStation; i ++)
		changeSquare(stations[i]);
}

Board::~Board()
{
	free();
}

void Board::free()
{
	if (board == NULL)
		return;
	for (int i = 0; i < size; i ++) {
		for (int j = 0; j < size; j ++) {
			delete board[i][j];
		}
		delete[] board[i];
	}
	delete[] board;

	delete[] stations;
}

Square *Board::get(int row, int column)
{
	return board[row][column];
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

Station *Board::getStation(idTile id){
	return stations[id - StationA];
}

void Board::set(int row, int column, Square *t)
{
	t->setCoordinates((Point){row, column});
	board[row][column] = t;
}

int Board::getSize()
{
	return size;
}

void Board::setSize(int s, int nb)
{
	free();
	size = s;
	nbrStation = nb;
	board = new Square**[size];
	stations = new Station*[size];
	// all tiles are empty
	for(int i = 0; i < size; i++) {
		board[i] = new Square*[size];
		for(int j = 0; j < size; j++)
			setSquare(new Tile(Empty, i, j));
	}
}

int Board::getNbrStation()
{
	return nbrStation;
}

/*t1 can be replace by t2 ?*/
bool Board::changePossible(Tile *t1, Tile *t2){

	int row = t1->getCoordinates().x;
	int column = t1->getCoordinates().y;

	/*
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
	*/

	return t1->canChange(t2)
			&& adjacentPossible(t2, board[row-1][column], NORTH)
			&& adjacentPossible(t2, board[row+1][column], SOUTH)
			&& adjacentPossible(t2, board[row][column+1], EAST)
			&& adjacentPossible(t2, board[row][column-1], WEST);
}

bool Board::putPossible(Point p, Tile* t)
{
	return putPossible(p.x, p.y, t);
}

bool Board::putPossible(int row, int column, Tile* t)
{
	return 	board[row][column]->isEmpty()
			&& adjacentPossible(t, board[row-1][column], NORTH)
			&& adjacentPossible(t, board[row+1][column], SOUTH)
			&& adjacentPossible(t, board[row][column+1], EAST)
			&& adjacentPossible(t, board[row][column-1], WEST);
}

Station *Board::nextToStop(int row, int column)
{
	// case station A
	if ((((column + 1 == 1)||(column - 1 == 1)) && (row == 8)) || ((column == 1 ) && ((row + 1 == 8)||(row - 1 == 8))))
		return (Station*) board[1][8];
	else if ((((column + 1 == 2)||(column - 1 == 2)) && (row == 4)) || ((column == 2 ) && ((row + 1 == 4)||(row - 1 == 4))))
		return (Station*) board[2][4];
	else if ((((column + 1 == 3)||(column - 1 == 3)) && (row == 6)) || ((column == 3 ) && ((row + 1 == 6)||(row - 1 == 6))))
		return (Station*) board[4][6];
	else if ((((column + 1 == 4)||(column - 1 == 4)) && (row == 11)) || ((column == 4 ) && ((row + 1 == 11)||(row - 1 == 11))))
		return (Station*) board[4][11];
	else if ((((column + 1 == 5)||(column - 1 == 5)) && (row == 1)) || ((column == 5 ) && ((row + 1 == 1)||(row - 1 == 1))))
		return (Station*) board[5][1];
	else if ((((column + 1 == 6)||(column - 1 == 6)) && (row == 9)) || ((column == 6 ) && ((row + 1 == 9)||(row - 1 == 9))))
		return (Station*) board[6][9];
	else if ((((column + 1 == 7)||(column - 1 == 7)) && (row == 4)) || ((column == 7 ) && ((row + 1 == 4)||(row - 1 == 4))))
		return (Station*) board[7][4];
	else if ((((column + 1 == 8)||(column - 1 == 8)) && (row == 12)) || ((column == 8 ) && ((row + 1 == 12)||(row - 1 == 12))))
		return (Station*) board[8][12];
	else if ((((column + 1 == 9)||(column - 1 == 9)) && (row == 2)) || ((column == 9 ) && ((row + 1 == 9)||(row - 1 == 2))))
		return (Station*) board[9][2];
	else if ((((column + 1 == 9)||(column - 1 == 9)) && (row == 7)) || ((column == 9 ) && ((row + 1 == 7)||(row - 1 == 7))))
		return (Station*) board[9][7] ;
	else if ((((column + 1 == 11)||(column - 1 == 11)) && (row == 9)) || ((column == 11 ) && ((row + 1 == 9)||(row - 1 == 9))))
		return (Station*) board[11][9];
	else if ((((column + 1 == 12)||(column - 1 == 12)) && (row == 5)) || ((column == 12 ) && ((row + 1 == 5)||(row - 1 == 5))))
		return (Station*) board[12][5];
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
bool Board::adjacentPossible(Tile *a, Square *b, Orientation o) {
	bool res;

	if(b->isEmpty()){
		res = true;
	}
	else if(b->isStation() || b->isWall()){
		res = !a->getAccess(o);
	}
	else if(b->isTerminus()){
		res = a->getAccess(o);
	}
	else{ // a normal tile
		res = (a->getAccess(o) xor b->getAccess((Orientation)((o+2)%4)));
	}
	return res;
}

void Board::setSquare(Square *s)
{
	board[s->getCoordinates().x][s->getCoordinates().y] = s;
}

void Board::changeSquare(Square *s)
{
	delete board[s->getCoordinates().x][s->getCoordinates().y];
	setSquare(s);
}

/*
void Board::copy(Board copy){

	for(int i = 0 ; i < size; i++){
		for(int j = 0 ; j < size; j++){
			board[i][j] = copy.board[i][j];
		}
	}

	for(int i = 0 ; i < nbrStation ; i++){
		stations[i] = copy.stations[i];
	}
}
*/

void Board::printConsole()
{
	//Square board[BOARD_SIZE][BOARD_SIZE];
	//Point station[NBR_STATION];
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			switch (board[i][j]->getType()) {

                    case Straight :
                        cout << " STR ";
                        break;

                    case Curve :
                        cout << " CUR ";
                        break;

                    case DoubleCurves :
                        cout << " DBC ";
                        break;

                    case Intersect :
                        cout << " ITS ";
                        break;

                    case VCurve :
                        cout << " VCU ";
                        break;

                    case StraightLCurve :
                        cout << " SLU ";
                        break;

                    case StraightRCurve :
                        cout << " SRC ";
                        break;

                    case HStraightVCurve :
                        cout << " HSV ";
                        break;

                    case VStraightVCurve :
                        cout << " VSV ";
                        break;

                    case CrossCurves :
                        cout << " CRC ";
                        break;

                    case StraightLDoubleCurves :
                        cout << " SLDC";
                        break;

                    case StraightRDoubleCurves :
                        cout << " VRDC";
                        break;

                    case StationA :
                        cout << "  A  ";
                        break;

                    case StationB :
                        cout << "  B  ";
                        break;

                    case StationC :
                        cout << "  C  ";
                        break;

                    case StationD :
                        cout << "  D  ";
                        break;

                    case StationE :
                        cout << "  E  ";
                        break;

                    case StationF :
                        cout << "  F  ";
                        break;

                    case StationG :
                        cout << "  G  ";
                        break;

                    case StationH :
                        cout << "  H  ";
                        break;

                    case StationI :
                        cout << "  I  ";
                        break;

				   /* case StationJ :
                        cout << "  J  ";
                        break;
*/
                    case StationK :
                        cout << "  K  ";
                        break;

                    case StationL :
                        cout << "  L  ";
                        break;

                    case Wall :
                        cout << "  W  ";
                        break;

                    case Terminus1_1 :
                        cout << " T11 ";
                        break;

                    case Terminus1_2 :
                        cout << " T12 ";
                        break;

                    case Terminus1_3 :
                        cout << " T13 ";
                        break;

                    case Terminus1_4 :
                        cout << " T14 ";
                        break;

                    case Terminus2_1 :
                        cout << " T21 ";
                        break;

                    case Terminus2_2 :
                        cout << " T22 ";
                        break;

                    case Terminus2_3 :
                        cout << " T23 ";
                        break;

                    case Terminus2_4 :
                        cout << " T24 ";
                        break;

                    case Terminus3_1 :
                        cout << " T31 ";
                        break;

                    case Terminus3_2 :
                        cout << " T32 ";
                        break;

                    case Terminus3_3 :
                        cout << " T33 ";
                        break;

                    case Terminus3_4 :
                        cout << " T34 ";
                        break;

                    case Terminus4_1 :
                        cout << " T41 ";
                        break;

                    case Terminus4_2 :
                        cout << " T42 ";
                        break;

                    case Terminus4_3 :
                        cout << " T43 ";
                        break;

                    case Terminus4_4 :
                        cout << " T44 ";
                        break;

                    case Terminus5_1 :
                        cout << " T51 ";
                        break;

                    case Terminus5_2 :
                        cout << " T52 ";
                        break;

                    case Terminus5_3 :
                        cout << " T53 ";
                        break;

                    case Terminus5_4 :
                        cout << " T54 ";
                        break;

                    case Terminus6_1 :
                        cout << " T61 ";
                        break;

                    case Terminus6_2 :
                        cout << " T62 ";
                        break;

                    case Terminus6_3 :
                        cout << " T63 ";
                        break;

                    case Terminus6_4 :
                        cout << " T64 ";
                        break;

                    case Empty :
                        cout << "     ";
                        break;

                    case EmptyHand :
                        cout << " EMH ";
                        break;
                    default :
                        cout << " DFT ";
                        break;
            }
            cout << " | ";
        }
        cout << endl;
	}
}

void Board::read(istream &f)
{
	/*
	if (board == NULL)
		free();
	f >> size >> nbrStation;

	station = new Station[nbrStation];
	int nbSt = 0;

	for(int i = 0; i < size; i++) {
		board[i] = new Square*[size];
		for(int j = 0; j < size; j++) {
			int id;
			int turn;
			f >> id >> turn;
			board[i][j] = new Tile((idTile)id, -1, i, j);
			if (board[i][j]->isStation()) {
				station[nbSt] = board[i][j];
				nbSt ++;
			}
		}
	}
	*/
}
