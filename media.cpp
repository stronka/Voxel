
#include <string.h>

#include "media.h"


void Sdl_Media::cleanup()
{
   for (item in sounds)
   {
      Mix_FreeChunk(item);
   }
   if (music != NULL)
      Mix_FreeMusic(music);

   for (item in ts)
   {
      SDL_DestroyTexture(item);
   }
   for (item in is)
   {
      SDL_FreeSurface(item);
   }
}
SDL_Texture * texture Sdl_Media::loadImage(SDL_Renderer * renderer, std::String name)
{
   //"media/image.jpg"
   is.push_back( IMG_Load(name) );
   ts.push_back( SDL_CreateTextureFromSurface(renderer,  image) );

   return ts.back;
}

void Sdl_Media::loadMusic(std::String name)
{
   music = Mix_LoadMUS(name);
}
void Sdl_Media::loadChunk(std::String name)
{
   sounds.push_back( Mix_LoadWAV(name) );
}
