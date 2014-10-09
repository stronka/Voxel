#!/bin/bash

g++ -c -o sdl_engine.o sdl_engine.cpp -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o scene.o scene.cpp  -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o media.o media.cpp  -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o logger.o logger.cpp  -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o config.o config.cpp  -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image -lSDL2_mixer
g++ -c -o main.o main.cpp -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image  -lSDL2_mixer
g++ -o game main.o sdl_engine.o scene.o media.o logger.o config.o -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image  -lSDL2_mixer
