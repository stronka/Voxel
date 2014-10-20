
#include <cstdlib>
#include "config_level.h"
#include "logger.h"

void Level_Config::load(std::string label, std::string fname)
{
   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file( fname.c_str() );

   std::string text("Reading level: ");
   text.append(fname);
   Logger::get()->log_info(text);

   pugi::xml_node level = doc.child("level");

   background  = Sdl_Media::get()->load_image(level.attribute("background").value());
   Logger::get()->log_info("log back ok");
   //music.assign(level.attribute("music").value());
   //Logger::get()->log_info("log music ok");
   width       = atoi(level.attribute("width").value());
   Logger::get()->log_info("log width ok");
   height      = atoi(level.attribute("height").value());
   Logger::get()->log_info("log height ok");
   texel_size  = atoi(level.attribute("texel_size").value());
   Logger::get()->log_info("log texel ok");

   load_inner(level);

   text.assign("Reading level: ");
   text.append(fname);
   text.append(" done");
   Logger::get()->log_info(text);

   //Logger::get()->log_debug(background);
}

void Level_Config::load_inner(pugi::xml_node main)
{
   Logger::get()->log_debug("Reading level inner data");

   for (pugi::xml_node item = main.child("character"); item; item = item.next_sibling("character"))
   {
      Logger::get()->log_info("Found character");

      Character * ch = new Character();
      int startx, starty;

      ch->set_name(item.attribute("label").value());
      ch->set_sprite(item.attribute("sprite").value());

      startx = atoi(item.attribute("startx").value());
      starty = atoi(item.attribute("starty").value());
      ch->set_start(startx,starty);

      ch->set_input(item.attribute("input").value());

      characters.push_back(ch);
   }
}
std::list<Character*> Level_Config::get_characters()
{
   return characters;
}
GLuint Level_Config::get_background()
{
   return background;
}
