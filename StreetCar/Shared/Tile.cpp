#include "Tile.h"

using namespace std;

Tile::Tile(idTile t, int p) {

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

