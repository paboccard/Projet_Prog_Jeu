
#include "UtilsGui.h"

QPixmap getPixmap(idTile i) {
	switch(i) {
		case Empty:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/emptyTileLisse.png");
			break;
		case Straight:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile2.png");
			break;
		case Curve:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile4.png");
			break;
		case DoubleCurves:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile11.png");
			break;
		case Intersect:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile9.png");
			break;
		case VCurve:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile3.png");
			break;
		case StraightLCurve:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile5.png");
			break;
		case StraightRCurve:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile1.png");
			break;
		case HStraightVCurve:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile6.png");
			break;
		case VStraightVCurve:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile10.png");
			break;
		case CrossCurves:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile12.png");
			break;
		case StraightLDoubleCurves:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile7.png");
			break;
		case StraightRDoubleCurves:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/tile8.png");
			break;
		case StationA:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationA.png");
			break;
		case StationB:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationB.png");
			break;
		case StationC:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationC.png");
			break;
		case StationD:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationD.png");
			break;
		case StationE:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationE.png");
			break;
		case StationF:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationF.png");
			break;
		case StationG:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationG.png");
			break;
		case StationH:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationH.png");
			break;
		case StationI:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationI.png");
			break;
		case StationK:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationK.png");
			break;
		case StationL:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationL.png");
			break;
		case StationM:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/stations/stationM.png");
			break;
		case Wall:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/wallLisse.png");
			break;
		default:
			return QPixmap("/home/f/finielj/Projet_Prog_Jeu/StreetCar/StreetCar/images/tiles/emptyTile.png");
	}
}
