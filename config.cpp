
#include <iostream>

#include "pugixml.hpp"
#include "config.h"


Config * Config::me = 0;

Config::Config()
{
   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file("config/config.xml");
   //doc.child("items")
   pugi::xml_node items = doc.child("items");

   for (pugi::xml_node item = items.child("item"); item; item = item.next_sibling("item"))
   {
      if (strcmp(item.attribute("type").value(),"menu") == 0)
      {
         std::cout<<"Found menu"<<std::endl;
      }
      if (strcmp(item.attribute("type").value(),"video") == 0)
      {
         std::cout<<"Found video"<<std::endl;
      }
      if (strcmp(item.attribute("type").value(), "level") == 0)
      {
         std::cout<<"Found level"<<std::endl;
      }
      if (strcmp(item.attribute("type").value(), "flow") == 0)
      {
         std::cout<<"Found float"<<std::endl;
      }
   }
}
Config * Config::get()
{
   if (me == 0)
   {
      me = new Config();
   }
}
Level_Config * Config::get_level(std::string)
{
   return new Level_Config();
}
