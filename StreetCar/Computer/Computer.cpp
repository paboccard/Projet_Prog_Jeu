#include "Computer.h"

using namespace std;

void printBoard(Board b){
    Square *s;
    for(int i = 0 ; i < 14 ; i++){
	for(int j = 0 ; j < 14 ; j++){
	    s = b.get(i,j);
	    cout << (int)s->getType() << "  ";
	}
	cout << endl;
    }
    cout << endl;
}

Computer::Computer(std::vector<vector<Tile> > hands,int IAm, GoalPlayer goalP){
    board = new Board();
    players.clear();
    for (unsigned int i=0; i<hands.size(); i++){
	Player *p = new Player();
	p->setMyIdPlayer(i);
	Tile* handTmp[5];
	for (int j=0; j<5; j++){
	    *handTmp[i] = hands[i][j];
	    pile[(int)handTmp[i]->getType()]--; 
	}
	p->setHand(handTmp);
	players.push_back(p);
    }
    myPlayer = *players[IAm];
    //createPath();
    cout << "CP 1" << endl;
    /*things create for test purpose only*/
    myPlayer.setLine(goalP.line);
    board->whichTerminus(myPlayer.getLine(),myTerminus);
    int* s = goalP.stop.whichStation(myPlayer.getLine());
    vector<idTile> stations;
    stations.clear();
    for (int i = 0; i<3; i++)
	stations.push_back((idTile)s[i]);
    vector<Station*> it;
    for (unsigned i = 0; i<stations.size(); i++)
	it.push_back(board->getStation(stations[i]));
    myPlayer.setItinerary(it);
    for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	    cout << myTerminus[i][j].x << "|" << myTerminus[i][j].y << " ";
    cout << endl;
    // Stop stop1(StationL),stop2(StationA),stop3(StationB);
    // stop1.coordinates={1,12};
    // stop2.coordinates={10,2};
    // stop3.coordinates={5,6};
    // vector<Stop> totot;
    // totot.push_back(stop1);
    // totot.push_back(stop2);
    // totot.push_back(stop3);
    // cout << "CP 2" << endl;
    
    /*CAUSE DES SEGMENTATION FAULT*/
    //    myPlayer.itinerary=totot;
    /*	for(Stop tototot : myPlayer.itinerary)
	cout << tototot.coordinates.x << "|" << tototot.coordinates.y << " ";
    */
}

// double eval(Tile tile){
//     Stop* stop;
//     if(stop=nextToStop(tile.coordinates.y,tile.coordinates.x)
    
// }

/*****************************************/
/*            GETTEUR                    */
/*****************************************/

Board* Computer::getBoard(){
    return board;
}

Player Computer::getMyPlayer(){
    return myPlayer;
}

int* Computer::getPile(){
    return pile;
}

vector<Player*> Computer::getPlayers(){
    return players;
}

Player* Computer::getPlayers(int position){
    return players[position];
}

/*****************************************/
/*            SETTEUR                    */
/*****************************************/

void Computer::setPlayers(vector<Player*> player){
    players = player;
}

void Computer::setPile(int p[12]){
    for (int i = 0; i<12; i++)
	pile[i] = p[i];
}

void Computer::setPile(int idxChange){
    pile[idxChange]--;
}

void Computer::setMyPlayer(Player p){
    myPlayer = p;
}

// int minimalpath(int[][] adjPossibilities,int depth){
//     return 1;
// }

vector<Point> aroundStation(Point p){
    vector<Point> Points;
    int x=p.x,y=p.y;
    if (x>1) Points.push_back({x-1,y});
    if (x<12) Points.push_back({x+1,y});
    if (y>1) Points.push_back({x,y-1});
    if (y<12) Points.push_back({x,y+1});
    return Points;
}

PlayTile Computer::easy(){

    Stroke stroke;
    vector<Point> squareEmpty;
    vector<Point>::iterator itEmpty1;
    vector<Point>::iterator itEmpty2;
    PlayTile result = PlayTile();

    result.idPlayer = myPlayer.getMyIdPlayer();

    /*Calcul des cases vides*/
    for(int i = 1; i < 13; i++){
	for(int j = 1 ; j < 13 ; j++){
	    if(board->get(i,j)->isEmpty()) squareEmpty.push_back((Point) {i,j});
	}
    }
	
    /*Initialisation de l'iterateur de case vide*/
    itEmpty1 = squareEmpty.begin();

    set<Stroke> setStroke;
    set<Stroke>::iterator itStroke;

    /*Tous les coups possibles avec la main courante*/
    setStroke = myPlayer.strokePossible();

    bool put = false;	

    // Tant que l'on a pas pose ses deux tuiles et que l'on a encore des possibilites
    while( itStroke != setStroke.end() && !put){
			
	//On recupere le coup
	stroke.tile1 = itStroke->tile1;
	stroke.turn1 = itStroke->turn1;
	stroke.tile2 = itStroke->tile2;
	stroke.turn2 = itStroke->turn2;

	// On recupere les tuiles
	Tile** myHand = myPlayer.getHand();
	Tile* t1 = myHand[stroke.tile1];
	Tile* t2 = myHand[stroke.tile2];
		
	// Rotation de la tuile 1
	for(int j = 0; j < stroke.turn1 ; j++){
	    t1->rotate();
	}

	// Rotation de la tuile 2
	for(int j = 0; j < stroke.turn2 ; j++){
	    t2->rotate();
	}
		
	/*Tant qu'il y a des cases vides*/
	while(itEmpty1 != squareEmpty.end() && !put){

	    /*Recuperation des coordonnees de la case vide*/
	    int k = itEmpty1->x; 
	    int j = itEmpty1->y;

	    // On peut poser t1 ?
	    if(board->putPossible(k,j,t1)){

		/*itEmpty2 pointe sur l'element suivant*/
		itEmpty2 = itEmpty1;
		itEmpty2++;

		/*Tant qu'il y a des cases vides*/
		while(itEmpty2 != squareEmpty.end() && !put){

		    /*Recuperation des coordonnees de la case vide*/
		    int x = itEmpty2->x; 
		    int y = itEmpty2->y;

		    //On peut poser t2 ?
		    if(board->putPossible(x,y,t2)){
						
			result.idxHand[0] = stroke.tile1;
			result.idxHand[1] = stroke.tile2;
			result.tiles[0] = t1;
			result.tiles[1] = t2;
						
			put = true;

		    }
										
		    itEmpty2++;
		}
	    }
				
	    itEmpty1++;
	}
    }
	
    // POSE IMPOSSIBLE
    // if(!put){
    // 	result.idxHand[0] = -1;
    // 	result.idxHand[1] = -1;
    // 	result.tiles[0] = Empty;
    // 	result.tiles[1] = Empty;
    // }
	
    return result;
	
}



void Computer::medium(Board p){};



/*
vector<Stop> Computer::createOrder(){
    vector<Stop> StationOrder;
    bool isVert=(myTerminus[0][0].y==myTerminus[0][1].y),firstIsLeftOrDown=(isVert && myTerminus[0][0].x<myTerminus[1][0].x || !isVert && myTerminus[0][0].y<myTerminus[1][0].y);
    int calcul_x,calcul_y;
    Point min={15,15};
    Stop whichStop=myPlayer.itinerary[0];
    vector<Point> listOfPoint;
    int distance=31,distanceTmp=31;
    for(int i=0;i<myPlayer.itinerary.size();i++){
	calcul_x=myPlayer.itinerary[i].coordinates.x - myTerminus[0][0].x;
	calcul_y=myPlayer.itinerary[i].coordinates.y - myTerminus[0][0].y;
	calcul_x=ABS(calcul_x);
	calcul_y=ABS(calcul_y);
	// cout <<  "caculs :  " << calcul_x << "|" << calcul_y << endl;
	distanceTmp=calcul_x+calcul_y;
	if(distanceTmp<distance){
	    cout << "doistance "<< distanceTmp << endl;
	    distance=distanceTmp;
	    whichStop=myPlayer.itinerary[i];
	}
    }
    StationOrder.push_back(whichStop);
    for(int i=0; i<myPlayer.itinerary.size()-1;i++){
	distance=31;
	distanceTmp=31;
	for(int j=0;j<myPlayer.itinerary.size();j++){
	    int k=0;
	    for(;k<StationOrder.size()&& StationOrder[k].coordinates != myPlayer.itinerary[j].coordinates;k++);
	    if(k==StationOrder.size()){
		calcul_x=myPlayer.itinerary[j].coordinates.x - StationOrder[i].coordinates.x;
		calcul_y=myPlayer.itinerary[j].coordinates.y - StationOrder[i].coordinates.y;
		calcul_x=ABS(calcul_x);
		calcul_y=ABS(calcul_y);
		cout <<  "caculs :  " << calcul_x << "|" << calcul_y << endl;
		distanceTmp=calcul_x+calcul_y;
	
		if(distanceTmp<distance){
		    cout << "doistance "<< distanceTmp << endl;
		    distance=distanceTmp;
		    whichStop=myPlayer.itinerary[j];
		}
	    }
	}
	StationOrder.push_back(whichStop);

    }
    vector<vector<Point>> allPossibilities;
    vector<Point> tmp;
    tmp.push_back(myTerminus[0][0]);
    tmp.push_back(myTerminus[0][1]);
    allPossibilities.push_back(tmp);
    for(int i=0;i<StationOrder.size();i++)
	allPossibilities.push_back(aroundStation(StationOrder[i]));
    tmp.push_back(myTerminus[1][0]);
    tmp.push_back(myTerminus[1][1]);
    allPossibilities.push_back(tmp);
    int sum=0,sumTmp=0;
    for(vector<Point>tmp:allPossibilities)
	sum+=tmp.size();
    int[int][int] adjPossibilities;
    for(int h;h<allPossibilities.size()-1;h++){
	for(int i;i<allPossibilities[h].size();i++)
	    for(int j;j<allPossibilities[h+1].size();j++){
		calcul_x=allPossibilities[h][i].x - allPossibilities[h+1][j].x;
		calcul_y=allPossibilities[h][i].y - allPossibilities[h+1][j].y;
		calcul_x=ABS(calcul_x);
		calcul_y=ABS(calcul_y);
		adjPossibilities[sumTmp+i][sumTmp+i+allPossibilities[h].size()]=calcul_x+calcul_y;
		adjPossibilities[sumTmp+i+allPossibilities[h].size()][sumTmp+i]=calcul_x+calcul_y;
	    }
	sumTmp+=allPossibilities[h].size();
    }
	
    for(Point init:allPossibilities[0]);
	

    return StationOrder;
}*/

// void Computer::monteCarlo(){
// 	
//     Tile empty = Tile(Empty, -1);
//     Pile pileTmp;
//     bool first;
//     int x, y;
// 	
//     boardTmp.copy(board);
// 	
//     // Calcul de tous les coups possibles avec les tuiles de la main
//     set<Stroke> setStroke = players[whoAmI-1].strokePossible();
// 	
//     //#if TRACE
//     cout << "Nombre de coup : " << setStroke.size() << endl;
//     //#endif
// 	
//     /*Pour chaque coup*/
//     for (set<Stroke>::iterator it=setStroke.begin(); it!=setStroke.end(); ++it){
// 	Stroke stroke = *it;
// 		
// 	//#if TRACE
// 	cout << stroke << endl;
// 	//#endif
// 
// 	// On recupere les tuiles
// 	Tile t1 = players[whoAmI-1].hand[stroke.tile1];
// 	Tile t2 = players[whoAmI-1].hand[stroke.tile2];
// 	
// 	//cout << "Rotation 1" << endl;
// 	// Rotation de la tuile 1
// 	for(int j = 0; j < stroke.turn1 ; j++){
// 	    t1.rotate();
// 	}
// 		
// 	//cout << "Rotation 2" << endl;
// 	// Rotation de la tuile 2
// 	for(int j = 0; j < stroke.turn2 ; j++){
// 	    t2.rotate();
// 	}
// 		
// 	/* Nous avons les deux tuiles bien positionnées (orientées)
// 	 * On essaie de placer la tuile t1 sur chaque case libre
// 	 * Des que l'on a trouve une case, on essaie de placer la tuile t2
// 	 * sur chaque case libre a son tour
// 	 * Si l'on place les deux tuiles, on lance l'algo
// 	 * Sinon on passe a la case libre suivante pour t2
// 	 * Si on a tout essaye pour t2, on avance dans t1,
// 	 * Si on a tout essaye pour t1, on passe au couple suivante
// 	 * Si on a tout essaye, c'est fini !!
// 	 */
// 	for(int k = 1; k < 13 ; k++){
// 	    for(int j = 1 ; j < 13 ; j++){
// 				
// 		// On peut poser t1 ?
// 		if(board.putPossible(k,j,t1)){
// 					
// 		    //On place la tuile
// 		    boardTmp.set(k,j,t1);
// 					
// 		    y = (j + 1)%13;
// 		    x = k;
// 		    if(y==0){ 
// 			x++;
// 			y = 1;
// 		    }
// 					
// 		    first = true;
// #if TRACE
// 		    cout << "K: " << k << " J: " << j << endl;
// #endif
// 		    for(x; x < 13 ; x++){
// 						
// 			if(!first) y = 1;
// 						
// 			for(y; y < 13 ; y++){
// 					
// 			    if(y==12) first = false;
// #if TRACE
// 			    cout << "X: " << x << " Y: " << y << endl;
// #endif
// 							
// 			    //On peut poser t2 ?
// 			    if(boardTmp.putPossible(x,y,t2)){
// 								
// 				boardTmp.set(x,y,t2);
// 								
// 				pileTmp = pile;
// 								
// 				/*Pioche les deux nouvelles tuiles*/
// 				players[whoAmI-1].hand[stroke.tile1] = pileTmp.take();
// 				players[whoAmI-1].hand[stroke.tile2] = pileTmp.take();
// 								
// 				allAlea(boardTmp, pileTmp);
// 				//printBoard(boardTmp);
// 				boardTmp.set(x,y,empty);
// 			    }
// 			}
// 		    }
// 		    boardTmp.set(k,j,empty);
// 		}
// 	    }
// 	}
//     }
// }

// void Computer::allAlea(Board b, Pile pile){
// 	
//     bool first, put = false, block = false;
//     int x, y, currentPlayer;
//     Stroke stroke;
//     set<Stroke> setStroke;
//     set<Stroke>::iterator it;
//     vector<Point> squareEmpty;
//     vector<Point>::iterator itEmpty1;
//     vector<Point>::iterator itEmpty2;
// 	
//     //Le joueur courant est celui qui suit l'IA
//     currentPlayer = (whoAmI + 1) % players.size(); //MEFIANCE
//  
//     /*Calcul de toutes les cases libres du board*/
//     for(int i = 1; i < 13; i++){
// 	for(int j = 1 ; j < 13 ; j++){
// 	    if(b.get(i,j).isEmpty()) squareEmpty.push_back((Point) {i,j});
// 	}
//     }
// 	
//     /*Initialisation de l'iterateur de case vide*/
//     itEmpty1 = squareEmpty.begin();
// 	
//     while(!block){
// 	
// 	// Calcul de tous les coups possibles avec les tuiles de la main courante
// 	setStroke = players[currentPlayer].strokePossible();
// 		
// #if TRACE
// 	cout << "Nombre de coup : " << setStroke.size() << endl;
// #endif
// 		
// 	// Initialisation de l'iterateur
// 	it=setStroke.begin();
// 	put = false;	
// 	
// 	// Tant que l'on a pas pose ses deux tuiles et que l'on a encore des possibilites
// 	while( it != setStroke.end() && !put){
// 			
// 	    //On recupere le coup
// 	    stroke.tile1 = it->tile1;
// 	    stroke.turn1 = it->turn1;
// 	    stroke.tile2 = it->tile2;
// 	    stroke.turn2 = it->turn2;
// 			
// 			
// #if TRACE
// 	    cout << stroke << endl;
// #endif		
// 			
// 	    // On recupere les tuiles
// 	    Tile t1 = players[currentPlayer].hand[stroke.tile1];
// 	    Tile t2 = players[currentPlayer].hand[stroke.tile2];
// 
// 	    // Rotation de la tuile 1
// 	    for(int j = 0; j < stroke.turn1 ; j++){
// 		t1.rotate();
// 	    }
// 
// 	    // Rotation de la tuile 2
// 	    for(int j = 0; j < stroke.turn2 ; j++){
// 		t2.rotate();
// 	    }
// 			
// 	    int k = 1;
// 	    int j = 1;
// 			
// 			
// 	    /*Tant qu'il y a des cases vides*/
// 	    while(itEmpty1 != squareEmpty.end() && !put){
// 				
// 		/*Recuperation des coordonnees de la case vide*/
// 		k = itEmpty1->x; 
// 		j = itEmpty1->y;
// 				
// 		// On peut poser t1 ?
// 		if(b.putPossible(k,j,t1)){
// 				
// 		    /*itEmpty2 pointe sur l'element suivant*/
// 		    itEmpty2 = itEmpty1;
// 		    itEmpty2++;
// 					
// 		    /*Tant qu'il y a des cases vides*/
// 		    while(itEmpty2 != squareEmpty.end() && !put){
// 				
// 			/*Recuperation des coordonnees de la case vide*/
// 			x = itEmpty2->x; 
// 			y = itEmpty2->y;
// 					
// 			//On peut poser t2 ?
// 			if(b.putPossible(x,y,t2)){
// 
// 			    b.set(k,j,t1);
// 			    b.set(x,y,t2);
// 			    put = true;
// 							
// 			    /*On enlve les cases posees du veteur*/
// 			    squareEmpty.erase(itEmpty1);
// 			    squareEmpty.erase(itEmpty2);
// 
// 			    /*Pioche les deux nouvelles tuiles*/
// 			    players[currentPlayer].hand[stroke.tile1] = pile.take();
// 			    players[currentPlayer].hand[stroke.tile2] = pile.take();
// 									
// 			    /*Joueur suivant*/
// 			    currentPlayer = (currentPlayer + 1) % players.size(); //MEFIANCE
// 			}
// 								
// 			itEmpty2++;
// 		    }
// 		}
// 				
// 		itEmpty1++;
// 	    }
// 		
// 	    it++;
// 		
// 	}
// 	
// 	block = (itEmpty1 == squareEmpty.end());
// 		
//     }
//    
//     //cout << "Alea termine" << endl;
//     //printBoard(b);
// 
// }

// void Computer::easy(Board b){
// 	
//     Stroke stroke;
//     vector<Point> squareEmpty;
//     vector<Point>::iterator itEmpty1;
//     vector<Point>::iterator itEmpty2;
// 	
//     /*Calcul des cases vides*/
//     for(int i = 1; i < 13; i++){
// 		for(int j = 1 ; j < 13 ; j++){
// 			if(b.get(i,j).isEmpty()) squareEmpty.push_back((Point) {i,j});
// 		}
//     }
// 	
//     /*Initialisation de l'iterateur de case vide*/
//     itEmpty1 = squareEmpty.begin();
// 	
//     set<Stroke> setStroke;
//     set<Stroke>::iterator itStroke;
// 	
//     /*Tous les coups possibles avec la main courante*/
//     setStroke = players[whoAmI].strokePossible();
// 	
//     bool put = false;	
// 	
//     // Tant que l'on a pas pose ses deux tuiles et que l'on a encore des possibilites
//     while( itStroke != setStroke.end() && !put){
// 			
// 	//On recupere le coup
// 	stroke.tile1 = itStroke->tile1;
// 	stroke.turn1 = itStroke->turn1;
// 	stroke.tile2 = itStroke->tile2;
// 	stroke.turn2 = itStroke->turn2;
// 	
// 	// On recupere les tuiles
// 	Tile t1 = players[currentPlayer].hand[stroke.tile1];
// 	Tile t2 = players[currentPlayer].hand[stroke.tile2];
// 	
// 	// Rotation de la tuile 1
// 	for(int j = 0; j < stroke.turn1 ; j++){
// 	    t1.rotate();
// 	}
// 
// 	// Rotation de la tuile 2
// 	for(int j = 0; j < stroke.turn2 ; j++){
// 	    t2.rotate();
// 	}
// 		
// 	/*Tant qu'il y a des cases vides*/
// 	while(itEmpty1 != squareEmpty.end() && !put){
// 				
// 	    /*Recuperation des coordonnees de la case vide*/
// 	    int k = itEmpty1->x; 
// 	    int j = itEmpty1->y;
// 				
// 	    // On peut poser t1 ?
// 	    if(b.putPossible(k,j,t1)){
// 				
// 		/*itEmpty2 pointe sur l'element suivant*/
// 		itEmpty2 = itEmpty1;
// 		itEmpty2++;
// 					
// 		/*Tant qu'il y a des cases vides*/
// 		while(itEmpty2 != squareEmpty.end() && !put){
// 				
// 		    /*Recuperation des coordonnees de la case vide*/
// 		    int x = itEmpty2->x; 
// 		    int y = itEmpty2->y;
// 					
// 		    //On peut poser t2 ?
// 		    if(b.putPossible(x,y,t2)){
// 							
// 			/*
// 			 * 
// 			 * 
// 			 * ENREGISTRER SOUS QUEL FORMAT ??????
// 			 * 
// 			 * 
// 			 * 
// 			 * 
// 			 */
// 			put = true;
// 
// 		    }
// 								
// 		    itEmpty2++;
// 		}
// 	    }
// 				
// 	    itEmpty1++;
// 	}
// 		
// 		
//     }
// 	
//     // POSE IMPOSSIBLE
//     //if(!put) ?????
// 	
// 	
//     //return s;
// 	
// }
