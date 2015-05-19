#include <PlayedTravel.h>
#include <fstream>

using namespace std;

PlayedTravel::PlayedTravel(int idP, int nbrT, Tile t[]){
    idNextPlayer = idP;
    nbrTiles = nbrT;
    travel = t;
}

PlayedTravel::writePack(int fd){
    stringstream ss;
    ss << idNextPlayer << " " << nbrTiles ;

    for (int i = 0; i<nbrTiles<i++)
	ss << " " << t[i];

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
