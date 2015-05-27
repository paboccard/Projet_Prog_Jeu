#include "InitGame.h"

using namespace std;

InitGame::InitGame() : Pack() {} 

InitGame::InitGame(vector<vector<Tile> > h, Pile p, int firstP, vector<GoalPlayer> goalP) : Pack(){
    idPack = INITGAME;
    hands = h;
    pile = p;
    idFirstPlayer = firstP;
    goalPlayer = goalP;
}

void InitGame::print(ostream& f){
    f << INITGAME << " ";
    f << hands.size() << " ";
    for (unsigned int i = 0; i<hands.size(); i++)
	for (int j = 0; j<5; j++)
	    f << hands[i][j] << " ";
    f << pile << " "; //TODO redefinition of ostream & istream in Pile
    f << idFirstPlayer << " ";
    f << goalPlayer.size() << " ";
    for (unsigned int i=0; i<goalPlayer.size(); i++){
	for (int j = 0; j<6 ; j++){
	    for (int k = 0; k<3; k++)
		f << goalPlayer[i].stop.card[j][k] << " ";
	}
	f << goalPlayer[i].line << " ";
    }
}

void InitGame::read(istream& f){
    int pa;
    f >> pa;
    idPack = INITGAME;
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
    Pile p;
    f >> p;
    pile = p;

    f >> idFirstPlayer;
    int sizeGoalPlayer;
    f >> sizeGoalPlayer;
    goalPlayer.clear();
    for (int i=0; i<sizeGoalPlayer; i++){
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
	goalPlayer.push_back(gp);
    }
}

