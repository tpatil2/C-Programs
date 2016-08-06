#include <iostream>

using namespace std;
//1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , 89
int fibonacci(int n){
int sum=0;
  if(n<=1){
    return n;
  }
int f1=0;
int f2=1;

  for(int i=2;i<=n;i++){
    std::cout << sum << " " ;
    sum = f1 + f2;
     f1=f2;
     f2=sum;
  }

  return sum;
}

int main(){

int n;
std::cout << "Entet your number" << std::endl;
cin>>n;

int result = fibonacci(n);
std::cout << "result is : "<< result << std::endl;


  return 0;
}
