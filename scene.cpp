
#include <iostream.h>
#include "scene.h"

void Game_Scene::init(SDL_Renderer * renderer)
{
   std::cout << "nothing" << std::endl;

   //SDL_Surface * image;
   SDL_Rect pos;

   background = Sdl_Media.load_img(renderer, "media/image.jpg");

   pos.x = 0;
   pos.y = 0;
   pos.w = w;
   pos.h = h;
}
void Game_Scene::draw(SDL_Renderer * renderer)
{
    SDL_RenderCopy(renderer, background, NULL, &pos);
}

void Game_Scene::key_down(SDLK_KEY key)
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
