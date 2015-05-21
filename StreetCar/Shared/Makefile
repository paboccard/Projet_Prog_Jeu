CXX = g++
CXXFLAGS = -Wall -std=c++11

All: Tile.o Board.o PlayTile.o Pack.o Clean
#Pack.o: Pack.h
#	$(CXX) $(CXXFLAGS) -c $^ -o $@

all : clean

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayTile.o: Pack.h PlayTile.h PlayTile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
# main: main.o Tile.o Square.o
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# client: client.o Tile.o Square.o 
# 	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm *.o
