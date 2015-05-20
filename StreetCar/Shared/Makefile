CXX = g++
CXXFLAGS = -Wall -c -std=c++11


Tile.o: Tile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayTile.o: Pack.h PlayTile.h PlayTile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Pack.o: Pack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Clean:
	rm *.o