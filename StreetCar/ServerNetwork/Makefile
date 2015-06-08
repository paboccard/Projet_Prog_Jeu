SDL_INCLUDE = -I/usr/local/include -I../Shared/
LDFLAGS = $(LIB)  -I../Shared/ -Wall -pthread

CC=clang++ -g
CFLAGS=-Wall -c -std=c++11 $(SDL_INCLUDE)
SDL_INCLUDE = -I/usr/local/include -I../Shared/

SOURCES=$(wildcard *.cpp) $(wildcard ../Shared/*.cpp)
DEPS=$(patsubst %.cpp, %.dep, $(SOURCES))
OBJ=$(patsubst %.cpp, %.o, $(SOURCES))


serverNetwork: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

-include $(DEPS)

%.dep: %.cpp
	$(CC) -g -MM $< >$@ $(CFLAGS)

#Tile.o:../Shared/Tile.cpp ../Shared/Tile.h
#	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep *.h.gch ../Shared/*.h.gch
