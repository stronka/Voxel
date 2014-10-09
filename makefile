CC=g++
CFLAGS=-c `sdl2-config --libs` -lSDL2_image -lSDL2_mixer -lX11 -lGL -lGLU `sdl2-config --cflags`
LDFLAGS=-lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
SOURCES=main.cpp sdl_engine.cpp media.cpp scene.cpp logger.cpp config.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf game
	rm -rf voxel_log.txt
