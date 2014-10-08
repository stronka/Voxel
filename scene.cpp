
#include <iostream>
#include "scene.h"
#include "media.h"

void Game_Scene::init(SDL_Renderer * r, int width, int height)
{
   w = width;
   h = height;

   renderer = r;

   //SDL_Surface * image;
   background = Sdl_Media::get()->load_image(renderer, "media/image.jpg");

   pos.x = 0;
   pos.y = 0;
   pos.w = w;
   pos.h = h;
}
void Game_Scene::clean()
{
   Sdl_Media::get()->clean();
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
    }
}
