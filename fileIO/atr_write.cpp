#include <iostream>
#include <fstream>

using namespace std;


int main(){

  ofstream op;
  op.open("out.txt");

  std::cout << "Please enter ID, name , Salary" << '\n';
  std::cout << "Please enter comand+z after entering" << '\n';

  int id;
  string name;
  double Salary;

  while(cin >> id >>name >> Salary){
    op << id << " " << name <<" "<<Salary<<endl;
  }

  return 0;
}
