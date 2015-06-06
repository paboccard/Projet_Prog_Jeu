	#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"
#include "Utils.h"
#include <fstream>
#include <iostream>

#define IMPOSSIBLE false
#define OBLIGATORY true

enum Orientation {
    WEST=0,
    SOUTH,
    EAST,
    NORTH
};

class Square{
 public:

    Square(idTile t = Empty, int x = -1, int y = -1);
    virtual ~Square();

    bool isEmpty();
    bool isTerminus();
    bool isStation();
    bool isTile();
    bool isWall();

    virtual bool getAccess(Orientation) = 0;
    virtual bool canChange(Square*) = 0;

    idTile getType();
    void setType(idTile id);
    Point getCoordinates();
    void setCoordinates(Point p);
	void setCoordinates(int x, int y);

    virtual void print();

	virtual Square& operator = (Square const & s);

	void serialize(std::ostream &f);
	void deserialize(std::istream &f);

    friend std::ostream& operator << (std::ostream &f, Square &s);
    friend std::istream& operator >> (std::istream &f, Square &s);

 private:
    Point coordinates;
    idTile type;
};

#endif
