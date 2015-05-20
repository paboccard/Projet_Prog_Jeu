#include <iostream>
#include <pthread.h>

int main(int argc, char* argv[])
{
	GraphicData data();

	pthread_t threadEvent;
	pthread_create(&threadEvent, NULL, event, (void*)data);
	
}
