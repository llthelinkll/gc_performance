#include <value.h>
#include <iostream>

using namespace gc_performance;
using namespace std;

value::value() : type(UNDEFINED)
{
  // std::cout << "value()" << '\n';
}

#include <integer.h>
value::value(int _i) : type(INTEGER)
{
  // 0.007 s
  _value._int = _i;
  
  // 0.059 s
  // _value._object = new integer(_i);
  
  
  // std::cout << "value(int _i)" << '\n';
}

value::value(std::string& _str) : type(STRING)
{
  // should copy
  _value._str = &_str;
  
  // _value._object = new integer(_i);
  
  // std::cout << "value(string)" << '\n';
}

value::value(const char* _char) : type(STRING)
{
  _value._str = new std::string(_char);
  
  // _value._object = new integer(_i);
  
  // std::cout << "value(string)" << '\n';
}

value::value(object* __object) : type(OBJECT)
{
  _value._object = __object;
  // std::cout << "value(object)" << '\n';
}

#include <unordered_map>

bool 
value::operator==(const value &other) const
{
  return hash<gc_performance::object*>()(_value._object) == hash<gc_performance::object*>()(other.getObject());
}
