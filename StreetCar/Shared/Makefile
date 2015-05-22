CXX = g++
CXXFLAGS = -Wall -c -std=c++11

All: Tile.o Square.o Board.o Stop.o PlayTile.o Pack.o Pile.o Player.o Profile.o Clean

Tile.o: Tile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
Stop.o: Stop.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Pile.o: Pile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Square.o: Square.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayTile.o: Pack.h PlayTile.h PlayTile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Pack.o: Pack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Profile.o: Profile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Clean:
	rm *.o
