#include <vector.h>
#include "SDL.h"

class Sdl_Media
{
   std::vector<SDL_Surface *> is;
   std::vector<SDL_Texture *> ts;
   Mix_Music *music;
   std::vector<Mix_Chunk *> scratch;

   public:
      void cleanup();
      SDL_Texture * loadImage(SDL_Renderer * renderer, std::String name);
      void loadMusic(std::String name);
};
