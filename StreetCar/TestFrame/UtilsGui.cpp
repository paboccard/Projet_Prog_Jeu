
#include "UtilsGui.h"

QPixmap getPixmap(idTile i) {
	switch(i) {
		case Empty:
			return QPixmap(":/tiles/emptyTileLisse");
			break;
		case Straight:
			return QPixmap(":/tiles/tile2");
			break;
		case Curve:
			return QPixmap(":/tiles/tile4");
			break;
		case DoubleCurves:
			return QPixmap(":/tiles/tile11");
			break;
		case Intersect:
			return QPixmap(":/tiles/tile9");
			break;
		case VCurve:
			return QPixmap(":/tiles/tile3");
			break;
		case StraightLCurve:
			return QPixmap(":/tiles/tile5");
			break;
		case StraightRCurve:
			return QPixmap(":/tiles/tile1");
			break;
		case HStraightVCurve:
			return QPixmap(":/tiles/tile6");
			break;
		case VStraightVCurve:
			return QPixmap(":/tiles/tile10");
			break;
		case CrossCurves:
			return QPixmap(":/tiles/tile12");
			break;
		case StraightLDoubleCurves:
			return QPixmap(":/tiles/tile7");
			break;
		case StraightRDoubleCurves:
			return QPixmap(":/tiles/tile8");
			break;
		case StationA:
			return QPixmap(":/stations/stationA");
			break;
		case StationB:
			return QPixmap(":/stations/stationB");
			break;
		case StationC:
			return QPixmap(":/stations/stationC");
			break;
		case StationD:
			return QPixmap(":/stations/stationD");
			break;
		case StationE:
			return QPixmap(":/stations/stationE");
			break;
		case StationF:
			return QPixmap(":/stations/stationF");
			break;
		case StationG:
			return QPixmap(":/stations/stationG");
			break;
		case StationH:
			return QPixmap(":/stations/stationH");
			break;
		case StationI:
			return QPixmap(":/stations/stationI");
			break;
		case StationK:
			return QPixmap(":/stations/stationK");
			break;
		case StationL:
			return QPixmap(":/stations/stationL");
			break;
		case StationM:
			return QPixmap(":/stations/stationM");
			break;
		case Wall:
			return QPixmap(":/tiles/wallLisse");
			break;
		default:
			return QPixmap(":/tiles/emptyTile");
	}
}
