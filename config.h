#ifndef __H_CONFIG_H_
#define __H_CONFIG_H_

#include <iostream>
#include <map>
#include "config_level.h"

class Config
{
   static Config * me;

   std::string MAIN_FILE;

   std::map<std::string,Level_Config*> levels;

   void load_level(std::string label, std::string fname);

   public:
      Config();
      static Config * get();
      Level_Config * get_level(std::string);
};

#endif
