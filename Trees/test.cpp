#include <iostream>

using namespace std;

int main(){

  int a[]= {9,8,7,6,5,4,3,2,1};


  std::cout <<"0[a]      "<<0[a] << std::endl;
  std::cout <<"a[0]      "<<a[0]<< std::endl;
  std::cout <<"(1+3)[a]  "<<(1+1)[a]<< std::endl;
  std::cout <<"(a+5)[a]  "<<(a+5)[0]<< std::endl;


  return 0;
}
