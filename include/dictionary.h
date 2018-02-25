#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <unordered_map>
#include <value.h>
#include <object.h>

namespace gc_performance
{
  class dictionary : public object
  {
  private:
    // map between value and value
    typedef std::unordered_map<value,value> DictionaryMap;
    DictionaryMap dictionaryMap;
  public:
    dictionary();
    
  };
}
#endif