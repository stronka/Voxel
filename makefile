CXX=g++
CFLAGS=-c `sdl2-config --cflags`
LDFLAGS=-lX11 -lGL -lGLU -lSDL2 -lSDL2_image -lSDL2_mixer
SOURCES=main.cpp sdl_engine.cpp media.cpp config.cpp scene.cpp logger.cpp pugixml.cpp character.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) -o $@ $^  $(LDFLAGS)

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf game
	rm -rf voxel_log.txt
