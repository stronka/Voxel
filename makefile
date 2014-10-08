CC=g++
#CFLAGS=`sdl2-config --cflags`
LIBS=-lSDL2 -lSDL2_image -lSDL2_mixer
DEPS=sdl_main.h media.h scene.h
OBJ=sdl_main.o media.o scenee.o main.o

%.o: %.c $(DEPS)
	echo $(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

all: $(OBJ)
	echo $(CC) -o $@ $^ $(CFLAGS) $(LIBS)
