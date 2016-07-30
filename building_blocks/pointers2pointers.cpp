#include <iostream>

using namespace std;

int main(){

  int a=6;
  int *p1=&a;

  std::cout << "a   :"<<a << std::endl;
  std::cout << "&a  :"<<&a << std::endl;
  std::cout << "p1  :"<<p1 << std::endl;
  std::cout << "*p1 :"<<*p1 << std::endl;
  std::cout << "&p1 :"<<&p1 << std::endl;

  std::cout << "  " << std::endl;

  int** p2=&p1;
  std::cout << "p2 add of p1 :"<<p2 << std::endl;
  std::cout << "*p2 address of a :"<<*p2 << std::endl;
  std::cout << "**p2 val of a:"<<**p2 << std::endl;
  std::cout << "&p2 :"<<&p2 << std::endl;

  std::cout << "  " << std::endl;

  int*** p3=&p2;
  std::cout << "p3 add of p2 :"<<p3 << std::endl;
  std::cout << "*p3 add of p1 :"<<*p3 << std::endl;
  std::cout << "**p3 address of a:"<<**p3 << std::endl;
  std::cout << "***p3 val of a:"<<***p3 << std::endl;



  return 0;
}
