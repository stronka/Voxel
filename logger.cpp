

static Logger * Logger::me = NULL;

void Logger::setEnabled(bool en)
{
   enabled = en;
}

Logger Logger::get()
{
   if (me == NULL)
   {
      me = new Logger();
   }
   return me;
}
void Logger::init(int l)
{
   level = l;
   name = "voxel_log.txt";
   stream.open(name);
}

void Logger::log_info(std::string text)
{
   stream << text <<";INFO";
}
void Logger::log_debug(std::string text)
{
   stream << text <<";DEBUG";
}
void Logger::log_error(std::string text)
{
   stream << text <<";ERROR";
}

void Logger::cleanup()
{
   delete me;
   me = NULL;
   stream.close();
}
