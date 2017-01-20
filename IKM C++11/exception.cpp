#include <iostream>

using namespace std;


int main(){

  try{
    int father_age = 50;
    int daughter_age = 32;

    if((father_age - daughter_age) < 18){
        throw 99;
    }
  }catch(int x){
    if(x==99){
      std::cout << "ERROR::99 Age Conflict" << '\n';
    }
  }
  return 0;
}
