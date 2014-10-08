
#include <string.h>

#include "media.h"

SDL_Texture * texture Sdl_Media::loadImage(SDL_Renderer * renderer, std::String name)
{
   //"media/image.jpg"
   is.push_back( IMG_Load(name) );
   ts.push_back( SDL_CreateTextureFromSurface(renderer,  image) );

   return ts.back;
}
