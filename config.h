#ifndef __H_CONFIG_H_
#define __H_CONFIG_H_

class Config
{
   static Config * me;

   public:
      Config();
      static Config * get();
};

#endif
