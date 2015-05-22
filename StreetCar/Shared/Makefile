CXX = g++
CXXFLAGS = -Wall -c -std=c++11

All: Tile.o Square.o Board.o PlayTile.o Pack.o StartTravel.o PlayTravel.o StopTravel.o PlayTile.o PlayedTile.o PlayedTravel.o StartedTravel.o StoppedTravel.o Won.o PilePlayer.o PileWhenTravel.o Player.o Profile.o Clean

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

StartTravel.o: StartTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayTravel.o: PlayTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

StopTravel.o : StopTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayTile.o: PlayTile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayedTile.o: PlayedTile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayedTravel.o: PlayedTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

StartedTravel.o: StartedTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

StoppedTravel.o: StoppedTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Won.o: Won.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PilePlayer.o: PilePlayer.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PileWhenTravel.o: PileWhenTravel.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Profile.o: Profile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Clean:
	rm *.o
