/*
 * This class is used for logging information.
 * Like dmesg
 */

#ifndef __H_LOGGER_H
#define __H_LOGGER_H

#include <string>
#include <fstream>

class Logger;

class Logger
{
   private:
      std::ofstream stream;
      bool enabled;
      std::string name;
      static Logger * me;
      int level;

   public:
      void setEnabled(bool en);
      void init(int level);
      void log_error(std::string text);
      void log_info(std::string text);
      void log_debug(std::string text);
      void cleanup();

      static Logger * get();

      static const int LVL_DEBUG = 2;
      static const int LVL_INFO = 1;
      static const int LVL_ERROR = 0;
};

#endif
