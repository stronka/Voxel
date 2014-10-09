/*
 * This is a Scene management class
 *
 * Author: Piotr Zielinski
 */

#ifndef __H_SCENE__
#define __H_SCENE__

#include "game.h"

class Game_Scene
{
   private:
      int count;
      SDL_Texture * background;
      Sdl_Main * engine;
      int w;
      int h;
      SDL_Rect pos;
      bool done;

   public:
      void init(Sdl_Main * en, int width, int height);
      void draw();
      void cleanup();
      void key_down(int key);
};

#endif
