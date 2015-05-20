#include <StoppedTravel.h>
#include <fstream>

using namespace std;

StoppedTravel::StoppedTravel(int idP){
    idNextPlayer = idP;
}

StoppedTravel::writePack(int fd){
    stringstream ss;
    ss << idNextPlayer;

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
