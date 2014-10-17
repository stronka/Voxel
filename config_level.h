
#ifndef __H_LEVEL_CONFIG__H_
#define __H_LEVEL_CONFIG__H_

#include <iostream>
#include "character.h"
#include "item.h"

class Level_Config
{
   std::vector<Character> characters;
   std::vector<Game_Item> items;
   std::string background;
   std::string music;
   std::string width;
   std::string height;
   std::string texel_size;

   public:
      void load(std::string label, std::string fname);
};

#endif
