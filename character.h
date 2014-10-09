#ifndef __H_CHARACTER_H_
#define __H_CHARACTER_H_

#include "SDL.h"
#include "media.h"

class Character
{
   private:
      int x;
      int y;
      SDL_Texture * sprite;

   public:
      Character(int posx, int posy);
      void display();
      void go_left();
      void go_right();
      void go_up();
      void go_down();
};

#endif
