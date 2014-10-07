#!/bin/bash

g++ -c -o GameApp.o GameApp.cpp -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image
g++ -c -o main.o main.cpp -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image
g++ -o game main.o GameApp.o -lX11 -lGL -lGLU `sdl2-config --cflags` `sdl2-config --libs` -lSDL2_image
