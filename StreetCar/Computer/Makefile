CXX=g++
CXXFLAGS= -std=c++11 -I../Shared/



test : test.o Computer.o ../Shared/Player.o ../Shared/Tile.o ../Shared/Board.o ../Shared/Stop.o ../Shared/Pile.o ../Shared/Square.o ../Shared/Profile.o ../Shared/Point.o
	$(CXX) $(CXXFLAGS) -o $@ $^
