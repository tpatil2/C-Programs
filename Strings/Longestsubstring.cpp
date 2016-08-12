#include <iostream>
#include <string>

using namespace std;

bool Is_palindrome(string str){

  int i=0;
  size_t j=str.length()-1;

  while(i<j){
    if(str[i]==str[j]){
      i++;
      j--;
    }else return false;
    }

return true;
}


int main(){

  string str ="tejanitinPatil";

  for(int i=str.length();i>0;i--){
    for(int j=0;j+i<=str.length();j++){
      //std::cout << str.substr(j,i) << std::endl;
      if(Is_palindrome(str.substr(j,i))){
        std::cout << str.substr(j,i)<<" Is palindrome" << std::endl;
      }
    }
  }

  return 0;
}
