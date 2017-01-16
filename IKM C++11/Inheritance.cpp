#include <iostream>

using namespace std;

class Mother{
public:
  Mother(){};
  void Sayname();
};

void Mother::Sayname(){
  std::cout << "I am Mom" << '\n';
}

class Daughter:public Mother{

public:

};

int main(){

  Daughter d;
  d.Sayname();


  return 0;
}
