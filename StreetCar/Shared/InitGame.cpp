#include "InitGame.h"

using namespace std;

InitGame::InitGame() : Pack(INITGAME) {} 

InitGame::InitGame(vector<vector<Tile> > h, int firstP, GoalPlayer goalP) : Pack(INITGAME){
    hands = h;
    idFirstPlayer = firstP;
    goalPlayer = goalP;
}

void InitGame::print(ostream& f){
    Pack::print(f);
    f << hands.size() << " ";
    for (unsigned int i = 0; i<hands.size(); i++)
	for (int j = 0; j<5; j++)
	    f << hands[i][j] << " ";
    f << idFirstPlayer << " ";
    for (int j = 0; j<6 ; j++){
	for (int k = 0; k<3; k++)
	    f << goalPlayer.stop.card[j][k] << " ";
    }
    f << goalPlayer.line << " ";
}

void InitGame::read(istream& f){
	int sizeOfHands;
	f >> sizeOfHands;

	hands.clear();
	for (int i = 0; i<sizeOfHands; i++){
		vector<Tile> h;
		h.clear();
		for (int j = 0; j<5; j++){
			Tile tile;
			f >> tile;
			h.push_back(tile);
		}
		hands.push_back(h);
	}
	hands.push_back(h);
    }
    f >> idFirstPlayer;
    Card card;
    for (int j=0; j<6; j++){
	for (int k=0; k<3; k++){
	    f >> card.card[j][k];
	}
    }
    int l;
    f >> l;
    GoalPlayer gp;
    gp.stop = card;
    gp.line = l;
    goalPlayer = gp;
    
}

