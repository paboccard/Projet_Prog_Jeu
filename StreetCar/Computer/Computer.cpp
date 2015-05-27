#include "Computer.h"

using namespace std;

Computer::Computer(std::vector<Player> allPlayers,int IAm){
    board= new Board();
    players= allPlayers;
    whoAmI=IAm;
    board.whichTerminus(INFORMATIONS.line,myTerminus);
	pile = new Pile();
    createPath();
}

void Computer::test(){
	
	int stroke[320][4];
	Tile empty = Tile(Empty, -1);
	
	// Calcul de tous les coups possibles avec les tuiles de la main
	player[whoAmI] = strokePossible(stroke[320][4]);
	
	// Pour chaque coup
	for(int i = 0; i < 320 ; i++){
		
		// On recupere les tuiles
		Tile t1 = Tile(stroke[i][0], whoAmI);
		Tile t2 = Tile(stroke[i][2], whoAmI);
		
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
			if(b.putPossible(x,y,players[currentPlayer].hand[index]){
				b.set(x,y,players[currentPlayer].hand[index]);
				put = true;
				it = squareEmpty.erase(*it);
			}
			// On ne peut pas la poser, on teste sa rotation
			// si on ne les a pas toutes testees
			else if(attemptRotation != 3){
				attemptRotation++;
				players[currentPlayer].hand[index].rotate();
			}
			// On essaie une autre tuile de la main
			// si on ne les a pas toutes testees
			else if {attemptHand != 4}{
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
			if(b.putPossible(x,y,players[currentPlayer].hand[index2]){
				b.set(x,y,players[currentPlayer].hand[index2]);
				put = true;
				it = squareEmpty.erase(*it);
			}
			// On ne peut pas la poser, on teste sa rotation
			// si on ne les a pas toutes testees
			else if(attemptRotation != 3){
				attemptRotation++;
				players[currentPlayer].hand[index2].rotate();
			}
			// On essaie une autre tuile de la main
			// si on ne les a pas toutes testees
			else if {attemptHand != 4}{
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
			else players[currentPlayer].hand[index] = Tile(empty, currentPlayer);
			if(!pile.isEmpty()) players[currentPlayer].hand[index2] =  Tile(pile.take(), currentPlayer) ;
			else players[currentPlayer].hand[index2] = Tile(empty, currentPlayer);
			   
			// On passe au joueur suivant
			currentPlayer = (currentPlayer + 1)% players.size(); //(+1 ?)

			//On revient au début du vecteur
			it = squareEmpty.begin();
		}
	}
	
}
