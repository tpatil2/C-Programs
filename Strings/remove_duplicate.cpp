/*
Design an algorithm and write code to remove the duplicate characters
in a string without using any additional buffer. NOTE: One or two
additional variables are fine. An extra copy of the array is no
*/

#include <iostream>
#include <string>

using namespace std;


char *remove_duplicates(char *str)
{
	int i=1; int j=1;

  while(*(str+j)){
      if(*(str+j) != *(str+j-1)){
        *(str+i)=*(str+j);
        i++;
      }
      j++;
  }

  *(str+i)='\0';

  return str;

}


int main(){

  char name[]="heello";
  int n = strlen(name);

  sort(name,name+n);

  std::cout << "Sorted string is :"<< name << std::endl;
  char *opt=remove_duplicates(name);
  std::cout << "String after removing deplicate: "<< opt << std::endl;



  return 0;
}
