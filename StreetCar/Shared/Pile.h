#ifndef PILE_H
#define PILE_H
#include <stdlib.h>    
#include <time.h> 
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <vector>

/* class Pile { */
	
/* public: */
/*     Pile(); */
/*     idTile take(); */
/*     bool isEmpty(); */
/*     void updatePile(idTile t); */

/*     int types[12]; */
/*     int total; */

/*     friend std::ostream& operator << (std::ostream &f, Pile &p); */
/*     friend std::istream& operator >> (std::istream &f, Pile &p); */
/* }; */

using namespace std;

template<class T>
class Pile{
 public:
    Pile();
    ~Pile();

    T* take();
    void push(T elem, int nbr = 1);
    void wrap();
    bool isEmpty();
    
    vector<T> element;
};

template<class T>
Pile<T>::Pile(){
    element.clear();
}

template<class T>
void Pile<T>::push(T elem, int nbr){
    for (int i=0; i<nbr; i++)
	element.push_back(elem);
}

template<class T>
void Pile<T>::wrap(){
    srand(time(NULL));
    vector<T> tmp(element.size());
    for (unsigned int i = 0; i<element.size(); i++){
	int alea = rand() % (element.size()-i);
	tmp[i] = element[alea];
    }
    element.clear();
    //    for (unsigned i = 0; i<tmp.size(); i++)
    //	element.push_back(tmp[i]);
    element = tmp;
}

template<class T>
T* Pile<T>::take(){
    T *elem;
    *elem = element[element.size()];
    element.pop_back();
    return elem;
}

template<class T>
bool Pile<T>::isEmpty(){
    return element.size()==0;
}

#endif
