#include <iostream>
#include <string>

using namespace std;


int main(){

  string str ="abcdefghijklmnopqrstuvwxyz";

  for(int i=str.length();i>1;i--){
    for(int j=0;j+i<=str.length();j++){
      std::cout << str.substr(j,i) << std::endl;
    }
  }

  return 0;

}
