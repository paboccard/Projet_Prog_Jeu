LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib -lSDL2_image -lSDL2_ttf -lpthread
SDL_INCLUDE = -I/usr/local/include
LDFLAGS = $(LIB) 

CC=g++
CFLAGS=-Wall -c -std=c++11 $(SDL_INCLUDE) 
SOURCES=$(wildcard *.cpp)
DEPS=$(patsubst %.cpp, %.dep, $(SOURCES))
OBJ=$(patsubst %.cpp, %.o, $(SOURCES))


streetCar: ../Shared/ProdCons.h $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEPS)

%.dep: %.cpp
	$(CC) -MM $< >$@ $(CFLAGS)

clean:
	rm *.o *.dep
