#include "Tile.h"

using namespace std;


Tile::Tile(idTile t, int p) : Square(t) {

	type = t;
	idPlayer = p;
	turn = 0;
	
	switch(t){
    /*
       |
       |
    */
		case Straight:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			break;
    /*
      __
        \
    */
		case Curve:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
    /*

      __ \__
        \
    */
		case DoubleCurves:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			break;
    /*
        |
      --|--
        |
    */
		case Intersect:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = WEST;
			break;
    /*
      __   __
        \ /
    */
		case VCurve:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = SOUTH;
			ways[0].s2 = EAST;
			ways[1].s1 = SOUTH;
			ways[1].s2 = WEST;
			break;
    /*
      __ |
        \|
    */
		case StraightLCurve:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			break;
    /*
      |  __
      |/
    */
		case StraightRCurve:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = SOUTH;
			break;
    /*
      _______
        \ /
         V
    */
		case HStraightVCurve:
			tree = true;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = WEST;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			ways[2].s1 = EAST;
			ways[2].s2 = SOUTH;
			break;
    /*
       __ | __
         \|/
          V
    */
		case VStraightVCurve:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(4);
			ways[0].s1 = WEST;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			ways[2].s1 = EAST;
			ways[2].s2 = SOUTH;
			ways[3].s1 = NORTH;
			ways[3].s2 = SOUTH;
			break;
    /*
      __/ \__
        \ /
    */
		case CrossCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(4);
			ways[0].s1 = NORTH;
			ways[0].s2 = EAST;
			ways[1].s1 = NORTH;
			ways[1].s2 = WEST;
			ways[2].s1 = SOUTH;
			ways[2].s2 = WEST;
			ways[3].s1 = SOUTH;
			ways[3].s2 = EAST;
			break;
    /*
         |\__
      __ |
        \|
    */
		case StraightLDoubleCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = NORTH;
			ways[2].s1 = NORTH;
			ways[2].s2 = SOUTH;
			break;
    /*
      __/|
         | __
         |/
    */
		case StraightRDoubleCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			ways[1].s1 = WEST;
			ways[1].s2 = NORTH;
			ways[2].s1 = NORTH;
			ways[2].s2 = SOUTH;
			break;
		case Empty:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Wall:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus1_1:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus1_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_1: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus2_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus3_1: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus3_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break; 
		case Terminus4_1: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus4_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus5_1: 
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus5_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus6_1: 
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus6_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_3: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus1_3: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus1_4: 
			tree = false;
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus3_3: 
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus3_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus5_3:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus5_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus4_3: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus4_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus6_3: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus6_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		default:
			cout << "FATAL ERROR: Constructor Tile: Bad idTile" << endl;
			break;
	}
}

Tile::Tile(idTile t, int p, int x, int y) : Square(t, x, y) {

	type = t;
	idPlayer = p;
	turn = 0;
	
	switch(t){
    /*
       |
       |
    */
		case Straight:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			break;
    /*
      __
        \
    */
		case Curve:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
    /*

      __ \__
        \
    */
		case DoubleCurves:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			break;
    /*
        |
      --|--
        |
    */
		case Intersect:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = WEST;
			break;
    /*
      __   __
        \ /
    */
		case VCurve:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = SOUTH;
			ways[0].s2 = EAST;
			ways[1].s1 = SOUTH;
			ways[1].s2 = WEST;
			break;
    /*
      __ |
        \|
    */
		case StraightLCurve:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			break;
    /*
      |  __
      |/
    */
		case StraightRCurve:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = SOUTH;
			break;
    /*
      _______
        \ /
         V
    */
		case HStraightVCurve:
			tree = true;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = WEST;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			ways[2].s1 = EAST;
			ways[2].s2 = SOUTH;
			break;
    /*
       __ | __
         \|/
          V
    */
		case VStraightVCurve:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(4);
			ways[0].s1 = WEST;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			ways[2].s1 = EAST;
			ways[2].s2 = SOUTH;
			ways[3].s1 = NORTH;
			ways[3].s2 = SOUTH;
			break;
    /*
      __/ \__
        \ /
    */
		case CrossCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(4);
			ways[0].s1 = NORTH;
			ways[0].s2 = EAST;
			ways[1].s1 = NORTH;
			ways[1].s2 = WEST;
			ways[2].s1 = SOUTH;
			ways[2].s2 = WEST;
			ways[3].s1 = SOUTH;
			ways[3].s2 = EAST;
			break;
    /*
         |\__
      __ |
        \|
    */
		case StraightLDoubleCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = NORTH;
			ways[2].s1 = NORTH;
			ways[2].s2 = SOUTH;
			break;
    /*
      __/|
         | __
         |/
    */
		case StraightRDoubleCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			ways[1].s1 = WEST;
			ways[1].s2 = NORTH;
			ways[2].s1 = NORTH;
			ways[2].s2 = SOUTH;
			break;
		case Empty:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Wall:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus1_1:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus1_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_1: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus2_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus3_1: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus3_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break; 
		case Terminus4_1: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus4_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus5_1: 
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus5_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus6_1: 
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus6_2: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_3: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus1_3: 
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus1_4: 
			tree = false;
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus3_3: 
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus3_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus5_3:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus5_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus4_3: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus4_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus6_3: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus6_4: 
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		default:
			cout << "FATAL ERROR: Constructor Tile: Bad idTile" << endl;
			break;
	}
}

bool Tile::change(Tile t){
    if(tree)
	return false;
    switch (t.type){
    case Straight:
	return type==Intersect || type==StraightLCurve || type==StraightRCurve || type==HStraightVCurve || type==VStraightVCurve || type==StraightLDoubleCurves || type==StraightRDoubleCurves;
    case Curve:
	return !(type==Intersect);
    case StraightRCurve:
	return type==StraightRDoubleCurves || type==HStraightVCurve || type==VStraightVCurve;
    case StraightLCurve:
	return type==StraightLDoubleCurves || type==HStraightVCurve || type==VStraightVCurve;
    case VCurve:
	return type==HStraightVCurve || type==VStraightVCurve || type==CrossCurves;
    case DoubleCurves:
	return type==StraightLDoubleCurves || type==StraightRDoubleCurves || type==CrossCurves;
    default:
	return false;
    }
}

void Tile::rotate(){
	turn++;
	if(turn == 4) turn = 0;
	bool temp = access[WEST];
	access[WEST] = access[NORTH];
	access[NORTH] = access[EAST];
	access[EAST] = access[SOUTH];
	access[SOUTH] = temp;
	for(unsigned int i=0;i<ways.size();i++){
		ways[i].s1 = (ways[i].s1 + 1) % 4;
		ways[i].s2 = (ways[i].s2 + 1) % 4;
	}
}

ostream& operator << (ostream &f, Tile &t){
    
	f << "Coordinates X: " << t.coordinates.x << " Y: " << t.coordinates.y << endl; 
    f << "Tree: " << t.tree << endl;
    
    f << "Number of ways: " << t.ways.size() << endl;
    for (unsigned int i = 0; i<t.ways.size(); i++){
	f << t.ways[i].s1 << " " << t.ways[i].s2 << endl;
    }
    f << "Rotation: " << t.turn << endl;
    f << "Type: " << t.type << endl;
    f << "Players: " << t.idPlayer << " ";
	f << "Access: ";
    for (int i = 0; i<4; i++){
	if (t.access[i])
	    f << 1 << " ";
	else
	    f << 0 << " ";
    }
    cout << endl;
    return f;
	
//     f << t.tree << " ";
//     
//     f << t.ways.size() << " ";
//     for (unsigned int i = 0; i<t.ways.size(); i++){
// 	f << t.ways[i].s1 << " " << t.ways[i].s2 << " ";
//     }
//     f << t.turn << endl;
//     f << t.type << endl;
//     f << t.idPlayer << " ";
//     for (int i = 0; i<4; i++){
// 	if (t.access[i])
// 	    f << 1 << " ";
// 	else
// 	    f << 0 << " ";
//     }
//     return f;
}

istream& operator >> (istream &f, Tile &t){
    int tree;
    Rail r;
    f >> tree;
    if (tree)
	t.tree = true;
    else 
	t.tree = false;
    
    int nbrT;
    f >> nbrT;
    t.ways.clear();
    for (int i = 0; i<nbrT; i++){
	f >> r.s1;
	f >> r.s2;
	t.ways.push_back(r);
    }

    f >> t.turn;
    
    int ty;
    f >> ty;
    idTile idT;
    switch(ty){
    case 0:
	idT = Straight;
	break;
    case 1:
	idT = Curve;
	break;
    case 2:
	idT = DoubleCurves;
	break;
    case 3:
	idT = Intersect;
	break;
    case 4:
	idT = VCurve;
	break;
    case 5:
	idT = StraightLCurve;
	break;
    case 6:
	idT = StraightRCurve;
	break;
    case 7:
	idT = HStraightVCurve;
	break;
    case 8:
	idT = VStraightVCurve;
	break;
    case 9:
	idT = CrossCurves;
	break;
    case 10:
	idT = StraightLDoubleCurves;
	break;
    case 11:
	idT = StraightRDoubleCurves;
	break;
    case 12:
	idT = StationA;
	break;
    case 13:
	idT = StationB;
	break;
    case 14:
	idT = StationC;
	break;
    case 15:
	idT = StationD;
	break;
    case 16:
	idT = StationE;
	break;
    case 17:
	idT = StationF;
	break;
    case 18:
	idT = StationG;
	break;
    case 19:
	idT = StationH;
	break;
    case -1:
	idT = Empty;
	break;
    }
    t.type = idT;
    f >> t.idPlayer;
    for (int i = 0; i<4; i++){
	int test;
	f >> test;
	if (test)
	    t.access[i] = 1;
	else
	    t.access[i] = 0;
    }
    return f;
}
