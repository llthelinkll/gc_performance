#ifndef INTEGER_H
#define INTEGER_H

#include <object.h>

namespace gc_performance
{
  class integer : public object
  {
  private:
    int _i;
  public:
   integer(int);
  };
}

#endif