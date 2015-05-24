CXX = g++
CXXFLAGS = -Wall -c -std=c++11

all: Pile.o Square.o TestPile TestSquare

Pile.o: ../Pile.cpp ../Pile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Square.o: ../Square.cpp ../Square.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

TestPile: TestPile.cpp Pile.o
	g++ TestPile.cpp Pile.o -o TestPile -Wall

TestSquare: TestSquare.cpp Square.o
	g++ TestSquare.cpp Square.o -o TestSquare -Wall
	
clean:
	rm TestPile TestSquare *.o