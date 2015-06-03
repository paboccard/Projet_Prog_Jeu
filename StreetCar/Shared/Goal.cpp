#include "Goal.h"

using namespace std;

Goal::Goal() : Pack(GOAL) {} 

Goal::Goal(int idP, GoalPlayer goalP) : Pack(GOAL){
    idPlayer = idP;
    goalPlayer = goalP;
}

void Goal::print(ostream& f){
	Pack::print(f);
	f << idPlayer << " ";
	f << goalPlayer.stop << " ";
	f << goalPlayer.line;
}

void Goal::read(istream& f){
	f >> idPlayer;
	Card card;
	f >> card;
	int l;
	f >> l;
 	GoalPlayer gp;
	gp.stop = card;
	gp.line = l;
	goalPlayer = gp;

}

