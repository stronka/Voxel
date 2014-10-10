
#include <string.h>

#include <GL/gl.h>
#include "SDL.h"
#include "SDL_image.h"

#include "logger.h"
#include "media.h"

Sdl_Media * Sdl_Media::me = NULL;

void Sdl_Media::init()
{
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
      glDeleteTextures(1,&texture);
   }
*/
   delete me;
   me = NULL;
}
GLuint Sdl_Media::load_image(std::string name)
{
   std::string temp("Media: Loading image: ");
   temp.append(name.c_str() );
   Logger::get()->log_info(temp);

   GLuint texture;
   SDL_Surface* surface = IMG_Load(name.c_str() );
   glGenTextures(1,&texture);
   glBindTexture(GL_TEXTURE_2D,texture);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w,surface->h, 0, GL_RGB,GL_UNSIGNED_BYTE,surface->pixels);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   SDL_FreeSurface(surface);

   ts.push_back(texture);

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
