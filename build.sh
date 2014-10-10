#!/bin/bash

g++ -c -o sdl_engine.o sdl_engine.cpp `sdl2-config --cflags`
g++ -c -o scene.o scene.cpp `sdl2-config --cflags`
g++ -c -o media.o media.cpp `sdl2-config --cflags`
g++ -c -o logger.o logger.cpp  `sdl2-config --cflags`
g++ -c -o config.o config.cpp  `sdl2-config --cflags`
g++ -c -o character.o character.cpp `sdl2-config --cflags`
g++ -c -o pugixml.o pugixml.cpp `sdl2-config --cflags`
g++ -c -o main.o main.cpp `sdl2-config --cflags`
echo g++ -o game main.o sdl_engine.o scene.o media.o logger.o config.o character.o pugixml.o -lX11 -lGL -lGLU `sdl2-config --libs` -lSDL2_image  -lSDL2_mixer
