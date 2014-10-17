#include "pugixml.hpp"

void Level_Config::load(std::string label, std::string fname)
{
   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file( fname);

   Logger::get()->log_info("Reading level: ");
   Logger::get()->log_info(fname);

   pugi::xml_node level = doc.child("level");

   background  = level.attribute("background").value();
   music       = level.attribute("music").value();
   width       = level.attribute("width").value();
   height      = level.attribute("height").value();
   texel_size  = level.attribute("texel_size").value();
}
