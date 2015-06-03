#ifndef UTILS_H
#define UTILS_H
#define NBR_TILE_MAX 2
#define HAND_SIZE 5
#define PULLPLAYER 6
#define NBR_CARD_STATION 6
#define NBR_LINE 6

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
	StraightRDoubleCurves,
	StationA,
	StationB,
	StationC,
	StationD,
	StationE,
	StationF,
	StationG,
	StationH,
	StationI,
	//StationJ,
	StationK,
	StationL,
	StationM,
	Wall,
	Terminus1_1,
	Terminus1_2,
	Terminus1_3,
	Terminus1_4,
	Terminus2_1,
	Terminus2_2,
	Terminus2_3,
	Terminus2_4,
	Terminus3_1,
	Terminus3_2,
	Terminus3_3,
	Terminus3_4,
	Terminus4_1,
	Terminus4_2,
	Terminus4_3,
	Terminus4_4,
	Terminus5_1,
	Terminus5_2,
	Terminus5_3,
	Terminus5_4,
	Terminus6_1,
	Terminus6_2,
	Terminus6_3,
	Terminus6_4,
	EmptyHand
};

typedef struct{
	int tile1;
	int turn1;
	int tile2;
	int turn2;
	
}Stroke;



#endif
