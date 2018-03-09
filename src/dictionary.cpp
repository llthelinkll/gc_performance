#include <dictionary.h>
#include <iostream>

using namespace gc_performance;

dictionary::dictionary()
{
  // std::cout << "construct dictionary" << '\n';
}

value&
dictionary::operator[](const value& v)
{
  auto itr = dictionaryMap.find(v);
  if (itr != dictionaryMap.end())
  {
    return itr->second;
  }
  dictionaryMap[v] = 0;
  return dictionaryMap[v];
}