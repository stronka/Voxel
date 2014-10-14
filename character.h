/**
*/
#ifndef __H_CHARACTER_H_
#define __H_CHARACTER_H_

#include "game.h"
#include "media.h"

class Character
{
   private:
      int x;
      int y;
      GLuint sprite;
      int dirx;
      int diry;

   public:
      Character(int posx, int posy);
      void display();
      void go_left(bool on);
      void go_right(bool on);
      void go_up(bool on);
      void go_down(bool on);
      void update();
};

#endif
