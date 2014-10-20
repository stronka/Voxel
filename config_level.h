
#ifndef __H_LEVEL_CONFIG__H_
#define __H_LEVEL_CONFIG__H_

#include <iostream>
#include <list>

#include "pugixml.hpp"

#include "character.h"
#include "item.h"


class Level_Config
{
   std::list<Character*> characters;
   std::list<Game_Item*> items;
   GLuint background;
   std::string music;
   int width;
   int height;
   int texel_size;

   public:
      void load(std::string label, std::string fname);
      void load_inner(pugi::xml_node main);
      std::list<Character*> get_characters();
      GLuint get_background();
};

#endif
