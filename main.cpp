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

   int Wwidth  = Config::get()->get_width();
   int Wheight = Config::get()->get_height();

   Sdl_Main theGameWindow(Wwidth, Wheight);
   Game_Scene scene;
   scene.load();
   theGameWindow.set_scene(&scene);

   int result = theGameWindow.createWindow(&scene);
	
   if (result != 0)
   {
      theGameWindow.Cleanup();
      Logger::get()->log_error("Error during game initalization");
      Logger::get()->cleanup();
      return result;
   }

   Logger::get()->log_debug("main: reached events");

   theGameWindow.EventLoop();
   theGameWindow.Cleanup();

   Logger::get()->log_debug("main: closed");
   Logger::get()->cleanup();
   
   return 0;
}
