
#include <iostream>
#include <value.h>
#include <object.h>
#include <array.h> 
using namespace gc_performance;


int main(int argc, char const *argv[]) {
  array* v = new array();
  for(int i=0;i<100000;++i)
  {
    //  v = new object();
    (*v)[i] = 10;
    //  v = 10;
  }
  std::cout << "HelloWorld" << '\n';
  
  /* code */
  return 0;
}

void primitive_test()
{
  
}