/*
 * This is a Scene management class
 *
 * Author: Piotr Zielinski
 */

#ifndef __H_SCENE__
#define __H_SCENE__

#include <list>
#include "game.h"
#include "character.h"

class Game_Scene
{
   private:
      SDL_Rect pos;
      Sdl_Main * engine;
      SDL_Renderer * renderer;
      bool done;
      GLuint background;
      Character * jake;
      std::list<Character*> characters;
      Level_Config * level;

   public:
      int init();
      void Game_Scene(Sdl_Main * en);
      void draw();
      void cleanup();
      void key_down(int key);
      void key_up(int key);
      void update();
};

#endif
