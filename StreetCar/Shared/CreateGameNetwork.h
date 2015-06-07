#ifndef CREATEGAMENETWORK_H
#define CREATEGAMENETWORK_H

#include "Profile.h"
#include "Pack.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ProdCons.h"

using namespace std;

class CreateGameNetwork : public Pack{
    
 public:
    
  int nbrPlayer;
  string nameGame;
  ProdCons<Pack*> *prodConsClient;

	CreateGameNetwork();
	CreateGameNetwork(int nbrP, string nameG);

	void print(std::ostream& f);
	void read(std::istream& f);

	friend ostream& operator << (ostream &f, CreateGameNetwork &t){
		t.print(f);
		return f;
	};
	friend istream& operator >> (istream &f, CreateGameNetwork &t){
		t.read(f);
		return f;
	};
};

#endif
