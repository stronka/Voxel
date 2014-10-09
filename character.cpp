#include "character.h"

Character::Character(int posx, int posy)
{
   x = posx;
   y = posy;

   sprite = Sdl_Media::get()->load_image("level1/media/char_jake.jpg");
}
void Character::display()
{
   SDL_Rect pos;
   pos.x = x;
   pos.y = y;
   pos.w = 20;
   pos.h = 20;

   SDL_RenderCopy(Sdl_Media::get()->get_renderer(), sprite, NULL, &pos);
}      
void Character::go_left()
{
   x -= 1.5;
}
void Character::go_right()
{
   x += 1.5;
}

void Character::go_up()
{
   y += 1.5;
}
void Character::go_down()
{
   y -= 1.5;
}
