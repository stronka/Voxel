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
      GLfloat sx,sy; //size
      int dirx;
      int diry;
      std::string input;

      GLuint sprite;
      std::string name;

   public:
      Character();
      void draw();
      void go_left(bool on);
      void go_right(bool on);
      void go_up(bool on);
      void go_down(bool on);
      void update();
      void set_sprite(std::string name);
      void set_name(std::string name);
      void set_start(int pox, int posy);
      void set_input(std::string i);
      std::string get_input();
      std::string get_name();
};

#endif
