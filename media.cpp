
#include <string.h>

#include "SDL.h"
#include "SDL_image.h"

#include "logger.h"
#include "media.h"

Sdl_Media * Sdl_Media::me = NULL;

void Sdl_Media::init(SDL_Renderer * r)
{
    renderer = r;

    /*
    //Initialize SDL_mixer 
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
    { 
       Logger::get()->log_error("Cannot open audio");
    }
    */
}

Sdl_Media * Sdl_Media::get()
{
   if (me == NULL)
   {
      me = new Sdl_Media();
   }
   return me;
}

void Sdl_Media::cleanup()
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
SDL_Texture * Sdl_Media::load_image(std::string name)
{
   std::string temp("Media: Loading image: ");
   temp.append(name.c_str() );
   Logger::get()->log_info(temp);

   is.push_back( IMG_Load(name.c_str() ) );
   ts.push_back( SDL_CreateTextureFromSurface(renderer,  is.back() ) );

   return ts.back();
}

void Sdl_Media::load_music(std::string name)
{
   std::string temp("Media: Loading music: ");
   temp.append(name.c_str() );
   Logger::get()->log_info(temp);

   music = Mix_LoadMUS(name.c_str() );
}
void Sdl_Media::load_chunk(std::string name)
{
   std::string temp("Media: Loading chunk: ");
   temp.append(name.c_str() );

   //sounds.push_back( Mix_LoadWAV(name.c_str() ) );
}
SDL_Renderer * Sdl_Media::get_renderer()
{
   return renderer;
}
