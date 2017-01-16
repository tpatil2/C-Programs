#include <iostream>

using namespace std;

//base class
class Mother{
private:
  int privateVar;
protected:
  int protectedVar;
public:
  int publicVar;
};

class Daughter:public Mother{
private:
protected:
public:
  void printNum();
};


void Daughter::printNum(){
  protectedVar=1;
  publicVar = 2;
  privateVar = 6;
}

int main(){

  Daughter d;
  d.printNum();

  return 0;
}
