#ifndef UTILS_H
#define UTILS_H
#define ABS(I) ( ((I)<0)? -(I) : (I) )


#include "Card.h"
#define HAND_SIZE 5
#define NBR_LINES 6

enum idTile {
	Empty=-1,
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
    StationA = 12,
    StationB = 13,
    StationC = 14,
    StationD = 15,
    StationE = 16,
    StationF = 17,
    StationG = 18,
    StationH = 19,
    StationI = 20,
    StationJ = 21,
    StationK = 22,
    StationL = 23,
    Wall = 24,
    Terminus1_1 = 25,
    Terminus1_2 = 26,
    Terminus1_3 = 27,
    Terminus1_4 = 28,
    Terminus2_1 = 29,
    Terminus2_2 = 30,
    Terminus2_3 = 31,
    Terminus2_4 = 32,
    Terminus3_1 = 33,
    Terminus3_2 = 34,
    Terminus3_3 = 35,
    Terminus3_4 = 36,
    Terminus4_1 = 37,
    Terminus4_2 = 38,
    Terminus4_3 = 39,
    Terminus4_4 = 40,
    Terminus5_1 = 41,
    Terminus5_2 = 42,
    Terminus5_3 = 43,
    Terminus5_4 = 44,
    Terminus6_1 = 45,
    Terminus6_2 = 46,
    Terminus6_3 = 47,
    Terminus6_4 = 48,
	EmptyHand=49
};

typedef struct{
  Card stop;
  int line;
}GoalPlayer;

typedef struct{
	int tile1;
	int turn1;
	int tile2;
	int turn2;
	
}Stroke;

#endif
