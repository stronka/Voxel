
#include <iostream>

#include "pugixml.hpp"
#include "config.h"


Config * Config::me = 0;

Config::Config()
{
   MAIN_FILE="config/config.xml";

   std::string text = "Reading config file: ";
   text.append(MAIN_FILE);
   Logger::get()->log_info(text);

   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file(MAIN_FILE);
   pugi::xml_node items = doc.child("items");

   for (pugi::xml_node item = items.child("item"); item; item = item.next_sibling("item"))
   {
      if (strcmp(item.attribute("type").value(),"menu") == 0)
      {
         Logger::get()->log_info("Found menu");
      }
      if (strcmp(item.attribute("type").value(),"video") == 0)
      {
         Logger::get()->log_info("Found wideo");
      }
      if (strcmp(item.attribute("type").value(), "level") == 0)
      {
         Logger::get()->log_info("Found level");
         for (pugi::xml_node litem = item.child("inner"); litem; litem = item.next_sibling("inner"))
         {
            std::string fname = "config/";
            fname.append(litem.attribute("file").value());

            load_level(litem.attribute("label").value(), fname);
         }
      }
      if (strcmp(item.attribute("type").value(), "flow") == 0)
      {
         Logger::get()->log_info("Found flow");
      }
   }
}

void Config::load_level(std::string label, std::string fname)
{
   Level_Config * conf = new Level_Config();
   conf.load(label, fname);
   levels.insert( std::pair<std::string,Level_Config*>(label,conf));
}

Config * Config::get()
{
   if (me == 0)
   {
      me = new Config();
   }
}
Level_Config * Config::get_level(std::string lname)
{
   return levels[lname];
}
