#include <StopTravel.h>
#include <fstream>

using namespace std;

StopTravel::StopTravel(int idP){
    idPlayer = idP;
}

StopTravel::writePack(int fd){
    stringstream ss;
    ss << idPlayer;

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
