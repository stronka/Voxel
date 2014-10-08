/*
 *  main.cpp
 *
 */

#include "sdl_main.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Sdl_Main theGame;

    int result = theGame.InitApp();
	
    if (result != 0)
    {
       theGame.ErrorMessage("Error during game initialization");
       theGame.Cleanup();
       std::cout << "Error during game initalization" << std::endl;
       return result;
    }

    theGame.EventLoop();
    theGame.Cleanup();
    
    return 0;
}
