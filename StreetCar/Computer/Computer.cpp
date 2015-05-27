#include "Computer.h"

using namespace std;

Computer::Computer(std::vector<Player> allPlayers,int IAm){
    board = Board();
    players= allPlayers;
    whoAmI=IAm;
    pile =Pile();    
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
    vector<Point> listOfPoint;
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
    // if(isVert && firstIsLeftOrDown)
    // 	listOfPoint.push_back(StationOrder[0].coordinates.y+1>myTerminus[0][0].y ? )

    return StationOrder;
}

void Computer::test(){
	
	int stroke[320][4] = {0};
	Tile empty = Tile(Empty, -1);
	
	// Calcul de tous les coups possibles avec les tuiles de la main
	players[whoAmI].strokePossible(stroke);
	
	// Pour chaque coup
	for(int i = 0; i < 320 ; i++){
		
		// On recupere les tuiles
		Tile t1 = Tile((idTile) stroke[i][0], whoAmI);
		Tile t2 = Tile((idTile) stroke[i][2], whoAmI);
		
		// Rotation de la tuile 1
		for(int j = 0; j < stroke[i][1] ; j++){
			t1.rotate();
		}
		
		// Rotation de la tuile 2
		for(int j = 0; j < stroke[i][3] ; j++){
			t2.rotate();
		}
		
		/* Nous avons les deux tuiles bien positionnées (orientées)
		 * On essaie de placer la tuile t1 sur chaque case libre
		 * Des que l'on a trouve une case, on essaie de placer la tuile t2
		 * sur chaque case libre a son tour
		 * Si l'on place les deux tuiles, on lance l'algo
		 * Sinon on passe a la case libre suivante pour t2
		 * Si on a tout essaye pour t2, on avance dans t1,
		 * Si on a tout essaye pour t1, on passe au couple suivante
		 * Si on a tout essaye, c'est fini !!
		*/
		
		for(int i = 1; i < 13 ; i++){
			for(int j = 1 ; j < 13 ; j++){
				
				// On peut poser t1 ?
				if(board.putPossible(i,j,t1)){
					
					//On place la tuile
					boardTmp.copy(board);
					boardTmp.set(i,j,t1);
					
					for(int x = 1 ; x < 13 ; x++){
						for(int y = 1 ; y < 13 ; y++){
							if(boardTmp.putPossible(x,y,t2)){
								boardTmp.set(x,y,t2);
								cout << "T1: " << i << " " << j << "  T2: " << x << " " << y << "ALGO !" << endl;
								boardTmp.set(x,y,empty);
							}
						}
					}
				}
			}
		}
	}
}

void Computer::allAlea(Board b, Pile pile){
	/* L'IA a joué ses tuiles, il doit piocher ? NON, PIOCHER AVANT DE VENIR ET CHANGER LE PLAYER AVANT*/
	
	bool possible = true, put;
	Point p;
	int x, y, index, index2, turn, attemptHand, attemptRotation, currentPlayer;
	
	/*On recupere dans un vecteur toutes les cases libres du board*/
	vector<Point> squareEmpty;
	for(int i = 1; i < 13; i++){
		for(int j = 1 ; j < 13 ; j++){
			if(b.get(i,j).isEmpty()) squareEmpty.push_back((Point) {i,j});
		}
	}
	
	/*On melange le vecteur*/
	srand ( unsigned ( std::time(0) ) );
	random_shuffle ( squareEmpty.begin(), squareEmpty.end() );
	
	// On se place au debut du vecteur
	std::vector<Point>::iterator it = squareEmpty.begin();
	
	//Tant qu'il y a des cases libres et que les joueurs ne sont pas bloqués
	while(!squareEmpty.empty() && possible){
		
		/*On prend une case libre du vecteur*/
		p = *it;
		x = p.x;
		y = p.y;
		
		/*Tirage d'une tuile de la main*/
		index = rand() % 5;
		
		//Tirage d'une orientation aleatoire
		turn = rand() % 4;
		
		//Rotation de la piece en main
		for(int i = 0 ; i < turn ; i++){
			players[currentPlayer].hand[index].rotate();
		}
		
		put = false;
		attemptRotation = 0;
		attemptHand = 0;
		
		//Tant qu'on n'a pas posee la tuile 
		//On essaie la tuile de la main, 
		while(!put && it != squareEmpty.end()){
			// On peut la poser
			if(b.putPossible(x,y,players[currentPlayer].hand[index])){
				b.set(x,y,players[currentPlayer].hand[index]);
				put = true;
				it = squareEmpty.erase(it);
			}
			// On ne peut pas la poser, on teste sa rotation
			// si on ne les a pas toutes testees
			else if(attemptRotation != 3){
				attemptRotation++;
				players[currentPlayer].hand[index].rotate();
			}
			// On essaie une autre tuile de la main
			// si on ne les a pas toutes testees
			else if (attemptHand != 4){
				attemptHand++;
				index = (index + 1)%5;
				
				//Tirage d'une orientation aleatoire
				turn = rand() % 4;
		
				//Rotation de la piece en main
				for(int i = 0 ; i < turn ; i++){
					players[currentPlayer].hand[index].rotate();
				}
				attemptRotation = 0;
			}
			//Toute la main a été testée
			//On passe a la case suivante
			else {
				it++;
				attemptHand = 0;
				attemptRotation = 0;
			}
		}
		
		// On a pas poser de tuile, la main du joueur est bloquee
		if(!put) possible = false;
		else put = false;
			   
		//Pose de la deuxieme tuile
		while(!put && it != squareEmpty.end() && possible){
			
			/*On prend une case libre du vecteur*/
			p = *it;
			x = p.x;
			y = p.y;
			
			/*Tirage d'une tuile de la main, differente de la precedente*/
			do{
				index2 = rand() % 5;
			}
			while(index2 != index);

			//Tirage d'une orientation aleatoire
			turn = rand() % 4;
			
			//Rotation de la piece en main
			for(int i = 0 ; i < turn ; i++){
				players[currentPlayer].hand[index2].rotate();
			}
			
			put = false;
			attemptRotation = 0;
			attemptHand = 0;			
			
			// On peut la poser
			if(b.putPossible(x,y,players[currentPlayer].hand[index2])){
				b.set(x,y,players[currentPlayer].hand[index2]);
				put = true;
				it = squareEmpty.erase(it);
			}
			// On ne peut pas la poser, on teste sa rotation
			// si on ne les a pas toutes testees
			else if(attemptRotation != 3){
				attemptRotation++;
				players[currentPlayer].hand[index2].rotate();
			}
			// On essaie une autre tuile de la main
			// si on ne les a pas toutes testees
			else if (attemptHand != 4){
				attemptHand++;
				index2 = (index2 + 1)%5;
				
				//Tirage d'une orientation aleatoire
				turn = rand() % 4;
		
				//Rotation de la piece en main
				for(int i = 0 ; i < turn ; i++){
					players[currentPlayer].hand[index2].rotate();
				}
				
				attemptRotation = 0;
			}
			//Toute la main a été testée
			//On passe a la case suivante
			else {
				it++;
				attemptHand = 0;
				attemptRotation = 0;
			}
		}

		// On a pas poser de tuile, la main du joueur est bloquee
		if(!put) possible = false; 
		//On pioche, on passe au joueur suivant, on repart au debut du vecteur
		else {
			//Le joueur pioche 2 tuiles si possible
			if(!pile.isEmpty()) players[currentPlayer].hand[index] = Tile(pile.take(), currentPlayer) ;
			else players[currentPlayer].hand[index] = Tile(Empty, currentPlayer);
			if(!pile.isEmpty()) players[currentPlayer].hand[index2] =  Tile(pile.take(), currentPlayer) ;
			else players[currentPlayer].hand[index2] = Tile(Empty, currentPlayer);
			   
			// On passe au joueur suivant
			currentPlayer = (currentPlayer + 1)% players.size(); //(+1 ?)

			//On revient au début du vecteur
			it = squareEmpty.begin();
		}
	}
}
