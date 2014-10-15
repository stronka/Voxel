/**
*/
#ifndef __H_CHARACTER_H_
#define __H_CHARACTER_H_

#include "game.h"
#include "media.h"

class Character
{
   private:
      GLfloat x;
      GLfloat y;
      GLuint sprite;
      int dirx;
      int diry;
      GLfloat sx,sy;

   public:
      Character(GLfloat posx, GLfloat posy);
      void draw();
      void go_left(bool on);
      void go_right(bool on);
      void go_up(bool on);
      void go_down(bool on);
      void update();
};

#endif
