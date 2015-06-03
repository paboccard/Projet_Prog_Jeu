#include "Goal.h"

using namespace std;

Goal::Goal() : Pack(GOAL) {} 

Goal::Goal(GoalPlayer goalP) : Pack(GOAL){
    goalPlayer = goalP;
}

void Goal::print(ostream& f){
	Pack::print(f);
	f << goalPlayer.stop << " ";
	f << goalPlayer.line;
}

void Goal::read(istream& f){
	int idPack;
	f >> idPack;
	Card card;
	f >> card;
	int l;
	f >> l;
 	GoalPlayer gp;
	gp.stop = card;
	gp.line = l;
	goalPlayer = gp;

}

