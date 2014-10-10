#include "character.h"

Character::Character(int posx, int posy)
{
   x = posx;
   y = posy;

   sprite = Sdl_Media::get()->load_image("media/level1/char_jake.jpg");
}
void Character::display()
{
   glBindTexture(GL_TEXTURE_2D,sprite);

   glBegin(GL_TRIANGLES);
   glTexCoord2f(0.0f,0.0f);
   glVertex3f( 0.0f, 0.1f, 1.0f);
   glTexCoord2f(1.0f,0.0f);
   glVertex3f(-0.1f,-0.1f, 1.0f);
   glTexCoord2f(0.0f,1.0f);
   glVertex3f( 1.0f,-0.2f, 1.0f);
   glEnd();
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
