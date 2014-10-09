/*
 *  main.cpp
 *
 */

#include <iostream>
#include "game.h"
#include "sdl_engine.h"

int main(int argc, char *argv[])
{
   Logger::get()->init(Logger::LVL_DEBUG);

   Logger::get()->log_debug("main: start");

   Sdl_Main theGame;

   int result = theGame.InitApp();
	
   if (result != 0)
   {
      theGame.ErrorMessage("Error during game initialization");
      theGame.Cleanup();
      Logger::get()->log_error("Error during game initalization");
      return result;
   }

   Logger::get()->log_debug("main: reached events");

   theGame.EventLoop();
   theGame.Cleanup();

   Logger::get()->log_debug("main: closed");
   
   return 0;
}
