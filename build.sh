#!/bin/bash

g++ -c -o sdl_main.o sdl_main.cpp -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o scene.o scene.cpp  -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o media.o media.cpp  -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o main.o main.cpp -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image  -lSDL2_mixer
g++ -o game main.o sdl_main.o scene.o media.o -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image  -lSDL2_mixer
