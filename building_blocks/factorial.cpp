#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

long int get_factorial(int number){

  long int factorial;
  if(number == 1) factorial=1;
  else factorial = get_factorial(number-1)*number;

  return factorial;

}

int main(int argc, char const *argv[]) {

    int num;
    std::cout << "enter your number" << std::endl;
    cin >>num;

    long int answer = get_factorial(num);

    std::cout << "Factorial of "<<num <<" is "<<answer << std::endl;

  return 0;
}
