#include "StartedTravel.h"
#include <fstream>

using namespace std;

StartedTravel::StartedTravel(int idP, int nbrT, Tile t[]){
    idPlayer = idP;
    nbrTiles = nbrT;
    travel = t;
}

StartedTravel::writePack(int fd){
    stringstream ss;
    ss << idPlayer << " " << nbrTiles ;

    for (int i = 0; i<nbrTiles<i++)
	ss << " " << t[i];

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
