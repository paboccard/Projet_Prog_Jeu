#include "InitGame.h"

using namespace std;

InitGame::InitGame(vector<std::array<Tile,5>> h, Pile p, int firstP, vector<GoalPlayer> goalP){
    idPack = INITGAME;
    hands = h;
    pile = p;
    idFirstPlayer = firstP;
    goalPlayer = goalP;
    }

ostream& operator << (std::ostream &f, InitGame &t){
    f << INITGAME << " ";
    f << t.hands.size() << " ";
    for (unsigned int i = 0; i<t.hands.size(); i++)
	for (int j = 0; j<5; j++)
	    f << t.hands[i][j] << " ";
    f << t.pile << " "; //TODO redefinition of ostream & istream in Pile
    f << t.idFirstPlayer << " ";
    f << t.goalPlayer.size() << " ";
    for (unsigned int i=0; i<t.goalPlayer.size(); i++){
	for (int j = 0; j<6 ; j++){
	    for (int k = 0; k<3; k++)
		f << t.goalPlayer[i].stop.card[j][k] << " ";
	}
	f << t.goalPlayer[i].line << " ";
	}

   return f;
}

istream& operator >> (std::istream &f, InitGame &t){
    int pa;
    f >> pa;
    t.idPack = INITGAME;
    int sizeOfHands;
    f >> sizeOfHands;

    t.hands.clear();
    for (int i = 0; i<sizeOfHands; i++){
	array<Tile,5> h;
	for (int j = 0; j<5; j++){
	    Tile tile;
	    f >> tile;
	    h[i] = tile;
	}
	t.hands.push_back(h);
    }
    Pile p;
    f >> p;
    t.pile = p;

    f >> t.idFirstPlayer;
    int sizeGoalPlayer;
    f >> sizeGoalPlayer;
    t.goalPlayer.clear();
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
	t.goalPlayer.push_back(gp);
    }
    return f;
}

