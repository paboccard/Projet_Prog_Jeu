#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"

enum idTile {
    /*
       |
       |
    */
    Straight=0,
    /*
      __
        \
    */
    Curve=1,
    /*

      __ \__
        \
    */
    DoubleCurves=2,
    /*
        |
      --|--
        |
    */
    Intersect=3,
    /*
      __   __
        \ /
    */
    VCurve=4,
    /*
      __ |
        \|
    */
    StraightLCurve=5,
    /*
      |  __
      |/
    */
    StraightRCurve=6,
    /*
      _______
        \ /
         V
    */
    HStraightVCurve=7,
    /*
       __ | __
         \|/
          V
    */
    VStraightVCurve=8,
    /*
      __/ \__
        \ /
    */
    CrossCurves=9,
    /*
         |\__
      __ |
        \|
    */
    StraightLDoubleCurves=10,
    /*
      __/|
         | __
         |/
    */
    StraightRDoubleCurves=11,
    StationA,
    StationB,
    StationC,
    StationD,
    StationE,
    StationF,
    StationG,
    StationH,
    Empty=-1,
};



struct Point;

class Square{
    Point Coordinates;
	idTile type;
 public:
    Square();
	bool isEmpty();
};

<<<<<<< HEAD
// enum of the differet types of packs in the protocol

enum packs {
    // CLIENT TO SERVER PACKS
    STARTTRAVEL = 0, PLAYTRAVEL, STOPTRAVEL, PLAYTILE,
    // SERVER TO CLIENT PACKS
    PLAYEDTILE, PLAYEDTRAVEL, STARTEDTRAVEL, STOPPEDTRAVEL, VALIDATION, WON
};

#endif
