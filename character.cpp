#include "character.h"

Character::Character(int posx, int posy)
{
   x = posx;
   y = posy;

   sprite = Sdl_Media::get()->load_image("media/level1/char_jake.jpg");
}
void Character::display()
{
   //
   glBindTexture(GL_TEXTURE_2D,sprite);

   glTranslatef(x,y,0);

   glBegin(GL_QUADS);
   glTexCoord2f(0.0f, 1.0f);
   glVertex3f(  0.0f, 0.0f, -1.0f);
   glTexCoord2f(1.0f, 1.0f);
   glVertex3f(    70, 0.0f, -1.0f);
   glTexCoord2f(1.0f, 0.0f);
   glVertex3f(    70,  70,    -1.0f);
   glTexCoord2f(0.0f, 0.0f);
   glVertex3f(  0.0f,  70,    -1.0f);
   glEnd();
}      
void Character::go_left()
{
   x -= 4;
}
void Character::go_right()
{
   x += 4;
}

void Character::go_up()
{
   y += 4;
}
void Character::go_down()
{
   y -= 4;
}
