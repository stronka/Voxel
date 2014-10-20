#include "character.h"

Character::Character()
{
   x = 0;
   y = 0;

   sx = 50;
   sy = 50;

   dirx=0;
   diry=0;
}
void Character::set_sprite(std::string name)
{
   sprite = Sdl_Media::get()->load_image(name);
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
void Character::set_name(std::string nam)
{
   name = nam;
}
void Character::set_start(int posx, int posy)
{
   x = 50*posx;
   y = 50*posy;
}
void Character::set_input(std::string i)
{
   input = i;
}
std::string Character::get_input()
{
   return input;
}
std::string Character::get_name()
{
   return name;
}
