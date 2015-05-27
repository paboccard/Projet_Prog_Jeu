#include "Computer.h"

using namespace std;

Computer::Computer(std::vector<Player> allPlayers,int IAm){
    board = Board();
    players= allPlayers;
    whoAmI=IAm;
    // board.whichTerminus(INFORMATIONS.line,myTerminus);
    //createPath();
    
    /*things create for test purpose only*/
    INFORMATIONS.line=1;
    board.whichTerminus(INFORMATIONS.line,myTerminus);
    for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	    cout << myTerminus[i][j].x << "|" << myTerminus[i][j].y << " ";
    cout << endl;
    Stop stop1(StationL),stop2(StationA),stop3(StationB);
    stop1.coordinates={1,12};
    stop2.coordinates={10,2};
    stop3.coordinates={5,6};
    vector<Stop> totot;
    totot.push_back(stop1);
    totot.push_back(stop2);
    totot.push_back(stop3);
    
    INFORMATIONS.itinerary=totot;
    for(Stop tototot : INFORMATIONS.itinerary)
	cout << tototot.coordinates.x << "|" << tototot.coordinates.y << " ";
    cout<<endl;
}
vector<Stop> Computer::createOrder(){
    vector<Stop> StationOrder;
    bool isVert=(myTerminus[0][0].y==myTerminus[0][1].y),firstIsLeftOrDown=(isVert && myTerminus[0][0].x<myTerminus[1][0].x || !isVert && myTerminus[0][0].y<myTerminus[1][0].y);
    int calcul_x,calcul_y;
    Point min={15,15};
    Stop whichStop=INFORMATIONS.itinerary[0];
    Vector<Point> listOfPoint;
    int distance=31,distanceTmp=31;
    for(int i=0;i<INFORMATIONS.itinerary.size();i++){
	calcul_x=INFORMATIONS.itinerary[i].coordinates.x - myTerminus[0][0].x;
	calcul_y=INFORMATIONS.itinerary[i].coordinates.y - myTerminus[0][0].y;
	calcul_x=ABS(calcul_x);
	calcul_y=ABS(calcul_y);
	// cout <<  "caculs :  " << calcul_x << "|" << calcul_y << endl;
	distanceTmp=calcul_x+calcul_y;
	if(distanceTmp<distance){
	    cout << "doistance "<< distanceTmp << endl;
	    distance=distanceTmp;
	    whichStop=INFORMATIONS.itinerary[i];
	}
    }
    StationOrder.push_back(whichStop);
    for(int i=0; i<INFORMATIONS.itinerary.size()-1;i++){
	distance=31;
	distanceTmp=31;
	for(int j=0;j<INFORMATIONS.itinerary.size();j++){
	    int k=0;
	    for(;k<StationOrder.size()&& StationOrder[k].coordinates != INFORMATIONS.itinerary[j].coordinates;k++);
	    if(k==StationOrder.size()){
		calcul_x=INFORMATIONS.itinerary[j].coordinates.x - StationOrder[i].coordinates.x;
		calcul_y=INFORMATIONS.itinerary[j].coordinates.y - StationOrder[i].coordinates.y;
		calcul_x=ABS(calcul_x);
		calcul_y=ABS(calcul_y);
		cout <<  "caculs :  " << calcul_x << "|" << calcul_y << endl;
		distanceTmp=calcul_x+calcul_y;
	
		if(distanceTmp<distance){
		    cout << "doistance "<< distanceTmp << endl;
		    distance=distanceTmp;
		    whichStop=INFORMATIONS.itinerary[j];
		}
	    }
	}
	StationOrder.push_back(whichStop);

    }
    if(isVert && firstIsLeftOrDown)
	listOfPoint.push_back(StationOrder[0].coordinates.y+1>myTerminus[0][0].y ? )

    return StationOrder;
}
