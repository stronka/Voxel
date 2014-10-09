/*
 *  main.cpp
 *
 */

#include <iostream>
#include "game.h"

int main(int argc, char *argv[])
{
   Logger::get()->init(Logger::LVL_DEBUG);

    Sdl_Main theGame;

    int result = theGame.InitApp();
	
    if (result != 0)
    {
       theGame.ErrorMessage("Error during game initialization");
       theGame.Cleanup();
       Logger::get()->log_error("Error during game initalization");
       return result;
    }

    theGame.EventLoop();
    theGame.Cleanup();
    
    return 0;
}
