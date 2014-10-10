/*
 * This is a Scene management class
 *
 * Author: Piotr Zielinski
 */

#ifndef __H_SCENE__
#define __H_SCENE__

#include "game.h"
#include "character.h"

class Game_Scene
{
   private:
      SDL_Rect pos;
      Sdl_Main * engine;
      SDL_Renderer * renderer;
      float w;
      float h;
      bool done;
      GLuint texture;
      Character * jake;

   public:
      void init(Sdl_Main * en, float width, float height);
      void draw();
      void cleanup();
      void key_down(int key);
};

#endif
