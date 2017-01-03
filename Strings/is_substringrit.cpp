#include<iostream>
#include<string>

using namespace std;

bool is_substring(string s1, string s2){

  string str = s1+s2;

  std::cout << str << std::endl;




return ;
}

int main(){

  string s1="waterbottle";
  string s2="erbottlewat";

if(is_substring(s1,s2)) std::cout << "yes" << std::endl;
else std::cout << "No" << std::endl;


  return 0;
}
