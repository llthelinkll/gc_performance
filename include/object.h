#ifndef OBJECT_H
#define OBJECT_H

#include <unordered_map>
#include <map>
#include <vector>
#include <value.h>
#include <gc_cpp.h>
#include <gc/gc_allocator.h>

namespace gc_performance
{
  
  class object : public gc_cleanup
  {
  private:
    // map between string and value
    typedef std::unordered_map<std::string,value,std::hash<std::string> ,std::equal_to<std::string>,traceable_allocator<std::pair<std::string,value> > > ObjectMap;
    ObjectMap objectMap;
    
    // interfaces
    typedef std::vector<std::string> Interfaces;
    Interfaces interfaces;
    
    // parents
    typedef std::vector<std::string> Parents;
    Parents parents;
    
    // slot info
    typedef std::map<int, value> SlotInfo;
    SlotInfo slot_info;
    
    // slot value
    typedef std::map<int, value> SlotValue;
		std::map<int, value> slot_values;
    
		std::map<std::string, int> slot_name_to_index;
    
    // class name
    typedef std::string ClassName;
    ClassName classname;
    
    // super name
    typedef std::string SuperName;
    SuperName supername;
    
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
      typedef ObjectMap::iterator map_iterator;
      iterator(map_iterator itr) : _iterator(itr) { }
      self_type operator++() { self_type i = *this; _iterator++; return i; }
      self_type operator++(int junk) { _iterator++; return *this; }
      reference operator*() { return _iterator->second; }
      pointer operator->() { return &(_iterator->second); }
      bool operator==(const self_type& rhs) { return _iterator == rhs._iterator; }
      bool operator!=(const self_type& rhs) { return _iterator != rhs._iterator; }
      std::string _name(){ return  _iterator->first;}
      reference _value(){return _iterator->second;};
    private:
      map_iterator _iterator;
    };
    
    iterator* __itr;
    
    iterator begin()
    {
      return iterator(objectMap.begin());
    }
    
    iterator end()
    {
      return iterator(objectMap.end());
    }
    
    
  public:
    object();
    object(ObjectMap);
    
    value& operator[](const std::string&);
  };  
}
#endif