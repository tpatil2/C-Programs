#include <iostream>
#include <string>

using namespace std;



int main(){

    int A=9,B=33,C=11;

    int median;

    if ((A - B) * (C - B) <= 0) {
       median=B;
   } else if ((B - C) * (A - C) <= 0) {
       median=C;
   } else {
       median=A;
   }

    std::cout << "median is "<< median << std::endl;

  return 0;
}
