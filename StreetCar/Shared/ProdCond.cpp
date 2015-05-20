#include "ProdCond.h"

ProdCond<T>::ProdCond(int size) {
	nb = size;
	start = 0;
	end = 0;
	table = malloc(sizeof(T)*size);
	sem_init(&semEmpty, 0, size);
	sem_init(&semFull, 0, 0);
	pthread_mutex_init(&mutex, NULL);
}

ProdCond<T>::~ProdCond() {
	free(table);
	sem_destroy(&semEmpty);
	sem_destroy(&semFull);
	pthread_mutex_destroy(&mutex);
}

void ProdCond<T>::producte(T t) {
	sem_wait(&semEmpty);
	pthread_mutex_lock(&mutex);

	table[start] = t;
	start = (start+1)%nb;

	pthread_mutex_unlock(&mutex);
	sem_post(&semFull);
}

T ProdCond<T>::condume() {
	sem_wait(&semFull);
	pthread_mutex_lock(&mutex);

	T t = table[end];
	end = (end+1)%nb;

	pthread_mutex_unlock(&mutex);
	sem_post(&semEmpty);
}
