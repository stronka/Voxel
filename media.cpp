
#include <string.h>

#include "media.h"
#include "SDL.h"
#include "SDL_image.h"

Sdl_Media * Sdl_Media::me;

void Sdl_Media::init()
{
}

Sdl_Media * Sdl_Media::get()
{
   if (me == NULL)
   {
      me = new Sdl_Media();
   }
   return me;
}

void Sdl_Media::clean()
{
/*
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
*/
   delete me;
   me = NULL;
}
SDL_Texture * Sdl_Media::load_image(SDL_Renderer * renderer, std::string name)
{
   //"media/image.jpg"
   is.push_back( IMG_Load(name.c_str() ) );
   ts.push_back( SDL_CreateTextureFromSurface(renderer,  is.back() ) );

   return ts.back();
}

void Sdl_Media::load_music(std::string name)
{
   music = Mix_LoadMUS(name.c_str() );
}
void Sdl_Media::load_chunk(std::string name)
{
   //sounds.push_back( Mix_LoadWAV(name.c_str() ) );
}
