#include <value.h>
#include <iostream>

using namespace gc_performance;
using namespace std;

value::value() : type(UNDEFINED)
{
  // std::cout << "value()" << '\n';
}

#include <integer.h>
value::value(const int _i) : type(INTEGER)
{
  // 0.007 s
  _value._int = _i;
  
  // 0.059 s
  // _value._object = new integer(_i);
  
  
  // std::cout << "value(int _i)" << '\n';
}

value::value(const std::string& _str) : type(STRING)
{
  // should copy
  _value._str = new std::string(_str);
  
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

#include <array.h>
value& 
value::operator[](const value v)
{
  if (type == OBJECT && this->is<array>())
  {
    array* arr = this->as<array>();
    return (*arr)[v.getInteger()];
  }
  return value::undefined;
}

void 
value::operator=(const int other)
{
  type = INTEGER;
  _value._int = other;
}

void 
value::operator=(const std::string& other)
{
  type = STRING;
  _value._str = new std::string(other);
}

void 
value::operator=(const char* other)
{
  type = STRING;
  _value._str = new std::string(other);
}

void 
value::operator=(object* other)
{
  type = OBJECT;
  _value._object = other;
}

void 
value::operator=(const value& other)
{
  type = other.getType();
  switch (type) {
    case INTEGER:
      _value._int = other.getInteger();
      break;
    case STRING:
      _value._str = new std::string(other.getString());
      break;
    default:
      _value._object = other.getObject();
      break;
  }
}

value
value::undefined = 0;