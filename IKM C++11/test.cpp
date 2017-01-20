#include <iostream>
#define GREETING = "Hello!"

using namespace std;

class A{
public:
  A(){
    std::cout << "A" << '\n';
  }
  ~A(){
    std::cout << "~A" << '\n';

  }
};

class B:public A{
public:
  B(){
    std::cout << "B" << '\n';
  }
  ~B(){
    std::cout << "~B" << '\n';

  }

};

class C:public B{
public:
  C(){
    std::cout << "C" << '\n';
  }
  ~C(){
    std::cout << "~C" << '\n';

  }
};



int main(){

  C obj;
  return 0;
}
