
#include <iostream>
#include "scene.h"
#include "media.h"

void Game_Scene::init(Sdl_Main * en, int width, int height)
{
   w = width;
   h = height;

   engine = en;

   background = Sdl_Media::get()->load_image(en.getRenderer(), "level1/media/image.jpg");

   pos.x = 0;
   pos.y = 0;
   pos.w = w;
   pos.h = h;
}
void Game_Scene::cleanup()
{
   Sdl_Media::get()->cleanup();
}
void Game_Scene::draw()
{
    SDL_RenderCopy(renderer, background, NULL, &pos);
}

void Game_Scene::key_down(int key)
{
    switch( key ){
        case SDLK_LEFT:
            pos.x -= 1.0;
            if (pos.x < 0.0)
               done=true;
            break;
        case SDLK_RIGHT:
            pos.x += 1.0;
            if (pos.x > 640.0)
               done=true;
            break;
        case SDLK_f:
            engine->toggle_fullscreen();;
            break;
        case SDLK_q:
            engine->close();
            break;
    }
}
