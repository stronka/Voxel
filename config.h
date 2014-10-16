#ifndef __H_CONFIG_H_
#define __H_CONFIG_H_

#include "config_level.h"

class Config
{
   static Config * me;

   public:
      Config();
      static Config * get();
      Level_Config * get_level(std::string);
};

#endif
