#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace gc_performance
{
  class object;
  
  class value {
  private:
    enum TYPE { 
      OBJECT
      ,INTEGER
      ,ARRAY
      ,DICTIONARY
      ,STRING
      ,UNDEFINED
     };
     
    // inside object
    union{
      object* _object;
      int _int;
      std::string* _str;
    } _value;
    
    // inside type
    TYPE type;
  public:
    
    // undefined
    value();
    // primitive
    value(int);
    value(std::string&);
    value(const char*);
    // object
    value(object*);
    
    // get object from external
    object* getObject() const {return _value._object;}
    int getInteger() const {return _value._int;}
    
    // operators
    bool operator==(const value &other) const;
  };
  
  
}

#include <unordered_map>

namespace std {

  template <>
  struct hash<gc_performance::value>
  {
    std::size_t operator()(const gc_performance::value& v) const
    {
      return hash<gc_performance::object*>()(v.getObject());
    }
  };

}

#endif