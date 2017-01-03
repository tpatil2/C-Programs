#include <iostream>

using namespace std;

long factorial(int n){

  long fact=0;

  if(n<=1){
    return 1;
  }

  fact = n * factorial(n-1);

  return fact;
}



int main(){
long n,m;
  std::cout << "Enter the Number" << std::endl;
  cin>> n;

 m = factorial(n);
  std::cout << "rec in main "<<m << std::endl;
  return 0;
}
