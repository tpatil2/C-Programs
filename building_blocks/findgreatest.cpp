/*
Name Tejas Patil
https://github.com/tpatil2/C-Programs/blob/master/findgreatest.cpp
*/

#include <iostream>

using namespace std;

int main(){

    int n=223336226;
  //int n=14567890;

    string str = to_string(n);
    string  copy = str;
    string temp;

   int i=0;
   int largest=0;

   while(i < str.length()-1){

      if(str[i]==str[i+1]){
        temp = str;
        temp.erase(i,1);
          int x = stoi(temp);
          std::cout <<x << std::endl;

        if(largest < x) largest=x;
      }

      while(str[i]==str[i+1]) i++;
      if(str[i]!=str[i+1]) i++;
   }

   bool unique = false;
   for(int i=0;i<str.length()-1;i++){
     if(str[i]!=str[i+1]){
        unique = true;
     }else{
        unique = false;
        break;
      }
   }

   if(unique==true) largest = n;

   std::cout << "largest no is : "<< largest << std::endl;

  return 0;
}
