/*
 *  main.cpp
 *
 */

#include <iostream>

#include "sdl_engine.h"
#include "game.h"
#include "logger.h"

int main(int argc, char *argv[])
{
   Logger::get()->init(Logger::LVL_DEBUG);

   Logger::get()->log_debug("main: start");

   Sdl_Main theGame;

   int result = theGame.InitApp();
	
   if (result != 0)
   {
      theGame.Cleanup();
      Logger::get()->log_error("Error during game initalization");
      Logger::get()->cleanup();
      return result;
   }

   Logger::get()->log_debug("main: reached events");

   theGame.EventLoop();
   theGame.Cleanup();

   Logger::get()->log_debug("main: closed");
   Logger::get()->cleanup();
   
   return 0;
}
