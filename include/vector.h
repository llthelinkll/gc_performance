#ifndef VECTOR_H
#define VECTOR_H

#include <object.h>
#include <iostream>

namespace gc_performance
{
  template<class T>
  class vector : public object
  {
  private:
    typedef std::vector<T> Vector;
    Vector _vec;
  public:
   vector(Vector vec = {})
   {
     _vec = vec;
   }
   
   T& operator[](const int index)
   {
     if (index > _vec.size())
     {
       _vec.resize(index + 1);
     }
     return _vec[index];
   }
   
   T get()
   {
     dynamic_cast<T*>(_vec[0]);
     std::cout << "hello" << '\n';
     _vec[0];
   }
   
   
  };
  
  template<>
  int vector<int>::get()
  {
    std::cout << "int" << '\n';
    return 100;
  }
  
  template<>
  object* vector<object*>::get()
  {
    std::cout << "object" << '\n';
    return new object();
  }
}

#endif