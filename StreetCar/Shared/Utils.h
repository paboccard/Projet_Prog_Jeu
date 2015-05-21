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
    Wall = 20,
    Terminus1_1 = 21,
    Terminus1_2 = 22,
    Terminus2_1 = 23,
    Terminus2_2 = 24,
    Terminus3_1 = 25,
    Terminus3_2 = 26,
    Terminus4_1 = 27,
    Terminus4_2 = 28,
    Terminus5_1 = 29,
    Terminus5_2 = 30,
    Terminus6_1 = 31,
    Terminus6_2 = 32,
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
