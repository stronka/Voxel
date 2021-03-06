EXECUTABLE=game

CXX=g++
CFLAGS=-Wall -Wextra --std=c++17 -ggdb -O0

SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

LDFLAGS=-lX11 -lGL -lGLU -lSDL2 -lSDL2_image -lSDL2_mixer
SDL_INCLUDE=-IC:/MinGW/include/SDL2
INCLUDE=$(SDL_INCLUDE)

.DEFAULT_GOAL: all
.PHONY: all
all: $(OBJECTS) 
	$(CXX) $(INCLUDE) $(LDFLAGS) -o $(EXECUTABLE) $< 

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf $(EXECUTABLE)
	rm -rf *log.txt
