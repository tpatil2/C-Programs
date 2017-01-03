#include <iostream>

using namespace std;

int main(){

  int a[]= {9,8,7,6,5,4,3,2,1};


  std::cout <<"0[a]      "<<0[a] << std::endl;//9
  std::cout <<"a[0]      "<<a[0]<< std::endl;//9
  std::cout <<"(1+3)[a]  "<<(1+3)[a]<< std::endl;//5
  std::cout <<"(a+5)[2]  "<<(a+5)[2]<< std::endl;//2
  std::cout <<"0[a+1]    "<<0[a+1] << std::endl;//8
  std::cout <<"(1+3)[a+1]"<<(1+3)[a+1]<< std::endl;//4

  return 0;
}
