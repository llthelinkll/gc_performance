#ifndef STRING_H
#define STRING_H

#include <object.h>

namespace gc_performance
{
  class string : public object
  {
  private:
    std::string _str;
  public:
   string(std::string);
  };
}

#endif