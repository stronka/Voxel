#include "character.h"

Character::Character(GLfloat posx, GLfloat posy)
{
   x = posx;
   y = posy;

   sx = 50;
   sy = 50;

   dirx=0;
   diry=0;

   sprite = Sdl_Media::get()->load_image("media/level1/char_jake.jpg");
}
void Character::draw()
{
   Sdl_Media::get()->draw(sprite,x,y,sx,sy);
}
void Character::go_left(bool on)
{
   if (on)
      dirx = -1;
   else
      dirx = 0;
}
void Character::go_right(bool on)
{
   if (on)
      dirx = 1;
   else
      dirx = 0;
}

void Character::go_up(bool on)
{
   if (on)
      diry = 1;
   else
      diry = 0;
}
void Character::go_down(bool on)
{
   if (on)
      diry = -1;
   else
      diry = 0;
}
void Character::update()
{
   if (dirx == 1)
      x += 4.0f;
   if (dirx == -1)
      x -= 4.0f;
   if (diry == 1)
      y += 4.0f;
   if (diry == -1)
      y -= 4.0f;
}
