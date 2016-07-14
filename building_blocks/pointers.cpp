#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include <exception>

using namespace std;

void pass_ref(int* age){

  std::cout << "my age iside function is : "<< *age << std::endl;

  *age=20;
}

void num2_ref(int& number){

  std::cout << "my age iside num2 function is : "<< number << std::endl;
  number=100;
}
// *  value at :
// & address of :

int main(int argc, char const *argv[]) {

    int num = 26;
    int* pnum;
    pnum = &num;

    std::cout << "num is "<< num << std::endl;
    std::cout << "&num is "<< &num << std::endl;
    std::cout << "pnum is "<< pnum << std::endl;
    std::cout << "*pnum is "<< *pnum << std::endl;
    std::cout << "&pnum is "<< &pnum << std::endl;

    pass_ref(pnum);

    std::cout << "my age iside main function is  : "<< num << std::endl;


    int num2=11;
    int& anum=num2;

    std::cout << "num2 is :" <<num2<< std::endl;
    std::cout << "anum is :" <<anum<< std::endl;

    num2_ref(anum);

    std::cout << "num2 is after function change :" <<num2<< std::endl;
    std::cout << "anum is afetr function change :" <<anum<< std::endl;


  return 0;
}
