/*
Given two strings,
write a method to decide if one is a permutation of the other
NOTE: This code dose works for repeated char but not case sensative
*/

#include <iostream>
#include <string>

using namespace std;


bool check_permutations(char* str1, char* str2){

  if(strlen(str1)!=strlen(str2)){
    return false;
  }

  if(0!=strcmp(str1,str2)){
    return false;
  }

    return true;
}



int main(){

  char str1[]="tejas vamanrao patil";
  char str2[]="patil tejas vamanrao";

  sort(str1,str1+strlen(str1));
  sort(str2,str2+strlen(str2));

  bool flag=check_permutations(str1,str2);

  if(flag){
    std::cout << "Stirngs are permutations of each other" << std::endl;
  }
  else{
    std::cout << "Stirngs are not permutations of each other" << std::endl;
  }
  return 0;
}
