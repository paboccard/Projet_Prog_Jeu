CXX = g++
CXXFLAGS = -Wall -c -std=c++11

all: Pile.o TestPile

Pile.o: ../Pile.cpp ../Pile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

TestPile: TestPile.cpp Pile.o
	g++ TestPile.cpp Pile.o -o TestPile -Wall
	
clean:
	rm TestPile *.o