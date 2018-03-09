#ifndef VALUE_H
#define VALUE_H

#include <string>

namespace gc_performance
{
  class object;
  
  class value {
  private:
    // inside object
    union{
      object* _object;
      int _int;
      std::string* _str;
    } _value;
    
  public:
    enum TYPE { 
      OBJECT
      ,INTEGER
      ,ARRAY
      ,DICTIONARY
      ,STRING
      ,UNDEFINED
     };
     
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
    
    /*
      hasher for unordered_map Value
    */
    class hasher
    {
    public:
      size_t operator() (value  v) const
      {
        switch (v.getType()) {
          case INTEGER:
            return std::hash<int>()(v.getInteger());
          case STRING:
            return std::hash<std::string>()(v.getString());
          default:
            return std::hash<object*>()(v.getObject());
        }
        return std::hash<object*>()(v.getObject());
      }
    };
    
    class EqualFn
    {
    public:
      bool operator() (const value t1, const value t2) const
      {
        switch (t1.getType()) {
          case INTEGER:
            return t1.getInteger() == t2.getInteger();
          case STRING:
            return t1.getString() == t2.getString();
          default:
            return t1.getObject() == t2.getObject();
        }
        return t1.getObject() == t2.getObject();
      }
    };
    
  };
  
  // literal
  value operator "" _as(long double);
  value operator "" _as(unsigned long long int);
  value operator "" _as(const char* v,std::size_t);
}


namespace std {

  template <>
  struct hash<gc_performance::value>
  {
    std::size_t operator()(const gc_performance::value& v) const
    {
      switch (v.getType()) {
        case gc_performance::value::INTEGER:
          return hash<int>()(v.getInteger());
        case gc_performance::value::STRING:
          return hash<std::string>()(v.getString());
        default:
          return hash<gc_performance::object*>()(v.getObject());
      }
      return hash<gc_performance::object*>()(v.getObject());
    }
  };
  
  template <>
  struct equal_to<gc_performance::value>
  {
    bool operator() (const gc_performance::value t1, const gc_performance::value t2) const
    {
      switch (t1.getType()) {
        case gc_performance::value::INTEGER:
          return t1.getInteger() == t2.getInteger();
        case gc_performance::value::STRING:
          return t1.getString() == t2.getString();
        default:
          return t1.getObject() == t2.getObject();
      }
      return t1.getObject() == t2.getObject();
    }
  };

}

#endif