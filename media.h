/*
 * This is a class used for media loading
 *
 */

#ifndef __H_MEDIA_H_
#define __H_MEDIA_H_

#include <vector>
#include <string>

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"


class Sdl_Media;

class Sdl_Media
{
   std::vector<SDL_Surface *> is;
   std::vector<SDL_Texture *> ts;
   Mix_Music *music;
   std::vector<Mix_Chunk *> scratch;

   static Sdl_Media * me;

   public:
      void init();
      void cleanup();
      SDL_Texture * load_image(SDL_Renderer * renderer, std::string name);
      void load_music(std::string name);
      void load_chunk(std::string name);
      static Sdl_Media * get();
};


#endif
