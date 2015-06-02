CXX = g++
CXXFLAGS = -Wall -c -std=c++11

all: Pile.o Tile.o Player.o Square.o Profile.o Stop.o Board.o TestPile TestSquare TestPlayer TestTile TestBoard
	rm *.o

Pile.o: ../Pile.cpp ../Pile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Stop.o: ../Stop.cpp ../Stop.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Board.o: ../Board.cpp ../Board.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Tile.o: ../Tile.cpp ../Tile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Square.o: ../Square.cpp ../Square.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: ../Player.cpp ../Player.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Profile.o: ../Profile.cpp ../Profile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

TestTile: TestTile.cpp Tile.o Square.o
	g++ TestTile.cpp Tile.o Square.o -o TestTile -Wall

TestPile: TestPile.cpp Pile.o
	g++ TestPile.cpp Pile.o -o TestPile -Wall

TestBoard: TestBoard.cpp Board.o Tile.o Square.o Stop.o
	g++ TestBoard.cpp Board.o Tile.o Square.o Stop.o -o TestBoard -Wall

TestSquare: TestSquare.cpp Square.o
	g++ TestSquare.cpp Square.o -o TestSquare -Wall

TestPlayer: TestPlayer.cpp Player.o Tile.o Profile.o Square.o
	g++ TestPlayer.cpp Player.o Tile.o Profile.o Square.o -o TestPlayer -Wall
	
clean:
	rm TestPile TestSquare TestTile TestPlayer TestBoard *.o