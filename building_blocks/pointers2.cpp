#include <iostream>

using namespace std;

int main(){

char* a=(char*)"Tejas";


std::cout << "a   :"<<a << std::endl;
std::cout << "a+1 :"<<a+1 << std::endl;
std::cout << "*a+1  :"<<*(a+1) << std::endl;
std::cout << "&a  :"<<&a << std::endl;

a=(char*)"patil";

std::cout << "a   :"<<a << std::endl;
std::cout << "a+1 :"<<a+1 << std::endl;
std::cout << "*a  :"<<*a << std::endl;
std::cout << "&a  :"<<&a << std::endl;


//std::cout << "p :"<<p << std::endl;
//std::cout << "*p :"<<*p << std::endl;


  return 0;
}
