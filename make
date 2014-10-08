CC=g++
CFLAGS=$(sdl2-config --cflags)
LIBS=$(sdl2-config --libs)
DEPS=gameApp.h loadImage.h
OBJ=gameApp.o loadImage.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
