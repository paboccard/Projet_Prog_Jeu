SDL_INCLUDE = -I/usr/local/include -I../Shared/                                                              

LDFLAGS = $(LIB) -I../Shared -pthread

CC=g++
CFLAGS=-Wall -std=c++11 $(SDL_INCLUDE)
SOURCES=$(wildcard *.cpp) $(wildcard ../Shared/*.cpp)
DEPS=$(patsubst %.cpp, %.dep, $(SOURCES))
OBJ=$(patsubst %.cpp, %.o, $(SOURCES))


server: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

-include $(DEPS)

%.dep: %.cpp
	$(CC) $(CFLAGS) -MM $< >$@

clean:
	rm *.o *.dep ../Shared/*.o ../Shared/*.dep

#LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib -lSDL2_image -lSDL2_ttf