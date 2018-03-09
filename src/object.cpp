
#include <object.h>
#include <iostream>

using namespace gc_performance;

object::object()
{
  // std::cout << "construct object" << '\n';
}

object::object(ObjectMap map)
{
  objectMap = map;
}

value&
object::operator[](const std::string& str)
{
  auto itr = objectMap.find(str);
  if (itr != objectMap.end())
  {
    return itr->second;
  }
  objectMap[str] = 0;
  return objectMap[str];
}