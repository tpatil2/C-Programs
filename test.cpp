#include <iostream>

using namespace std;

int main(){
  int x = 25;
  int y = 10;


  std::cout << "x" <<x<< std::endl;
  std::cout << "y" <<y<< std::endl;

  x=y^x; // 10^25 = 19
  y=y^x; // 10^(10^25) = 25
  x=x^y; // 10^(25^25 = 10

  std::cout << "x" <<x<< std::endl;
  std::cout << "y" <<y<< std::endl;


  return 0;
}
