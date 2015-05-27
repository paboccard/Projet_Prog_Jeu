#ifndef STARTEDTRAVEL_H
#define STARTEDTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include "Utils.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>


class StartedTravel : public Pack{

 public:
    int idPlayer;
    Travel tram;

    StartedTravel();
    StartedTravel(int idP, Travel travelOfTram);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, StartedTravel &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, StartedTravel &t){
	t.read(f);
	return f;
    };

};

#endif
