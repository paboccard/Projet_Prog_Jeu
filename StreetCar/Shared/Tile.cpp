#include "Tile.h"

using namespace std;

Tile::Tile() : Square() {
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

ostream& operator << (ostream &f, Tile &t){
    
    f << t.tree << " ";
    
    f << t.ways.size() << " ";
    for (unsigned int i = 0; i<t.ways.size(); i++){
	f << t.ways[i].s1 << " " << t.ways[i].s2 << " ";
    }
    f << t.turn << " ";
    f << t.type << " ";
    f << t.idPlayer << " ";
    for (int i = 0; i<4; i++){
	if (t.access[i])
	    f << 1 << " ";
	else
	    f << 0 << " ";
    }
    return f;
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
