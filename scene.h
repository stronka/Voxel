
#include "SDL.h"

class Game_Scene
{
   private:
      int count;
      SDL_Texture * background;
      SDL_Renderer * renderer;
      int w;
      int h;
      SDL_Rect pos;
      bool done;

   public:
      void init(SDL_Renderer * renderer, int width, int height);
      void draw();
      void clean();
      void key_down(int key);
};
