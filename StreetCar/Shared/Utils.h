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
    DoubleCurve=2, 
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
    
    Empty=-1;
};




typedef struct {
    int x,y;
}Square ;

typedef vector<vector<Square>> Board;

typedef struct {
    int s1,s2; // s1 <= s2 .
}Rail;

typedef struct {
    int pile [12];
}Configuration;

typedef struct{
    Player *player;
    int idHand;
    int turn;
    Square square;
}Stroke;

#endif
