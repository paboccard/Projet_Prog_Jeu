#include "InitGame.h"

using namespace std;

InitGame::InitGame(vector<Hand> h, Pile p, int firstP, vector<GoalPlayer> goalP){
    idPack = INITGAME;
    hands = h;
    pile = p;
    firstPlayer = firstP;
    goalPlayer = goalP;
}

ostream& operator << (std::ostream &f, InitGame &t){
    f << INITGAME << " ";
    f << t.hands.size() << " ";
    for (unsigned int i = 0; i<t.hands.size(); i++)
	for (int j = 0; j<5; j++)
	    f << t.hands[i][j] << " ";
    for (int i = 0; i<12; i++)
	f << t.pile.type[i] << " ";
    f << t.idFirstPlayer << " ";
    f << t.goalPlayer.size() << " ";
    for (int i=0; i<t.goalPlayer.size(); i++)
	f << t.goalPlayer[i] << " ";

    return f;
}

istream& operator >> (std::istream &f, InitGame &t){
    f >> INITGAME;
    int sizeOfHands;
    f >> sizeOfHands;
    
    for (unsigned int i = 0; i<sizeOfHands; i++){
	for (int j = 0; j<5; j++){
	    Tile tile;
	    Hand h;
	    f >> tile;
	    h[i] = tile;
	}
	t.hands.push_back(h);
    }
    for (int i = 0; i<12; i++)
	f >> t.pile.type[i]

    f >> t.idFirstPlayer;
    int sizeGoalPlayer;
    f >> sizeGoalPlayer;
    for (int i=0; i<sizeGoalPlayer; i++){
	StopCard card;
	f >> card;
	f >> l;
	GoalPlayer gp;
	gp.stop = card;
	gp.line = l;
	t.goalPlayer.push_back(gp);
    }
    return f;
}

