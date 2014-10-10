
#include "config.h"


Config * Config::me = NULL;

Config::Config()
{
   pugi::xml_document doc;
   pugi::xml_parse_result result = doc.load_file("config/config.xml");
   doc.child("items")
   pugi::xml_node items = doc.child("items");

   for (pugi::xml_node item = items.child("item"); item; item = item.next_sibling("item"))
   {
      if (item.attribute("type").value() == "menu")
      {
      }
      if (item.attribute("type").value() == "video")
      {
      }
      if (item.attribute("type").value() == "level")
      {
      }
      if (item.attribute("type").value() == "flow")
      {
      }
   }
}
static Config * Config::get()
{
   if (me == NULL)
   {
      me = new Config();
   }
}
