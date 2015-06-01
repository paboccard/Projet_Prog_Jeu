#include<iostream>
#include<vector>
#include "../Computer.h"



int main() {
	
	vector<Player> allPlayers;
	Pile p = Pile();
	
	allPlayers.resize(2);
	allPlayers[0] = Player();
	allPlayers[1] = Player();
	
	allPlayers[0].hand[0] = p.take();
	allPlayers[0].hand[1] = p.take();
	allPlayers[0].hand[2] = p.take();
	allPlayers[0].hand[3] = p.take();
	allPlayers[0].hand[4] = p.take();
	
	allPlayers[1].hand[0] = p.take();
	allPlayers[1].hand[1] = p.take();
	allPlayers[1].hand[2] = p.take();
	allPlayers[1].hand[3] = p.take();
	allPlayers[1].hand[4] = p.take();
	cout << "deb init" << endl;
	Computer c = Computer(allPlayers, 2, p);
	cout << "end init" << endl;
	c.monteCarlo();
	
	return 0;
}