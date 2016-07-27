/*
remove wite spaces in sting
*/

#include <iostream>

using namespace std;


int main(){

    string str = "T   e  j  as    V a man r a o P   a    t      i  l  ";

    for(int i=0;i<str.length();i++){
      int k=0;
      if(str[i]=='\n' || str[i]=='\t' || str[i]==' ' ){
        str.erase(i,1);
        i--;
      }
    }

    std::cout << "Stirng is : "<< str << std::endl;

    return 0;

}
