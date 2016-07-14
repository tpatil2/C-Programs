#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <exception>

using namespace std;

int main(int argc, char const *argv[]) {

  int num = 0;

    try{
        if(num!=0){
          int div = 2/num;
        }else throw(num);

      }catch(int number){

      std::cout << "Numbe is not valid" << std::endl;

      }

  return 0;
}
