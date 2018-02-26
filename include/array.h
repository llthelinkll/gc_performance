#ifndef ARRAY_H
#define ARRAY_H

#include <object.h>

namespace gc_performance
{
  class value;
  
  class array : public object
  {
  private:
    typedef std::vector<value> Array;
    Array _array;
  public:
   array(Array arr);
  };
}

#endif