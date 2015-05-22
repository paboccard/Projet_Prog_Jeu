LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib -lSDL2_image -lSDL2_ttf -lpthread
SDL_INCLUDE = -I/usr/local/include -I../Shared/
LDFLAGS = $(LIB)  -I../Shared/

CC=g++
CFLAGS=-Wall -c -std=c++11 $(SDL_INCLUDE) 
SOURCES=$(wildcard *.cpp) $(wildcard ../Shared/*.cpp)
DEPS=$(patsubst %.cpp, %.dep, $(SOURCES))
OBJ=$(patsubst %.cpp, %.o, $(SOURCES))


streetCar: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEPS)

%.dep: %.cpp
	$(CC) -MM $< >$@ $(CFLAGS)

#Tile.o:../Shared/Tile.cpp ../Shared/Tile.h
#	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep
