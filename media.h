#include <vector.h>
#include "SDL.h"

class Sdl_Media
{
   std::vector<SDL_Surface *> is;
   std::vector<SDL_Texture *> ts;

   public:
      SDL_Texture * texture loadImage();
      //load song
};
