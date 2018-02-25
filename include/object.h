#ifndef OBJECT_H
#define OBJECT_H

#include <unordered_map>
#include <map>
#include <vector>
#include <value.h>

namespace gc_performance
{
  
  class object 
  {
  private:
    // map between string and value
    typedef std::unordered_map<std::string,value> ObjectMap;
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
    object();
    
  };  
}
#endif