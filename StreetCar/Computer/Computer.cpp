#include "Computer.h"


using namespace std;

/*void printBoard(Board b){
  Square s;
  for(int i = 0 ; i < 14 ; i++){
  for(int j = 0 ; j < 14 ; j++){
  s = b.get(i,j);
  cout << (int)s->getType() << "  ";
  }
  cout << endl;
  }
  cout << endl;
  }*/

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
	/*things create for test purpose only*/
	myPlayer.setLine(goalP.line);
	board->whichTerminus(myPlayer.getLine(),myTerminus);
	int* s = goalP.stop.whichStation(myPlayer.getLine());
	vector<idTile> stations;
	stations.clear();
	for (int i = 0; i<3; i++){
		stations.push_back((idTile)s[i]);
	}
	vector<Station*> it;
	for (unsigned i = 0; i<stations.size(); i++){
		it.push_back(board->getStation(stations[i]));
	}
	myPlayer.setItinerary(it);
	for (int i=0;i<2;i++){
		for (int j=0;j<2;j++){
			cout << myTerminus[i][j].x << "|" << myTerminus[i][j].y << " ";
		}
	}
	cout << endl;
    // Station stop1(StationL),stop2(StationA),stop3(StationB);
    // stop1->getCoordinates()={1,12};
    // stop2->getCoordinates()={10,2};
    // stop3->getCoordinates()={5,6};
    // vector<Station> totot;
    // totot.push_back(stop1);
    // totot.push_back(stop2);
    // totot.push_back(stop3);
    // cout << "CP 2" << endl;
    
    /*CAUSE DES SEGMENTATION FAULT*/
    /*    myPlayer.itinerary=totot;
	  for(Station &tototot : myPlayer.itinerary)
	  cout << tototot->getCoordinates().x << "|" << tototot->getCoordinates().y << " ";
    */	
				
				
				
    cout << "CP 3" << endl;
    cout<<endl;
}

// double eval(Tile tile){
//     Station* stop;
//     if(stop=nextToStation(tile->getCoordinates().y,tile->getCoordinates().x)
    
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

///////////////////////////////////////



void minimalpath(int** adjPossibilities,int *length,int dist,int path[],int *sizeOfPath,int *res,int pathRes[]){
    int i;
    for(i=0;i<*length && adjPossibilities[path[*sizeOfPath-1]][i]!=31;i++);
    if(i!=*length){
	if (dist<*res){
	    *res=dist;
	    for(int j=0;j<*sizeOfPath;j++)
		pathRes[j]=path[j];
	}
    }
    else{
	for(int j=0;j<*length;j++){
	    if(adjPossibilities[path[*sizeOfPath-1]][j]!=31){
		path[*sizeOfPath++]=j;
		minimalpath(adjPossibilities,length,dist+adjPossibilities[path[*sizeOfPath-2]][j],path,sizeOfPath,res,pathRes);
	    }
	}	
    }
}

vector<Point> around(Point p){
    vector<Point> Points;
    int x=p.x,y=p.y;
    if (x>1) Points.push_back({x-1,y});
    if (x<12) Points.push_back({x+1,y});
    if (y>1) Points.push_back({x,y-1});
    if (y<12) Points.push_back({x,y+1});
    return Points;
}
//TODO gérer les gares !
void heuris(int **heuristic,Point departure,Point arrival){
    int x,y,i=0;
    bool xinf=(departure.x<arrival.x)*(-2),yinf=(departure.y<arrival.y)*(-2);
    
    for(x=ABS(arrival.x-departure.x);departure.x-x!=0;x+=xinf+1){
	for(y=ABS(arrival.y-departure.y);departure.y-y!=0;y+=yinf+1)
	    heuristic[x][y]=ABS(arrival.y-y)+i;
	heuristic[x][y]=ABS(arrival.y-y)+i;
	i++;
    }
    heuristic[x][y]=ABS(arrival.y-y);

}


void cross(Point departure,Point arrival,Point Pred[14][14]){
    if (departure!=arrival)
	cross(departure,Pred[arrival.x][arrival.y],Pred);
    cout << "departure :"<< departure.x << " | " << departure.y << "  ||  " << arrival.x << " | " << arrival.y<<endl;
    return ;
}
vector<Point> aStar(int**heuristic,Point departure,Point arrival){
    //  vector<{int truc,int flute}>
    int height=ABS(departure.y-arrival.y),length=ABS(departure.x-arrival.x);
    Point P[14][14];
    vector<Point> T;
    bool B[height][length],V[height][length],end=false;
    for(int k=0;k<length;k++)
	for(int l=0;l<height;l++){
	    B[l][k]=false;
	    V[l][k]=false;

	}
    typedef struct {Point p;int weight;}elmtFifo;
    vector<elmtFifo> fifo;
    Point x,y;
    int yweight;
    x=departure;
    P[x.x][x.y]=x; //TDO tableau point
    fifo.push_back({x,1});
    while(!end && fifo.size()!=0){
	y=fifo.front().p;
	yweight=fifo.front().weight;
	fifo.erase(fifo.begin());
	B[y.x][y.y]=true;
	V[y.x][y.y]=true;
	T=around(y);
	if(departure==y)
	    end=true;
	for (unsigned int k=0;!end && k<T.size();k++){
	    if(!B[T[k].x][T[k].y] && !V[T[k].x][T[k].y]){// && !arrival.equals(T[k])){
		P[T[k].x][T[k].y]=y;

		//tg.setStatut(tg.getStatut(T[k].x,T[k].y).darker(),T[k].x,T[k].y);
		V[T[k].x][T[k].y]=true;
		fifo.push_back({T[k],1+yweight});
			     }
	    }
	}
	cross(x,arrival,P);	
	vector<Point> res;
	res.push_back(P[1][1]);
	return res; 
}

vector<Point> staryu(vector<Point>& mainAxe){
    vector<Point> tyle;
    int max_x,max_y;
    int **heuristic;//[ABS(mainAxe[i].x-mainAxe[i+1].x)+1][ABS(mainAxe[i].y-mainAxe[i+1].y)+1];
    for(unsigned int i=0;i<mainAxe.size()-1;i++){
	max_x=ABS(mainAxe[i].x-mainAxe[i+1].x)+1;
	max_y=ABS(mainAxe[i].y-mainAxe[i+1].y)+1;

	heuristic=(int**)malloc(sizeof(int*)*(max_x));
	for(int j;j<max_x;j++)  heuristic[j]=(int*)malloc(sizeof(int)*(max_y));
	

	heuris(heuristic,mainAxe[i],mainAxe[i+1]);
	aStar(heuristic,mainAxe[i],mainAxe[i+1]);
    }
    for(int j;j<max_x;j++)  free(heuristic[j]);
    free(heuristic);
    return tyle;

    
}
vector<Point> Computer::createOrder(){
    vector<Station> StationOrder;
    vector<Station*> itinerary=myPlayer.getItinerary();
    int calcul_x,calcul_y;
    Point min={15,15};
    Station whichStation=*itinerary[0];
    vector<Point> listOfPoint;
    int distance=31,distanceTmp=31;
    for(unsigned int i=0;i<itinerary.size();i++){
	calcul_x=itinerary[i]->getCoordinates().x - myTerminus[0][0].x;
	calcul_y=itinerary[i]->getCoordinates().y - myTerminus[0][0].y;
	calcul_x=ABS(calcul_x);
	calcul_y=ABS(calcul_y);
	// cout <<  "caculs :  " << calcul_x << "|" << calcul_y << endl;
	distanceTmp=calcul_x+calcul_y;
	if(distanceTmp<distance){
	    cout << "doistance "<< distanceTmp << endl;
	    distance=distanceTmp;
	    whichStation=*itinerary[i];
	}
    }
    StationOrder.push_back(whichStation);
    for(unsigned int i=0; i<itinerary.size()-1;i++){
	distance=31;
	distanceTmp=31;
	for(unsigned int j=0;j<itinerary.size();j++){
	    unsigned int k=0;
	    for(;k<StationOrder.size()&& StationOrder[k].getCoordinates() != itinerary[j]->getCoordinates();k++);
	    if(k==StationOrder.size()){
		calcul_x=itinerary[j]->getCoordinates().x - StationOrder[i].getCoordinates().x;
		calcul_y=itinerary[j]->getCoordinates().y - StationOrder[i].getCoordinates().y;
		calcul_x=ABS(calcul_x);
		calcul_y=ABS(calcul_y);
		cout <<  "caculs :  " << calcul_x << "|" << calcul_y << endl;
		distanceTmp=calcul_x+calcul_y;
	
		if(distanceTmp<distance){
		    cout << "doistance "<< distanceTmp << endl;
		    distance=distanceTmp;
		    whichStation=*itinerary[j];
		}
	    }
	}
	StationOrder.push_back(whichStation);

    }
    vector<vector<Point> > allPossibilities;
    vector<Point> tmp;
    tmp.push_back(myTerminus[0][0]);
    tmp.push_back(myTerminus[0][1]);
    allPossibilities.push_back(tmp);
    for(unsigned int i=0;i<StationOrder.size();i++)
	allPossibilities.push_back(around(StationOrder[i].getCoordinates()));
    tmp.push_back(myTerminus[1][0]);
    tmp.push_back(myTerminus[1][1]);
    allPossibilities.push_back(tmp);
    int sum=0,sumTmp=0;
    for(vector<Point>tmp:allPossibilities)
	sum+=tmp.size();


    int **adjPossibilities;
    
    adjPossibilities=(int**)malloc(sizeof(int*)*sum);
    for(int i=0; i<sum;i++){
	adjPossibilities[i] = (int*)malloc(sizeof(int)*sum);
	for(int j=0; j<sum;j++)
	    adjPossibilities[i][j]=31;
    }

    for(unsigned int h=0;h<allPossibilities.size()-1;h++){
	for(unsigned int i=0;i<allPossibilities[h].size();i++)
	    for(unsigned int j=0;j<allPossibilities[h+1].size();j++){
		calcul_x=allPossibilities[h][i].x - allPossibilities[h+1][j].x;
		calcul_y=allPossibilities[h][i].y - allPossibilities[h+1][j].y;
		calcul_x=ABS(calcul_x);
		calcul_y=ABS(calcul_y);
		adjPossibilities[sumTmp+i][sumTmp+i+allPossibilities[h].size()]=calcul_x+calcul_y;
		adjPossibilities[sumTmp+i+allPossibilities[h].size()][sumTmp+i]=calcul_x+calcul_y;
	    }
	sumTmp+=allPossibilities[h].size();
    }
    for(int i=0; i<sum;i++)
	for(int j=0; j<sum;j++){
	    cout << adjPossibilities[i][j] << " |";
	    if(j==sum-1)
		cout << endl;
	}
    int path[allPossibilities.size()],pathRes[allPossibilities.size()];
    int *sizeOfPath;
    int *res;
    *res=80000;
    *sizeOfPath=1;
    for(unsigned int i=0;i<allPossibilities[0].size();i++){
	path[0]=i;
	*sizeOfPath=1;
	minimalpath(adjPossibilities,&sum,0,path,sizeOfPath,res,pathRes);
    }
    vector<Point> PointPath;
    unsigned int j;
    for(unsigned int i;i<allPossibilities.size();i++){
	for(j=0;j<allPossibilities.size() && ((unsigned int)pathRes[i])>allPossibilities[j].size();j++)
	    pathRes[i]-=allPossibilities[j].size();
	PointPath.push_back(allPossibilities[j][pathRes[i]]);
    }

    for(int i=0;i<sum;i++)
	free(adjPossibilities[i]);
    free(adjPossibilities);

    return staryu(PointPath);

}
bool Computer::isOnThePath(Point p){

	vector<ElementPath>::iterator iteratorPath = path.begin();
	
	while(iteratorPath != path.end()){
		Point p1 = (*iteratorPath).p;
		if(p.x == p1.x && p.y == p1.y) return true;
		iteratorPath++;
	}
	return false;

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
						Point tmp = {k,j};
						t1->setCoordinates(tmp);
						tmp = {x,y};
						t2->setCoordinates(tmp);
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
	
    // ATTENTION POSE IMPOSSIBLE
    // if(!put){
    // 	result.idxHand[0] = -1;
    // 	result.idxHand[1] = -1;
    // 	result.tiles[0] = Empty;
    // 	result.tiles[1] = Empty;
    // }
	
    return result;
	
}

ElementPath Computer::pathGet(Point p){
	
	bool find = false;
	ElementPath e;
	
	vector<ElementPath>::iterator it = path.begin();
	while( it != path.end() && !find){
		if((*it).p == p){ 
			e = *it;
			find = true;
		}
	}
	
	return e;
}

// p doit appartenir au path
bool Computer::putPathPossible(ElementPath e, Tile *t){
	
	Rail r;
	r.s1 = e.prec;
	r.s2 = e.suiv;
	
	if(r.s1 > r.s2){
		Orientation tmp = r.s2;
		r.s2 = r.s1;
		r.s1 = tmp;
	}
	
	return t->haveRail(r);
}

PlayTile Computer::medium(Board p){

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

 	vector<ElementPath>::iterator iteratorPath1 = path.begin();
 	vector<ElementPath>::iterator iteratorPath2 = path.begin();

	/*Retire toutes les cases vides appartenant au chemin du vecteur de case vide*/
	while(itEmpty1 != squareEmpty.end()){
		Point p = *itEmpty1;
		if(isOnThePath(p)) squareEmpty.erase(itEmpty1);
	}

    /*Tous les coups possibles avec la main courante*/
	set<Stroke> setStroke;
	set<Stroke>::iterator itStroke;
	setStroke = myPlayer.strokePossible();
	
	/*Tant que l'on a pas pose ses 2 tuiles et que l'on a encore des possibilites pour le chemin*/
	bool played = false;
	bool justOne = false;
	vector<ElementPath>::iterator iteratorJustOne;
	
    while( itStroke != setStroke.end() && !played){
		
		/*On recupere les tuiles + rotation*/
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
		
		/*Tant qu'il y a des cases vides sur le chemin et que l'on a pas joue
		 * On essaie de mettre les deux tuiles sur le chemin
		 */
		while(iteratorPath1 != path.end() && !played){
			
			// On peut poser t1 ?
			if(putPathPossible(*iteratorPath1, t1) && board->putPossible((iteratorPath1->p).x, (iteratorPath1->p).y, t1)){

				/*itEmpty2 pointe sur l'element suivant*/
				iteratorPath2 = iteratorPath1;
				iteratorPath2++;
				
				/*Au moins un coup de sûr
				 On le stocke pour l'avoir directement si on ne pose pas nos deux tuiles d'un coup
				 Economie de temps: evite d'en rechercher un nouveau
				 */
				if(!justOne){
					justOne = true;
					result.idxHand[0] = stroke.tile1;
					result.idxHand[1] = stroke.tile2;
					result.tiles[0] = t1;
					result.tiles[1] = t2;
				}
				
				/*Tant qu'il y a des cases vides sur le chemin et que l'on a pas joue*/
				while(iteratorPath2 != path.end() && !played){
		
					// On peut poser t2 ?
					if(putPathPossible(*iteratorPath2, t2) && board->putPossible((iteratorPath2->p).x, (iteratorPath2->p).y, t1)){
						result.idxHand[0] = stroke.tile1;
						result.idxHand[1] = stroke.tile2;
						result.tiles[0] = t1;
						result.tiles[1] = t2;
						t1->setCoordinates(iteratorPath1->p);
						t2->setCoordinates(iteratorPath2->p);
						result.tiles[0] = t1;
						result.tiles[1] = t2;
						played = true;
					}
					iteratorPath2++;
				}
 			}
			iteratorPath1++;
		}
		itStroke++;
	}
	
	/*A-t-on joue les deux tuiles ?
	 * Si oui on a termine et on renvoit le coup
	 * Si non, on regarde si l'on peut mettre une tuile sur le chemin
	 * Si non, alea de la version 1
	 */
	if(!played){
		
		bool put = false;
		
		if(justOne){
			/*On essaie de poser la 2eme tuile aleatoirement*/
			/*Tant qu'il y a des cases vides*/
			itEmpty1 = squareEmpty.begin();
			bool put = false;
			
			while(itEmpty1 != squareEmpty.end() && !put){
				if(board->putPossible(itEmpty1->x, itEmpty1->y, result.tiles[1])){
					result.idxHand[0] = stroke.tile1;
					result.idxHand[1] = stroke.tile2;
					put = true;
				}
			}
		}
		
		/*Rien n'a ete joue, on lance la version precedente easy*/
		if(!put)
			result = easy();
	}
	return result;
};

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
