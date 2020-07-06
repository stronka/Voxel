CXX=g++
CFLAGS=-Wall -Wextra --std=c++17 -ggdb -O0

SOURCES=$(wildcard *.cpp)
LDFLAGS=-lX11 -lGL -lGLU -lSDL2 -lSDL2_image -lSDL2_mixer
SDL_INCLUDE=-IC:/MinGW/include/SDL2
INCLUDE=$(SDL_INCLUDE)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(OBJECTS) 
	$(CXX) $(INCLUDE) -o $(EXECUTABLE) $< $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf $(EXECUTABLE)
	rm -rf *log.txt
