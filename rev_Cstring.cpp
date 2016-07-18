
/*
3Write code to reverse a C-Style String. (C-String means that “abcd” is
represented as five characters, including the null character.)
*/

#include <iostream>
#include <string>


using namespace std;

void rev_string(char* str){

    char* end = str;

    if(str){
      while(*end){
        ++end;
      }
      --end;//set to last char which is exactly befor NULL char
      }

      if(str < end){
        swap(*str,*end);
        str++;
        end--;
      }

      return;
}


void swap(char* start, char* end){

  char temp;
  temp=*start;
  *start=*end;
  *end=temp;

return;

}


int main(){

  char name[]="Tejas";

  rev_string(name);

  std::cout << "Reverse of C-string Tejas is :  "<< name << std::endl;

  return 0;
}
