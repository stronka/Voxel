
#include <iostream>
#include "scene.h"
#include "sdl_engine.h"
#include "media.h"
#include "config.h"
#include "logger.h"

//SDL_Texture * tex;

int Game_Scene::init(Sdl_Main * en, float width, float height)
{
   w = width;
   h = height;

   engine = en;

   Level_Config * level1 = Config::get()->get_level("level1");
   if (level1 == 0)
   {
      Logger::get()->log_error("scene.cpp: No level data");
      return -1;
   }

   Logger::get()->log_info("scene.cpp: Attaching sprites & characters");

   background = level1->get_background();

   Logger::get()->log_info("scene.cpp: Attaching characters");

   characters = level1->get_characters();

   jake = NULL;

   Logger::get()->log_debug("scene.cpp: searching for main character");
   std::list<Character*>::iterator it;
   for(it=characters.begin(); it!=characters.end(); ++it)
   {
      std::cout<<"Name: "<<(*it)->get_name()<<std::endl;
      std::cout<<"input: "<<(*it)->get_input()<<std::endl;
      if ( (*it)->get_input().compare("keyboard")== 0)
      {
          jake = (*it);
      }
   }

   if (jake == NULL) {
      Logger::get()->log_error("Could not find main character");
      return -2;
   }
   else {
      Logger::get()->log_debug("found main character");
   }
   return 0;
}
void Game_Scene::cleanup()
{
   std::list<Character*>::iterator it;
   for(it=characters.begin(); it!=characters.end(); ++it)
   {
      delete (*it);
   }
}
void Game_Scene::draw()
{
   Sdl_Media::get()->draw(background,0.0,0.0,w,h);

   std::list<Character*>::iterator it;

   for(it=characters.begin(); it!=characters.end(); ++it)
   {
      (*it)->draw();
   }
}

void Game_Scene::key_down(int key)
{
    if (jake== NULL)
       return;

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
    if (jake== NULL)
       return;

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
   std::list<Character*>::iterator it;
   for(it=characters.begin(); it!=characters.end(); ++it)
   {
      (*it)->update();
   }
}
