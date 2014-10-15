
#include <iostream>
#include "scene.h"
#include "sdl_engine.h"
#include "media.h"

//SDL_Texture * tex;

void Game_Scene::init(Sdl_Main * en, float width, float height)
{
   w = width;
   h = height;

   engine = en;

   Level_Config * level1 = Config::get()->get_level("level1");

   background = Sdl_Media::get()->load_image("media/level1/background.jpg");

   jake = new Character(200,200);
}
void Game_Scene::cleanup()
{
   delete jake;
}
void Game_Scene::draw()
{
   Sdl_Media::get()->draw(background,0.0,0.0,w,h);

   jake->draw();
}

void Game_Scene::key_down(int key)
{
    switch( key ){
        case SDLK_LEFT:
            jake->go_left(true);
            break;
        case SDLK_RIGHT:
            jake->go_right(true);
            break;
        case SDLK_UP:
            jake->go_up(true);
            break;
        case SDLK_DOWN:
            jake->go_down(true);
            break;
        case SDLK_f:
            engine->toggle_fullscreen();
            break;
        case SDLK_q:
            engine->close();
            break;
    }
}
void Game_Scene::key_up(int key)
{
    switch( key ){
        case SDLK_LEFT:
            jake->go_left(false);
            break;
        case SDLK_RIGHT:
            jake->go_right(false);
            break;
        case SDLK_UP:
            jake->go_up(false);
            break;
        case SDLK_DOWN:
            jake->go_down(false);
            break;
    }
}
void Game_Scene::update()
{
   jake->update();
}
