/*
Write a method to replace all spaces in a string with'%20'. You may assume
that the string has sufficient space at the end of the string to hold the
additional characters, and that you are given the "true" length of the
string.
*/

#include <iostream>
#include <string>
#include <cstring>



using namespace std;

void replace_spaces(char* str1, int length){

    int newlength, spaces=0;
    //calculate number of spaces
    for(int i=0;i<=length;i++){
      if(str1[i]==' '){
        spaces++;
      }
    }
    newlength=length+spaces*2;

    str1[newlength]='\0';
    std::cout << "newlength is: "<<newlength << std::endl;
    for(int i=length-1;i>=0;i--){
      if(str1[i]==' '){

        str1[newlength-1]='0';
        str1[newlength-2]='2';
        str1[newlength-3]='%';
        newlength=newlength-3;

      }
      else{
        str1[newlength-1]=str1[i];
        newlength=newlength-1;
    }

    }

  return;

}

int main(){

  char str1[]="Mr John Smith";

  int length = strlen(str1);

  replace_spaces(str1,length);

  std::cout << "Output is : "<<str1<< std::endl;


  return 0;
}
