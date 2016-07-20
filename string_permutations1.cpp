/*
Given two strings,
write a method to decide if one is a permutation of the other
NOTE: This code dose not work for repeated char
*/

#include <iostream>
#include <string>

using namespace std;


bool check_permutations(char* str1, char* str2){

    bool arr[256]={false};

    while(*str1){

      int val=*str1;
      arr[val]=true;
      str1++;
    }

    while(*str2){
      int val=*str2;
      if(arr[val]==true){str2++;}
      else{return false;}
      }

    return true;
}



int main(){

  char str1[]="tejas patil";
  char str2[]="patil";

  bool flag=check_permutations(str1,str2);

  if(flag){
    std::cout << "Stirngs are permutations of each other" << std::endl;
  }
  else{
    std::cout << "Stirngs are not permutations of each other" << std::endl;
  }
  return 0;
}
