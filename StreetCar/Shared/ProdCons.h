#ifndef PRODCOND_H
#define PRODCOND_H

#include <semaphore.h>
#include <vector>
#include <cstddef>
#include <iostream>

using namespace std;

template<class T>
class ProdCons{

	public:
		ProdCons(int size = 10);
		~ProdCons();
		void produce(T t);
		T consume();

	private:
		std::vector<T> table;
		int start;
		int end;
		int nb;
		sem_t semEmpty;
		sem_t semFull;
		pthread_mutex_t mutex;

};

template<class T>
ProdCons<T>::ProdCons(int size) : table(size){
	nb = size;
	start = 0;
	end = 0;
	//table = static_cast<T*>(malloc(sizeof(T)*size));
	sem_init(&semEmpty, 0, size);
	sem_init(&semFull, 0, 0);
	pthread_mutex_init(&this->mutex, NULL);

}

template<class T>
ProdCons<T>::~ProdCons() {
	sem_destroy(&semEmpty);
	sem_destroy(&semFull);
	pthread_mutex_destroy(&this->mutex);
}

template<class T>
void ProdCons<T>::produce(T t) {

    cout << "wait produce " << pthread_self() << endl;
	sem_wait(&semEmpty);
	pthread_mutex_lock(&this->mutex);

	cout << "produce " << pthread_self() << endl;
	table[start] = t;
	start = (start+1)%nb;

	pthread_mutex_unlock(&this->mutex);
	sem_post(&semFull);
}

template<class T>
T ProdCons<T>::consume() {

	cout << "wait consume " << pthread_self() << endl;
	sem_wait(&semFull);
	pthread_mutex_lock(&this->mutex);

	cout << "consume " << pthread_self() << endl;
	T t = table[end];
	end = (end+1)%nb;

	pthread_mutex_unlock(&this->mutex);
	sem_post(&semEmpty);

	return t;
}

#endif
