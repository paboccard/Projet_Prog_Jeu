#include "Utils.h"

public class Tile :public Square {
    bool tree;
    vector<Rail> ways;
    int turn;
    idTile type;
    int idPlayer;
    bool access [4];
    

    bool change(Tile t){
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
}


