#include <iostream>
#include <string>

using namespace std;

int main(){

  string str="abcdefghijklmnopqrstuvwxyz";

  for(int i=1;i<str.length();i++ ){
    for(int j=0;j<str.length()-i;j++){
      std::cout << str.substr(j,i) << std::endl;
    }
  }


}
