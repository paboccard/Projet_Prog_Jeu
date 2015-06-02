CXX = g++
CXXFLAGS = -Wall -c -std=c++11

All: PileTarget.o Card.o Tile.o Square.o Board.o Station.o Pack.o StartTravel.o PlayTravel.o StopTravel.o Point.o PlayTile.o PlayedTile.o PlayedTravel.o StartedTravel.o StoppedTravel.o Won.o PilePlayer.o PileWhenTravel.o Player.o Profile.o IWantPlay.o NewPlayerAdd.o clean

IWantPlay.o: IWantPlay.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

NewPlayerAdd.o: NewPlayerAdd.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

Tile.o: Tile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Card.o: Card.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PileTarget.o: PileTarget.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Station.o: Station.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Square.o: Square.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Board.o: Board.cpp
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

Profile.o: Profile.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o

Clean:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep
