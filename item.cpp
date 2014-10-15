#include "item.h"

Game_Item::Game_Item(GLfloat posx, GLfloat posy)
{
   x = posx;
   y = posy;

   sx = 50;
   sy = 50;

   dirx=0;
   diry=0;

   sprite = Sdl_Media::get()->load_image("media/level1/item1.png");
}
void Game_Item::draw()
{
   Sdl_Media::get()->draw(sprite,x,y,sx,sy);
}
