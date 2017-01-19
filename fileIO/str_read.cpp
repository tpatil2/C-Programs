#include <iostream>
#include <fstream>

using namespace std;

int main(){

  ifstream ip;
  ip.open("out.txt");

  int id;
  string name;
  double Salary;

  if(!ip.is_open()){
    std::cout << "file does not exists:" << '\n';
  }
  ip>>id;
  ip>>name;
  ip>>Salary;
  while (ip.good()) {
    /* code */
    std::cout << id<<" "<<name<<" "<<Salary << '\n';
    ip>>id;
    ip>>name;
    ip>>Salary;
  }
}
