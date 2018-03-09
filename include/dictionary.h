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
    typedef std::unordered_map<value,value,std::hash<value>,std::equal_to<value>,traceable_allocator<std::pair<value,value> > > DictionaryMap;
    DictionaryMap dictionaryMap;
    
  public:
    /*
      ITERATOR
    */
    class iterator
    {
    public:
      typedef iterator self_type;
      typedef value value_type;
      typedef value& reference;
      typedef value* pointer;
      typedef std::forward_iterator_tag iterator_category;
      typedef int difference_type;
      typedef DictionaryMap::iterator map_iterator;
      iterator(map_iterator itr) : _iterator(itr) { }
      self_type operator++() { self_type i = *this; _iterator++; return i; }
      self_type operator++(int junk) { _iterator++; return *this; }
      reference operator*() { return _iterator->second; }
      pointer operator->() { return &(_iterator->second); }
      bool operator==(const self_type& rhs) { return _iterator == rhs._iterator; }
      bool operator!=(const self_type& rhs) { return _iterator != rhs._iterator; }
      value_type _name(){ return  _iterator->first;}
      reference _value(){return _iterator->second;};
    private:
      map_iterator _iterator;
    };
    
    iterator* __itr;
    
    iterator begin()
    {
      return iterator(dictionaryMap.begin());
    }
    
    iterator end()
    {
      return iterator(dictionaryMap.end());
    }
    
  public:
    dictionary();
    
    value& operator[](const value&);
    
    size_t size(){
      return dictionaryMap.size();
    }
  };
}
#endif