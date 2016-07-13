#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {

  int age;
  string input;
  std::cout << "Pease enter age" << std::endl;
  getline(cin,input);
  age=stoi(input);
  int large_number = (age > 5) ? age : 5 ;
  std::cout << "large_number  " << large_number<< std::endl;

  // arrays stoes multiple values of same datatypes
  // multidimentional arrat
  /*
        index      0       1      2       3
            0   [0][0]  [0][1]  [0][2]  [0][3]
            1   [][]     [][]    [][]     [][]
            2   [][]     [][]    [][]     [][]
            3   [][]     [][]    [][]     [][]
  */

  //random number

      int rand_num;

    do {
      rand_num = (rand() % 100) + 2;
    } while(rand_num !=101);

    std::cout << "random number is : "<<rand_num<< std::endl;

  return 0;
}
