SDL_INCLUDE = -I/usr/local/include -I../Shared/
LDFLAGS = $(LIB)  -I../Shared/ -Wall -pthread

CXX=g++
CXXFLAGS=-Wall -c -std=c++11 $(SDL_INCLUDE)
SDL_INCLUDE = -I/usr/local/include -I../Shared/                                                              

SOURCES=$(wildcard *.cpp) $(wildcard ../Shared/*.cpp)
DEPS=$(patsubst %.cpp, %.dep, $(SOURCES))
OBJ=$(patsubst %.cpp, %.o, $(SOURCES))


applicationComputer: $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^
	rm *.o

-include $(DEPS)

%.dep: %.cpp
	$(CXX) -MM $< >$@ $(CXXFLAGS)

#Tile.o:../Shared/Tile.cpp ../Shared/Tile.h
#	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep *.h.gch ../Shared/*.h.gch
	
cleanAll:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep *.h.gch ../Shared/*.h.gch applicationComputer
