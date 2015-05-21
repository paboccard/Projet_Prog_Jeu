#ifndef UTILS_H
#define UTILS_H

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
    StationA = 12,
    StationB = 13,
    StationC = 14,
    StationD = 15,
    StationE = 16,
    StationF = 17,
    StationG = 18,
    StationH = 19,
    StationI= 20,
    StationJ= 21,
    StationK= 22,
    StationL= 23,
    Wall = 24,
    Terminus1_1 = 25,
    Terminus1_2 = 26,
    Terminus2_1 = 27,
    Terminus2_2 = 28,
    Terminus3_1 = 29,
    Terminus3_2 = 30,
    Terminus4_1 = 31,
    Terminus4_2 = 32,
    Terminus5_1 = 33,
    Terminus5_2 = 34,
    Terminus6_1 = 35,
    Terminus6_2 = 36,
    Empty=-1,
};

// enum of the differet types of packs in the protocol

enum packs {
    // CLIENT TO SERVER PACKS
    STARTTRAVEL = 0, PLAYTRAVEL, STOPTRAVEL, PLAYTILE,
    // SERVER TO CLIENT PACKS
    PLAYEDTILE, PLAYEDTRAVEL, STARTEDTRAVEL, STOPPEDTRAVEL, VALIDATION, WON
};

#endif
