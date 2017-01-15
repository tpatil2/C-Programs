#include <iostream>

using namespace std;

void printNum(int x){
  std::cout << "Num is"<<x << '\n';
}

void printNum(float x){
  std::cout << "Num is"<<x << '\n';
}


int main(){

  int a = 44;
  float b = 4.44;

    printNum(a);
    printNum(b);

  return 0;
}
