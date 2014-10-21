
#include <iostream>

#include "pugixml.hpp"
#include "config.h"
#include "logger.h"


Config * Config::me = 0;

Config::Config()
{
   MAIN_FILE="config/config.xml";

   std::string text = "Reading config file: ";
   text.append(MAIN_FILE);
   Logger::get()->log_info(text);

   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file(MAIN_FILE.c_str() );
   pugi::xml_node items = doc.child("items");

   for (pugi::xml_node item = items.child("item"); item; item = item.next_sibling("item"))
   {
      if (strcmp(item.attribute("type").value(),"menu") == 0)
      {
         Logger::get()->log_debug("Found menu");
      }
      if (strcmp(item.attribute("type").value(),"video") == 0)
      {
         Logger::get()->log_debug("Found wideo");
      }
      if (strcmp(item.attribute("type").value(), "level") == 0)
      {
         Logger::get()->log_debug("Found level");

         read_levels();
      }
      if (strcmp(item.attribute("type").value(), "flow") == 0)
      {
         Logger::get()->log_debug("Found flow");
      }
      if (strcmp(item.attribute("type").value(), "setup") == 0)
      {
         Logger::get()->log_debug("Found setup");
         read_setup(item);
      }
   }
   Logger::get()->log_info("Loading configuration complete");
}
void Config::read_setup(pugi::xml_node node)
{
   for (pugi::xml_node litem = item.child("inner"); litem; litem = item.next_sibling("inner"))
   {
      if (strcmp(litem.attribute("type").value(), "width") == 0)
      {
         width = atoi(litem.value());
      }
      if (strcmp(litem.attribute("type").value(), "height") == 0)
      {
         height = atoi(litem.value());
      }
   }
}
void Config::read_levels(pugi::xml_node node)
{
   for (pugi::xml_node litem = item.child("inner"); litem; litem = item.next_sibling("inner"))
   {
      std::pair<std::string,std::string> thepair;
      
      thepair.first = litem.attribute("name");
      thepair.second = litem.attribute("file");

      levels.push_back(thepair);
   }
}
void Config::load_level(std::string label, std::string fname)
{
   Logger::get()->log_info("Loading level");
   Level_Config * conf = new Level_Config();
   conf->load(label, fname);
   levels.insert( std::pair<std::string,Level_Config*>(label,conf));
   Logger::get()->log_info("Loading level complete");
}

Config * Config::get()
{
   if (me == 0)
   {
      me = new Config();
   }
   return me;
}
Level_Config * Config::get_level(std::string lname)
{
   if (levels.size() == 0)
      return 0;

   return load_level(levels[lname]);
}
int Config::get_width()
{
   return width;
}
int Config::get_height()
{
   return height;
}
