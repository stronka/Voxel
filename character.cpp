#include "character.h"

Character::Character(int posx, int posy)
{
   x = posx;
   y = posy;

   dirx=0;
   diry=0;

   sprite = Sdl_Media::get()->load_image("media/level1/char_jake.jpg");
}
void Character::display()
{
   Sdl_Media::get()->draw(sprite,x,y,70.0,70.0);
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
      x += 4;
   if (dirx == -1)
      x -= 4;
   if (diry == 1)
      y += 4;
   if (diry == -1)
      y -= 4;
}
