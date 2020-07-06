CXX=g++
CFLAGS=-Wall -Wextra --std=c++17

SOURCES=$(wildcard *.cpp)
LDFLAGS=-lX11 -lGL -lGLU -lSDL2 -lSDL2_image -lSDL2_mixer
SDL_INCLUDE=-IC:/MinGW/include/SDL2
INCLUDE=$(SDL_INCLUDE)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(INCLUDE) -o $@ $^  $(LDFLAGS)

.cpp.o:
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf game
	rm -rf voxel_log.txt
