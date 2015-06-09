#include "Board.h"
#include "Tile.h"
#include "Station.h"
#include "Square.h"
#include "Utils.h"
#include <cstdlib>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

Board::Board(int s, int nb){
	size = s;
	nbrStation = nb;
	board = NULL;
	stations = NULL;
}

void Board::initEmpty() {
	setSize(14,12);
	//for (int i = 0; i < nbrStation; i ++)

	// wall on the board
	for(int i = 0; i < size-1; i++){
		changeSquare(new Tile(Wall, 0, i));
		changeSquare(new Tile(Wall, size-1, i+1));
		changeSquare(new Tile(Wall, i+1, 0));
		changeSquare(new Tile(Wall, i, size-1));
	}


	for (int i = 1; i<getSize()-1; i++)
		for (int j = 1; j<getSize()-1; j++)
			changeSquare(new Tile(Empty,i,j));

	// terminus on the board


	changeSquare(new Tile(Terminus4_1,2,0));
	changeSquare(new Tile(Terminus4_2,3,0));
	changeSquare(new Tile(Terminus5_1,6,0));
	changeSquare(new Tile(Terminus5_2,7,0));
	changeSquare(new Tile(Terminus6_1,10,0));
	changeSquare(new Tile(Terminus6_2,11,0));

	changeSquare(new Tile(Terminus3_2,0,2));
	changeSquare(new Tile(Terminus3_1,0,3));
	changeSquare(new Tile(Terminus2_2,0,6));
	changeSquare(new Tile(Terminus2_1,0,7));
	changeSquare(new Tile(Terminus1_2,0,10));
	changeSquare(new Tile(Terminus1_1,0,11));

	changeSquare(new Tile(Terminus6_4,2,13));
	changeSquare(new Tile(Terminus6_3,3,13));
	changeSquare(new Tile(Terminus4_4,6,13));
	changeSquare(new Tile(Terminus4_3,7,13));
	changeSquare(new Tile(Terminus5_4,10,13));
	changeSquare(new Tile(Terminus5_3,11,13));

	changeSquare(new Tile(Terminus2_3,13,2));
	changeSquare(new Tile(Terminus2_4,13,3));
	changeSquare(new Tile(Terminus1_3,13,6));
	changeSquare(new Tile(Terminus1_4,13,7));
	changeSquare(new Tile(Terminus3_3,13,10));
	changeSquare(new Tile(Terminus3_4,13,11));


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

	stations[0] = new Station(StationA, 1, 5);
	stations[1] = new Station(StationB, 4, 2);
	stations[2] = new Station(StationC, 8, 1);
	stations[3] = new Station(StationD, 11, 4);
	stations[4] = new Station(StationE, 12, 8);
	stations[5] = new Station(StationF, 9, 11);
	stations[6] = new Station(StationG, 5, 12);
	stations[7] = new Station(StationH, 2, 9);
	stations[8] = new Station(StationI, 4, 7);
	stations[9] = new Station(StationK, 6, 4);
	stations[10] = new Station(StationL, 9, 6);
	stations[11] = new Station(StationM, 7, 9);

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

Square *Board::get(Point p)
{
	return get(p.x, p.y);
}

Square *Board::get(int row, int column)
{
	if (row < 0 || column < 0 || row > size-1 || column > size-1) {
		cout << "ERROR, impossible to get " << row << " " << column << " in board of size " << size << endl;
		return NULL;
	}
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
	// 	cout << "get station id : " << id <<  " " << id - StationA << endl;
	return stations[id - StationA];
}

int Board::getNumberStroke()
{
	return strokePlay.size();
}

Tile Board::getLastTile()
{
	return *(strokePlay.back().	pointerTileBoard);
}

void Board::set(int row, int column, Square *t)
{
	//t->setCoordinates((Point){row, column});
	*board[row][column] = *t;
}

void Board::set(int row, int column, Tile *t)
{
	//t->setCoordinates((Point){row, column});
	*(Tile*)board[row][column] = *t;
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

	return t1->canChange(t2)
			&& adjacentPossible(t2, board[row-1][column], WEST)
			&& adjacentPossible(t2, board[row+1][column], EAST)
			&& adjacentPossible(t2, board[row][column+1], SOUTH)
			&& adjacentPossible(t2, board[row][column-1], NORTH);
}

bool Board::changePossible(Tile *t)
{
	return changePossible((Tile*)get(t->getCoordinates()), t);
}

void Board::change(Tile *sBoard, Tile *sHand)
{
	//sHand->setCoordinates(sBoard->getCoordinates());
	putStroke(*sBoard,*sHand, sBoard, sHand);
	Tile tmp = *sBoard;
	*sBoard = *sHand;
	*sHand = tmp;
	sHand->setPlayer(sBoard->getPlayer());
}

void Board::change(Tile *t)
{
	change((Tile*)get(t->getCoordinates()), t);
}

void Board::putStroke(Tile t1, Tile t2, Tile *t3, Tile *t4){
	strokeCancel.clear();
	strokePlay.push_back((strokeTmp){t1,t2, t3, t4});
}

void Board::undoStroke(){
	strokeTmp s = strokePlay.back();
	strokeCancel.push_back(s);
	*s.pointerTileHand = s.tileHand;
	*s.pointerTileBoard = s.tileBoard;
	strokePlay.pop_back();
}

void Board::redoStroke(){
	strokeTmp s = strokeCancel.back();
	strokePlay.push_back(s);
	//*s.pointerTileHand = s.tileHand;
	//*s.pointerTileBoard = s.tileBoard;
	if (s.pointerTileHand->isEmpty())
		put(s.pointerTileHand, s.pointerTileBoard);
	else
		change(s.pointerTileHand, s.pointerTileBoard);
	strokeCancel.pop_back();
}

bool Board::canUndo()
{
	return !strokePlay.empty();
}

bool Board::canRedo()
{
	return !strokeCancel.empty();
}

bool Board::putPossible(Point p, Tile* t)
{
	return putPossible(p.x, p.y, t);
}

bool Board::putPossible(int x, int y, Tile* t)
{
	return 	board[x][y]->isEmpty()
			&& adjacentPossible(t, board[x-1][y], WEST)
			&& adjacentPossible(t, board[x+1][y], EAST)
			&& adjacentPossible(t, board[x][y+1], SOUTH)
			&& adjacentPossible(t, board[x][y-1], NORTH);
}

bool Board::putPossible(Tile *t)
{
	return putPossible(t->getCoordinates(), t);
}

void Board::put(Tile *sBoard, Tile *sHand) {
	//sHand->setCoordinates(sBoard->getCoordinates());

	Station* station = nextToStop(sBoard->getCoordinates()) ;
	if( station != NULL){
		cout << "station found " << station->getType() << endl;
		// stop represent the adjacent stop, if there is no Tile associated to it, we associate the stop to the pointer of the tile on the board and the tile is set as a stop tile
		if (!(station->isLinked())){
			cout << "station link " << station->getType() << endl;
			sHand->setStop(true);
			if (station->getCoordinates().x - sHand->getCoordinates().x == 1)
				station->setOrientation(WEST);
			else if (station->getCoordinates().x - sHand->getCoordinates().x == -1)
				station->setOrientation(EAST);
			else if (station->getCoordinates().y - sHand->getCoordinates().y == 1)
				station->setOrientation(NORTH);
			else if (station->getCoordinates().y - sHand->getCoordinates().y == -1)
				station->setOrientation(SOUTH);

		}
	}

	putStroke(*sBoard,*sHand, sBoard, sHand);
	//Tile tmp = *sBoard;
	//cout << "in put -*-*-*-*-*-*-*-* card player : " << sHand->getPlayer() << endl;
	(*sBoard) = (*sHand);
	*sHand = Tile(Empty);
	//*sHand = tmp;
}

void Board::putComputer(Tile *sBoard, Tile *sHand) {
	//sHand->setCoordinates(sBoard->getCoordinates());

	
// 	Station* station = nextToStop(sBoard->getCoordinates()) ;
// 
// 	    if( station != NULL){
// 			cout << "station found" << endl;
// 		// 	// stop represent the adjacent stop, if there is no Tile associated to it, we associate the stop to the pointer of the tile on the board and the tile is set as a stop tile
// 			if (!(station->isLinked())){
// 				cout << "station link" << endl;
// 				sHand->setStop(true);
// 				if (station->getCoordinates().y - sHand->getCoordinates().y == 1){
// 					cout << "#############################################################WEST####################################################" << endl;
// 	// 				station->setOrientation(WEST);
// 				}
// 				else if (station->getCoordinates().y - sHand->getCoordinates().y == -1){
// 					cout << "#############################################################EAST####################################################" << endl;
// 	// 				station->setOrientation(EAST);
// 				}
// 				else if (station->getCoordinates().x - sHand->getCoordinates().x == 1){
// 					cout << "#############################################################NORTH####################################################" << endl;
// 	// 				station->setOrientation(NORTH);
// 				}
// 				else if (station->getCoordinates().x - sHand->getCoordinates().x == -1){
// 					cout << "#############################################################SOUTH####################################################" << endl;
// 	// 				station->setOrientation(SOUTH);
// 				}
// 			}
// 	    }

	putStroke(*sBoard,*sHand, sBoard, sHand);
	//Tile tmp = *sBoard;
	(*sBoard) = (*sHand);
	//     *sHand = Tile(Empty);
	//*sHand = tmp;
}



void Board::putComputer(Tile *t)
{
	putComputer((Tile*)get(t->getCoordinates()), t);
}

void Board::put(Tile *t)
{
	put((Tile*)get(t->getCoordinates()), t);
}

Station *Board::nextToStop(Point p)
{
	return nextToStop(p.x, p.y);
}

Station *Board::nextToStop(int row, int column)
{
	if (get(row-1, column)->isStation())
		return (Station*)get(row-1, column);
	else if (get(row+1, column)->isStation())
		return (Station*)get(row+1, column);
	else if (get(row, column-1)->isStation())
		return (Station*)get(row, column-1);
	else if (get(row, column+1)->isStation())
		return (Station*)get(row, column+1);
	else
		return NULL;
	/*
	// case station A
	if ((((column + 1 == 1)||(column - 1 == 1)) && (row == 8)) || ((column == 1 ) && ((row + 1 == 8)||(row - 1 == 8))))
		return (Station*) board[8][1];
	else if ((((column + 1 == 2)||(column - 1 == 2)) && (row == 4)) || ((column == 2 ) && ((row + 1 == 4)||(row - 1 == 4))))
		return (Station*) board[4][2];
	else if ((((column + 1 == 3)||(column - 1 == 3)) && (row == 6)) || ((column == 3 ) && ((row + 1 == 6)||(row - 1 == 6))))
		return (Station*) board[6][4];
	else if ((((column + 1 == 4)||(column - 1 == 4)) && (row == 11)) || ((column == 4 ) && ((row + 1 == 11)||(row - 1 == 11))))
		return (Station*) board[11][4];
	else if ((((column + 1 == 5)||(column - 1 == 5)) && (row == 1)) || ((column == 5 ) && ((row + 1 == 1)||(row - 1 == 1))))
		return (Station*) board[1][5];
	else if ((((column + 1 == 6)||(column - 1 == 6)) && (row == 9)) || ((column == 6 ) && ((row + 1 == 9)||(row - 1 == 9))))
		return (Station*) board[9][6];
	else if ((((column + 1 == 7)||(column - 1 == 7)) && (row == 4)) || ((column == 7 ) && ((row + 1 == 4)||(row - 1 == 4))))
		return (Station*) board[4][7];
	else if ((((column + 1 == 8)||(column - 1 == 8)) && (row == 12)) || ((column == 8 ) && ((row + 1 == 12)||(row - 1 == 12))))
		return (Station*) board[12][8];
	else if ((((column + 1 == 9)||(column - 1 == 9)) && (row == 2)) || ((column == 9 ) && ((row + 1 == 9)||(row - 1 == 2))))
		return (Station*) board[2][9];
	else if ((((column + 1 == 9)||(column - 1 == 9)) && (row == 7)) || ((column == 9 ) && ((row + 1 == 7)||(row - 1 == 7))))
		return (Station*) board[7][9] ;
	else if ((((column + 1 == 11)||(column - 1 == 11)) && (row == 9)) || ((column == 11 ) && ((row + 1 == 9)||(row - 1 == 9))))
		return (Station*) board[9][11];
	else if ((((column + 1 == 12)||(column - 1 == 12)) && (row == 5)) || ((column == 12 ) && ((row + 1 == 5)||(row - 1 == 5))))
		return (Station*) board[5][12];
	else
		return NULL;
*/
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
	//cout << "test adjacent " << a->getCoordinates().x << " " << a->getCoordinates().y << " " << b->getCoordinates().x << " " << b->getCoordinates().y << " " << o << endl;
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
		res = a->getAccess(o) == ((Tile*)b)->getAccess((Orientation)((o+2)%4));
		//res = (a->getAccess(o) xor b->getAccess((Orientation)((o+2)%4)));
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

			// 		cout << "Type: " << board[i][j]->getType() ;


	    switch (board[j][i]->getType()) {

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


				case StationM :
				cout << "  M  ";
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
	  }*/

}

void Board::resetStroke()
{
	strokePlay.clear();
	strokeCancel.clear();
}

ostream& operator << (std::ostream &f, Board &t){
	f << t.size << " ";
	f << t.nbrStation << " ";
	for (int i = 0; i<t.size; i++)
		for (int j = 0; j<t.size; j++){
			f << t.board[i][j]->getType() << " ";
			f << *t.board[i][j] << " ";
		}
	return f;
}

istream& operator >> (std::istream &f, Board &t){
	int a,b, nbrStationRead = 0;
	f >> a;
	f >> b;
	t.setSize(a,b);

	for (int i = 0; i<t.size; i++)
		for (int j = 0; j<t.size; j++){
			int type;
			f >> type;
			Square *sTmp;
			if (type <= StationM && type >= StationA) {
				sTmp = new Station();
				f >> *((Station*)sTmp);
				t.stations[nbrStationRead] = (Station*)sTmp;
				nbrStationRead++;
			}else{
				sTmp = new Tile();
				f >> *((Tile*)sTmp);
			}
			t.changeSquare(sTmp);
		}
	return f;
}
