SDL_INCLUDE = -I/usr/local/include -I../../Shared/                                                              

SOURCES=$(wildcard *.cpp) $(wildcard ../../Shared/*.cpp) $(wildcard ../Computer.cpp)
DEPS=$(patsubst %.cpp, %.dep, $(SOURCES))
OBJ=$(patsubst %.cpp, %.o, $(SOURCES))


TestComputer: $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^
	rm *.o

-include $(DEPS)

%.dep: %.cpp
	$(CXX) -MM $< >$@ $(CXXFLAGS)

clean:
	rm *.o *.dep ../../Shared/*.o ../../Shared/*.dep *.h.gch ../../Shared/*.h.gch
	
cleanAll:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep *.h.gch ../../Shared/*.h.gch TestComputer