#include "Computer.h"

using namespace std;

Computer::Computer(std::vector<Player> allPlayers,int IAm){
    board = Board();
    players= allPlayers;
    whoAmI=IAm;
    board.whichTerminus(INFORMATIONS.line,myTerminus);
}
