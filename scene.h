#include "SDL.h"

class Game_Scene
{
   private:
      int count;
      SDL_Texture * background;

   public:
      void init();
      void draw(SDL_Renderer * renderer);
};
