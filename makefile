CC=g++
#CFLAGS=$(sdl2-config --cflags)
#LIBS=$(sdl2-config --libs) -lSDL2_image -lSDL2_mixer
LIBS=-lSDL2 -lSDL2_image -lSDL2_mixer
DEPS=sdl_engine.h media.h scene.h logger.h config.h
OBJ=sdl_engine.o media.o scenee.o logger.o config.o main.o

%.o: %.c $(DEPS)
	echo $(CC) -c -o $(CFLAGS) $(LIBS) $@ $< 

all: $(OBJ)
	echo $(CC) -o $(CFLAGS) $(LIBS) $@ $^
