
#ifndef __H_GAME_ITEM__H_
#define __H_GAME_ITEM__H_

#include "game.h"
#include "media.h"

class Game_Item
{
      GLfloat x;
      GLfloat y;
      GLuint sprite;
      int dirx;
      int diry;
      GLfloat sx,sy;
   public:
      Game_Item(GLfloat posx,GLfloat posy);
      void draw();
      void update();
};

#endif
