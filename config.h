#ifndef __H_CONFIG_H_
#define __H_CONFIG_H_

#include <iostream>
#include <map>
#include "config_level.h"

class Config
{
   std::string MAIN_FILE;

   static Config * me;

   std::map<std::string,std::string> levels; //name, file
   int width;
   int height;

   void load_level(std::string label, std::string fname);

   public:
      Config();
      static Config * get();
      Level_Config * get_level(std::string);
      void read_setup(pugi::xml_node node);
      int get_width();
      int get_height();
};

#endif
