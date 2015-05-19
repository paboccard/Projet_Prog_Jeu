#ifndef PRODCOND_H
#define PRODCOND_H

#include <semaphore.h>

template<typename T> class ProdCond;


template<typename T>
class ProdCond{

	public:
		ProdCond(int size = 10);
		~ProdCond();
		void producte(T t);
		T consume();

	private:
		T *table;
		int start;
		int end;
		int nb;
		sem_t semEmpty;
		sem_t semFull;
		pthread_mute_t mutex;
};

#endif
