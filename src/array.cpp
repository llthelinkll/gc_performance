#include <array.h>
#include <iostream>

using namespace gc_performance;
array::array(Array arr)
{
  _array = arr;
}

value& 
array::operator[](const int index)
{
  if (index > _array.size())
  {
    _array.resize(index + 1);
  }
  return _array[index];
}