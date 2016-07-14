#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {

  string name, surname = "Patil" ;

  std::cout << "Enter your name" << std::endl;
  getline(cin,name);

  std::cout << "Hello " << name <<std::endl;

  string fullname = name.assign(surname);
  std::cout << "full name is "<< fullname<< std::endl;

  fullname = "Tejas Vamanrao Patil";

  string fathersname = name.assign(fullname, 6, 20);
  std::cout << "fathersname name is "<< fathersname << std::endl;

  fullname.insert(0, "Rajshri ");
  std::cout << "fullname is : "<< fullname << std::endl;

  int index = fullname.find("V",0);
  std::cout << "your last name found at : "<< index << std::endl;

  fullname.erase(5,14);//delete 5 characters startig at index 12
  std::cout << "after ersing " << fullname<< std::endl;

  fullname.replace(5,3,"surname");//replce from index 5 to next 3 char with surmane
  std::cout << "changed surname "<< fullname << std::endl;


  return 0;
}
