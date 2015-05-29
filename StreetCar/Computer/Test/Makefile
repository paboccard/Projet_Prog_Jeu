CXX = g++
CXXFLAGS = -Wall -c -std=c++11

all: Pile.o Tile.o Player.o Square.o Profile.o Computer.o Test

Pile.o: ../../Shared/Pile.cpp ../../Shared/Pile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Tile.o: ../../Shared/Tile.cpp ../../Shared/Tile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Square.o: ../../Shared/Square.cpp ../../Shared/Square.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: ../../Shared/Player.cpp ../../Shared/Player.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Profile.o: ../../Shared/Profile.cpp ../../Shared/Profile.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Board.o: ../../Shared/Board.cpp ../../Shared/Board.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Stop.o: ../../Shared/Stop.cpp ../../Shared/Stop.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Computer.o: ../Computer.cpp ../Computer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Point.o: ../../Shared/Point.cpp ../../Shared/Point.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Test: Test.cpp Computer.o Player.o Tile.o Pile.o Board.o Square.o Stop.o Profile.o Point.o
	g++ Test.cpp Computer.o Player.o Tile.o Pile.o Board.o Square.o Stop.o Profile.o Point.o -o Test -Wall
	
clean:
	rm Test *.o