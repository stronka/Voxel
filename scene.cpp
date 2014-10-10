
#include <iostream>
#include "scene.h"
#include "sdl_engine.h"
#include "media.h"

//SDL_Texture * tex;

void Game_Scene::init(Sdl_Main * en, float width, float height)
{
   w = width;
   h = height;

   engine = en;

   background = Sdl_Media::get()->load_image("media/level1/background.jpg");

   jake = new Character(0,0);
}
void Game_Scene::cleanup()
{
   delete jake;
}
void Game_Scene::draw()
{
   glBindTexture(GL_TEXTURE_2D,background);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(  0.0f, 0.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(    w,  0.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(    w,  h,    -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(  0.0f, h,    -1.0f);
    glEnd();

   jake->display();
}

void Game_Scene::key_down(int key)
{
    switch( key ){
        case SDLK_LEFT:
            jake->go_left();
            break;
        case SDLK_RIGHT:
            jake->go_right();
            break;
        case SDLK_UP:
            jake->go_up();
            break;
        case SDLK_DOWN:
            jake->go_down();
            break;
        case SDLK_f:
            engine->toggle_fullscreen();;
            break;
        case SDLK_q:
            engine->close();
            break;
    }
}
