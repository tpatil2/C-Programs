#include <iostream>

using namespace std;



void fib_seris(int n){


  int first = 0;
  int second  = 1;
  int next;

  for(int i=0;i<10;i++){

      if(i<=1){
        next=first+second;
        std::cout << next << '\n';
        first = second;
        second=next;
      }else{
        next=first+second;
        std::cout << next << '\n';
        first = second;
        second=next;
      }

    }
}


int main(){

  int n = 100;
  fib_seris(n);
  return 0;
}
