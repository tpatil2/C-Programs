#include <iostream>

using namespace std;

int fibonacci(int n){
  
  if(n<=1){
    return n;
  }
  return fibonacci(n-1)+fibonacci(n-2);
}

int main(){

int n;
std::cout << "Entet your number" << std::endl;
cin>>n;

int result = fibonacci(n);
std::cout << "result is : "<< result << std::endl;


  return 0;
}
