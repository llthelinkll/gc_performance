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
    value(const int);
    value(const std::string&);
    value(const char*);
    // object
    value(object*);
    
    // get object from external
    object* getObject() const {return _value._object;}
    int getInteger() const {return _value._int;}
    std::string getString() const {return *(_value._str);}
    TYPE getType() const { return type; }
    
    template<class T> bool is() const { return dynamic_cast<const T*>(_value._object); }
    template<class T> T* as() const { return dynamic_cast<T*>(_value._object); }
    
    // operators
    bool operator==(const value &other) const;
    
    void operator=(const value& other);
    void operator=(const int other);
    void operator=(const std::string&);
    void operator=(const char*);
    void operator=(object*);
    
    value& operator[](const value v);
    
    static value undefined;
    
    // cast operators
    operator std::string() const;
    operator const char*() const;
    operator int() const;
    operator double() const;
    operator unsigned int() const;
    
  };
  
  // literal
  value operator "" _as(long double);
  value operator "" _as(unsigned long long int);
  value operator "" _as(const char* v,std::size_t);
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