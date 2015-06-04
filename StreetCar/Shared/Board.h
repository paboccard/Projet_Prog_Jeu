#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include "Tile.h"
#include "Station.h"
#include <fstream>
#include <vector>

//#define BOARD_SIZE 14
//#define NBR_STATION 12

typedef struct{
    Tile tileBoard;
    Tile tileHand;
    Tile *pointerTileBoard;
    Tile *pointerTileHand;
}strokeTmp;

class Board
{
 public:

    Board(int s = 0, int nb = 0);

    ~Board();

    void free();

    void whichTerminus(int line, Point term[2][2]);
    bool adjacentPossible(Tile *a, Square *b, Orientation o);
    // GET/SET board
    Square* get(Point p);
    Square* get(int row, int column);
    void set(int row, int column, Square *t);

    int getSize();
    void setSize(int s, int nb);
    int getNbrStation();
    Station *getStation(idTile i);

    // GET/SET station

    bool putPossible(Point p, Tile *t);
    bool putPossible(int row, int column, Tile *t);
    bool putPossible(Tile *t);
    void put(Tile *sBoard, Tile *sHand);
    void put(Tile *t);

    bool changePossible(Tile *t1, Tile *t2);
    bool changePossible(Tile *t);
    void change(Tile *sBoard, Tile *sHand);
    void change(Tile *t);

    void putStroke(Tile t1, Tile t2, Tile *t3, Tile *t4);
    void redoStroke();
    void undoStroke();

    // returns the stop next to the given index or NULL if there is no stops
    Station* nextToStop(Point p);
    Station* nextToStop(int row, int column);

    //void copy(Board copy);
    void printConsole();
    void read(std::istream &f);

    void initEmpty();
    friend std::ostream& operator << (std::ostream &f, Board &t);
    friend std::istream& operator >> (std::istream &f, Board &t);

 private:
    int size;
    Square* **board;	//double table of square
    std::vector<strokeTmp> strokePlay;
    std::vector<strokeTmp> strokeCancel;

    /*
      bool adjacentNorthPossible(Tile a, Square *b);
      bool adjacentSouthPossible(Tile a, Square *b);
      bool adjacentEastPossible(Tile a, Square *b);
      bool adjacentWestPossible(Tile a, Square *b);
    */
 protected:
    int nbrStation;

    Station* *stations;

    void setSquare(Square *s);
    void changeSquare(Square *s);
};

#endif
